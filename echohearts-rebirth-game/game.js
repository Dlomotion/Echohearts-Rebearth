// EchoHearts Rebirth — Terraria-style rules, original code & art
// Rules adapted as generic mechanics: HP hearts (20 HP each), mana stars,
// contact damage + invincibility frames, knockback, crits, damage numbers,
// enemy drops, day/night spawns, and boss awaken / enrage phases.
(() => {
  const canvas = document.getElementById('game');
  const ctx = canvas.getContext('2d');
  const W = canvas.width, H = canvas.height;
  const $ = id => document.getElementById(id);
  const scoreEl=$('score'), heartsEl=$('hearts'), livesEl=$('lives'), levelEl=$('level'), bestEl=$('best');
  const overlay=$('overlay'), overlayTitle=$('overlayTitle'), overlayText=$('overlayText'), startBtn=$('startBtn');
  const bossBar=$('bossBar'), bossFill=$('bossFill');

  // --- Terraria-style weapon stats (shown like a tooltip) ---
  const WEAPON = { name:'Echo Pulse', damage:22, knockback:6, useTime:16, crit:10, manaCost:0 };
  const BURST  = { name:'Echo Burst', damage:55, knockback:9, useTime:38, crit:10, manaCost:30 };

  const state = {
    running:false, paused:false, frame:0, timeOfDay:0, // 0-3600, 0-1800 day, 1800-3600 night
    score:0, heartsCollected:0, level:1, kills:0,
    best: Number(localStorage.getItem('echohearts_best')||0),
    keys:{}, mouse:{x:W/2,y:H/2,down:false}, touch:null, lastShot:0, lastBurst:0,
  };
  bestEl.textContent = state.best;

  const player = {
    x:W/2, y:H/2, r:18, speed:3.6,
    hp:100, maxHp:100, mana:100, maxMana:100,
    defense:2, iframes:0, lastHitFrame:-999, facing:1, trail:[]
  };

  let hearts=[], pulses=[], enemies=[], orbs=[], drops=[], texts=[], particles=[];
  let boss=null;

  const rand=(a,b)=>a+Math.random()*(b-a);
  const dist=(a,b)=>Math.hypot(a.x-b.x,a.y-b.y);
  const isNight=()=> state.timeOfDay>=1800;
  const clamp=(v,a,b)=>Math.max(a,Math.min(b,v));

  function reset(){
    state.score=0; state.heartsCollected=0; state.level=1; state.kills=0; state.frame=0; state.timeOfDay=0;
    player.hp=player.maxHp; player.mana=player.maxMana; player.defense=2; player.x=W/2; player.y=H/2; player.trail=[]; player.iframes=0;
    hearts=[]; pulses=[]; enemies=[]; orbs=[]; drops=[]; texts=[]; particles=[]; boss=null;
    for(let i=0;i<5;i++) spawnHeart();
    bossBar.classList.add('hidden'); syncHud();
  }
  function syncHud(){
    scoreEl.textContent=state.score; heartsEl.textContent=state.heartsCollected;
    // Lives display = hearts of HP remaining in Terraria style (20 HP each)
    livesEl.textContent = `${Math.ceil(player.hp/20)} ❤ (${player.hp}/${player.maxHp} HP · ${Math.floor(player.mana)} mana)`;
    levelEl.textContent=state.level; bestEl.textContent=state.best;
    if(boss) bossFill.style.width = clamp(boss.hp/boss.maxHp*100,0,100)+'%';
  }
  function addText(x,y,str,color='#fff'){ texts.push({x,y,str,color,life:50}); }
  function burstFx(x,y,color,n=10){ for(let i=0;i<n;i++) particles.push({x,y,vx:rand(-3,3),vy:rand(-3,3),life:rand(15,30),color,r:rand(2,4)}); }

  function spawnHeart(){ hearts.push({x:rand(30,W-30),y:rand(30,H-30),r:13,pulse:rand(0,6)}); }

  // Enemy types — Terraria-style stats: HP, contact damage, knockback resist, defense
  function spawnImp(){ enemies.push({kind:'imp', emoji:'😈', x:rand(20,W-20), y:rand(20,H-20), r:16, hp:20, maxHp:20, damage:12, defense:0, kbResist:0.2, speed:rand(1.8,2.6), vx:rand(-2,2), vy:rand(-2,2), t:0, score:15}); }
  function spawnMonster(){ const s=isNight()?1.25:1; enemies.push({kind:'monster', emoji:'👾', x:rand(20,W-20), y:rand(40,H-40), r:22, hp:Math.round(60*s), maxHp:Math.round(60*s), damage:20, defense:2, kbResist:0.5, speed:1.45, vx:0, vy:0, t:0, score:25}); }
  function spawnBoss(){
    boss={kind:'boss', emoji:'👹', x:W/2, y:90, r:44, hp:600+(state.level*60), maxHp:600+(state.level*60), damage:35, defense:6, kbResist:0.95, speed:1.15, vx:1.2, vy:0, t:0, score:200, enraged:false};
    enemies.push(boss); bossBar.classList.remove('hidden');
    addText(W/2,120,'Heartbreaker has awoken!','#ff5a8a'); burstFx(boss.x,boss.y,'#ff3355',30);
  }
  function maybeDrop(e){
    const roll=Math.random();
    if(roll<0.25) drops.push({type:'heart', x:e.x, y:e.y, r:11});       // Terraria heart: heals 20 HP
    else if(roll<0.45) drops.push({type:'star', x:e.x, y:e.y, r:11});   // Terraria star: restores mana
  }

  function shoot(burst=false){
    const now=state.frame, w=burst?BURST:WEAPON;
    if(now-(burst?state.lastBurst:state.lastShot) < w.useTime) return;
    if(burst && player.mana < BURST.manaCost){ addText(player.x,player.y-28,'Not enough mana','#7ecbff'); return; }
    if(burst){ player.mana-=BURST.manaCost; state.lastBurst=now; } else state.lastShot=now;
    const a=Math.atan2(state.mouse.y-player.y, state.mouse.x-player.x);
    pulses.push({x:player.x, y:player.y, vx:Math.cos(a)*(burst?8:10), vy:Math.sin(a)*(burst?8:10), r:burst?10:6, damage:w.damage, knockback:w.knockback, crit:Math.random()*100 < w.crit, burst});
  }

  function damagePlayer(raw){
    if(player.iframes>0 || !state.running) return;
    const dmg=Math.max(1, raw - player.defense);
    player.hp-=dmg; player.iframes=40; player.lastHitFrame=state.frame; // ~0.66s i-frames like Terraria
    addText(player.x,player.y-30,'-'+dmg,'#ff6b6b'); burstFx(player.x,player.y,'#ff3355',12); syncHud();
    if(player.hp<=0) gameOver();
  }
  function damageEnemy(e, pulse){
    let dmg=Math.max(1, pulse.damage - e.defense); if(pulse.crit) dmg*=2;
    e.hp-=dmg;
    // Knockback
    const a=Math.atan2(pulse.vy,pulse.vx), kb=pulse.knockback*(1-e.kbResist)*0.6;
    e.x+=Math.cos(a)*kb*4; e.y+=Math.sin(a)*kb*4;
    addText(e.x, e.y-e.r-8, String(Math.round(dmg))+(pulse.crit?'!':''), pulse.crit?'#ffd93d':'#fff');
    burstFx(e.x,e.y, e.kind==='boss'?'#ff8a5a':'#c77dff', pulse.burst?14:6);
    if(e.hp<=0) killEnemy(e);
  }
  function killEnemy(e){
    e.dead=true; state.kills++; state.score+=e.score; maybeDrop(e); burstFx(e.x,e.y,'#ffd93d',18);
    if(e.kind==='boss'){
      boss=null; bossBar.classList.add('hidden'); state.score+=100;
      player.maxHp=Math.min(200, player.maxHp+20); player.hp=Math.min(player.maxHp, player.hp+40); player.defense+=1;
      addText(player.x,player.y-44,'REBIRTH! +20 Max HP, +1 Defense','#7CFC9A');
      state.level++; spawnHeart(); spawnHeart();
    }
    syncHud();
  }

  function levelCheck(){
    const targetLevel = Math.floor(state.heartsCollected/5)+1;
    if(targetLevel>state.level){ state.level=targetLevel; addText(player.x,player.y-40,'Level '+state.level+'!','#ffd93d'); }
    if(state.level%3===0 && !boss && !enemies.some(e=>e.kind==='boss') && state.heartsCollected>0 && state.frame%600===0){
      // Boss check once per window — spawn at start of a boss level
      if(!state['bossSpawnedFor'+state.level]){ state['bossSpawnedFor'+state.level]=true; spawnBoss(); }
    }
    syncHud();
  }

  function update(){
    if(!state.running || state.paused) return;
    state.frame++; state.timeOfDay=(state.timeOfDay+1)%3600;
    // Mana regen (Terraria-style: faster when standing still)
    const moving = state.keys['arrowup']||state.keys['w']||state.keys['arrowdown']||state.keys['s']||state.keys['arrowleft']||state.keys['a']||state.keys['arrowright']||state.keys['d'];
    player.mana=clamp(player.mana + (moving?0.25:0.6), 0, player.maxMana);
    // HP regen: only after 5s without being hit, slow
    if(state.frame-player.lastHitFrame>300) player.hp=clamp(player.hp+0.05,0,player.maxHp);
    if(player.iframes>0) player.iframes--;

    // Movement
    let dx=0,dy=0;
    if(state.keys['arrowup']||state.keys['w']) dy-=1;
    if(state.keys['arrowdown']||state.keys['s']) dy+=1;
    if(state.keys['arrowleft']||state.keys['a']) dx-=1;
    if(state.keys['arrowright']||state.keys['d']) dx+=1;
    if(state.touch){ dx+=state.touch.x-player.x>4?1:state.touch.x-player.x<-4?-1:0; dy+=state.touch.y-player.y>4?1:state.touch.y-player.y<-4?-1:0; }
    const len=Math.hypot(dx,dy)||1; player.x=clamp(player.x+dx/len*player.speed,player.r,W-player.r); player.y=clamp(player.y+dy/len*player.speed,player.r,H-player.r);
    if(dx) player.facing=Math.sign(dx);
    player.trail.push({x:player.x,y:player.y}); if(player.trail.length>22) player.trail.shift();

    if(state.keys[' ']||state.mouse.down) shoot(false);

    // Spawning — night spawns more / stronger (Terraria day/night rule)
    const spawnRate = isNight()? 140 : 260;
    if(state.frame%spawnRate===0) (Math.random()<0.5?spawnImp:spawnMonster)();
    if(hearts.length<4 && Math.random()<0.01) spawnHeart();

    // Hearts collect
    hearts=hearts.filter(h=>{ if(dist(player,h)<player.r+h.r){ state.heartsCollected++; state.score+=10; player.hp=clamp(player.hp+5,0,player.maxHp); burstFx(h.x,h.y,'#ffd93d',8); spawnHeart(); levelCheck(); syncHud(); return false;} return true; });
    // Drops
    drops=drops.filter(d=>{ if(dist(player,d)<player.r+d.r){ if(d.type==='heart'){player.hp=clamp(player.hp+20,0,player.maxHp); addText(player.x,player.y-26,'+20 HP','#ff8fab');} else {player.mana=clamp(player.mana+50,0,player.maxMana); addText(player.x,player.y-26,'+50 Mana','#7ecbff');} syncHud(); return false;} return true; });
    // Pulses
    pulses=pulses.filter(p=>{ p.x+=p.vx; p.y+=p.vy; if(p.x<0||p.x>W||p.y<0||p.y>H) return false;
      for(const e of enemies){ if(dist(p,e)<p.r+e.r){ damageEnemy(e,p); return false; } } return true; });
    // Enemies
    for(const e of enemies){
      e.t++;
      if(e.kind==='imp'){ if(e.t%45===0){e.vx=rand(-2.6,2.6); e.vy=rand(-2.6,2.6);} e.x+=e.vx; e.y+=e.vy; if(e.x<e.r||e.x>W-e.r) e.vx*=-1; if(e.y<e.r||e.y>H-e.r) e.vy*=-1; }
      else if(e.kind==='monster'){ const a=Math.atan2(player.y-e.y,player.x-e.x); e.x+=Math.cos(a)*e.speed; e.y+=Math.sin(a)*e.speed; }
      else if(e.kind==='boss'){
        if(!e.enraged && e.hp < e.maxHp*0.25){ e.enraged=true; e.speed=2; addText(e.x,e.y-60,'ENRAGED!','#ff3355'); }
        const a=Math.atan2(player.y-e.y,player.x-e.x); const sp=e.enraged?e.speed*1.4:e.speed;
        e.x+=Math.cos(a)*sp; e.y+=Math.sin(a)*sp;
        if(e.t% (e.enraged?55:90)===0) orbs.push({x:e.x,y:e.y,vx:Math.cos(a)*3.2,vy:Math.sin(a)*3.2,r:9,damage:15});
        if(e.t%420===0) spawnImp();
        bossFill.style.width=clamp(e.hp/e.maxHp*100,0,100)+'%';
      }
      if(dist(player,e)<player.r+e.r-4) damagePlayer(e.damage);
    }
    enemies=enemies.filter(e=>!e.dead);
    // Orbs / shards
    orbs=orbs.filter(o=>{ o.x+=o.vx; o.y+=o.vy; if(dist(player,o)<player.r+o.r){ damagePlayer(o.damage); return false;} return o.x>0&&o.x<W&&o.y>0&&o.y<H; });
    particles=particles.filter(p=>{p.x+=p.vx;p.y+=p.vy;p.life--;return p.life>0;});
    texts=texts.filter(t=>{t.y-=0.7;t.life--;return t.life>0;});
    syncHud();
  }

  function drawHeart(x,y,s,color){ ctx.save(); ctx.translate(x,y); ctx.scale(s,s); ctx.beginPath(); ctx.moveTo(0,10); ctx.bezierCurveTo(-14,-4,-6,-16,0,-7); ctx.bezierCurveTo(6,-16,14,-4,0,10); ctx.fillStyle=color; ctx.fill(); ctx.restore(); }
  function draw(){
    ctx.clearRect(0,0,W,H);
    // Day / night tint
    if(isNight()){ ctx.fillStyle='rgba(5,5,30,0.35)'; ctx.fillRect(0,0,W,H); }
    ctx.fillStyle='#ffffffcc'; ctx.font='13px system-ui';
    ctx.fillText(isNight()?'🌙 Night — monsters are stronger & more frequent':'☀️ Day', 14, 22);
    ctx.fillText(`${WEAPON.name}: ${WEAPON.damage} dmg · ${WEAPON.crit}% crit · E = ${BURST.name} (${BURST.manaCost} mana)`, 14, H-14);
    // Trail (echo)
    player.trail.forEach((p,i)=> drawHeart(p.x,p.y,0.5+i/player.trail.length*0.5,'rgba(255,90,138,0.18)'));
    hearts.forEach(h=> drawHeart(h.x,h.y+Math.sin(state.frame/20+h.pulse)*3,1.1,'#ffd93d'));
    drops.forEach(d=> d.type==='heart'?drawHeart(d.x,d.y,0.9,'#ff5a8a'):(ctx.fillStyle='#7ecbff',ctx.font='20px serif',ctx.fillText('★',d.x-7,d.y+7)));
    pulses.forEach(p=>{ ctx.beginPath(); ctx.arc(p.x,p.y,p.r,0,7); ctx.fillStyle=p.burst?'#ffd93d':'#7ecbff'; ctx.fill(); });
    orbs.forEach(o=>{ ctx.beginPath(); ctx.arc(o.x,o.y,o.r,0,7); ctx.fillStyle='#b388ff'; ctx.fill(); });
    enemies.forEach(e=>{ ctx.font=`${e.r*1.7}px serif`; ctx.textAlign='center'; ctx.fillText(e.emoji,e.x,e.y+e.r*0.6); ctx.textAlign='left';
      if(e.maxHp>20){ ctx.fillStyle='#0008'; ctx.fillRect(e.x-e.r,e.y-e.r-12,e.r*2,5); ctx.fillStyle='#ff5a8a'; ctx.fillRect(e.x-e.r,e.y-e.r-12,e.r*2*clamp(e.hp/e.maxHp,0,1),5);} });
    // Player — blink during i-frames (Terraria rule)
    if(!(player.iframes>0 && Math.floor(state.frame/4)%2===0)) drawHeart(player.x,player.y,1.6,'#ff5a8a');
    particles.forEach(p=>{ ctx.globalAlpha=p.life/25; ctx.fillStyle=p.color; ctx.fillRect(p.x,p.y,p.r,p.r); ctx.globalAlpha=1; });
    texts.forEach(t=>{ ctx.globalAlpha=clamp(t.life/30,0,1); ctx.fillStyle=t.color; ctx.font='bold 15px system-ui'; ctx.fillText(t.str,t.x-14,t.y); ctx.globalAlpha=1; });
  }
  function loop(){ update(); draw(); requestAnimationFrame(loop); }

  function start(){ reset(); state.running=true; state.paused=false; overlay.classList.add('hidden'); }
  function gameOver(){
    state.running=false; state.best=Math.max(state.best,state.score); localStorage.setItem('echohearts_best',state.best);
    overlayTitle.textContent='You were slain…';
    overlayText.innerHTML=`Score <b>${state.score}</b> · Hearts <b>${state.heartsCollected}</b> · Defeated <b>${state.kills}</b> · Level <b>${state.level}</b><br/>Terraria rule: on rebirth you keep your Best score — try again and beat the boss!`;
    startBtn.textContent='Rebirth — Play Again'; overlay.classList.remove('hidden'); syncHud();
  }

  window.addEventListener('keydown',e=>{ state.keys[e.key.toLowerCase()]=true; if(e.key===' '){e.preventDefault();} if(e.key.toLowerCase()==='e') shoot(true); if(e.key.toLowerCase()==='p') state.paused=!state.paused; });
  window.addEventListener('keyup',e=> state.keys[e.key.toLowerCase()]=false);
  canvas.addEventListener('mousemove',e=>{ const r=canvas.getBoundingClientRect(); state.mouse.x=(e.clientX-r.left)*W/r.width; state.mouse.y=(e.clientY-r.top)*H/r.height; });
  canvas.addEventListener('mousedown',()=> state.mouse.down=true); window.addEventListener('mouseup',()=> state.mouse.down=false);
  canvas.addEventListener('touchmove',e=>{ const r=canvas.getBoundingClientRect(),t=e.touches[0]; state.touch={x:(t.clientX-r.left)*W/r.width,y:(t.clientY-r.top)*H/r.height}; e.preventDefault(); },{passive:false});
  canvas.addEventListener('touchend',()=> state.touch=null);
  startBtn.addEventListener('click',start);
  $('restartBtn').addEventListener('click',start);
  $('pauseBtn').addEventListener('click',()=> state.paused=!state.paused);
  $('shootBtn').addEventListener('click',()=> shoot(false));

  draw(); loop();
})();
