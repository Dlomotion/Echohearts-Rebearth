import Link from "next/link";
import { ecoKinRoster } from "@/data/ecoKin";
import { EcoKinCard } from "@/components/EcoKinCard";

export default function Home() {
  const featured = ecoKinRoster.slice(0, 3);

  return (
    <main className="min-h-screen overflow-x-hidden bg-slate-950 text-white">
      <nav className="sticky top-0 z-50 border-b border-white/10 bg-slate-950/85 backdrop-blur-xl">
        <div className="mx-auto flex max-w-7xl items-center justify-between px-6 py-4">
          <Link href="/" className="text-sm font-black tracking-[0.18em] text-white">
            ECHOHEARTS: <span className="text-cyan-300">REBEARTH</span>
          </Link>
          <div className="flex items-center gap-3 text-sm font-semibold text-white/65">
            <Link className="rounded-lg px-3 py-2 hover:bg-white/5 hover:text-white" href="/eco-kin">
              Eco-Kin
            </Link>
            <a className="hidden rounded-lg px-3 py-2 hover:bg-white/5 hover:text-white md:inline-flex" href="#pillars">
              Game pillars
            </a>
          </div>
        </div>
      </nav>

      <header className="relative mx-auto flex min-h-[72vh] max-w-7xl items-center px-6 py-20">
        <div className="absolute inset-0 -z-10 bg-[radial-gradient(circle_at_30%_25%,rgba(34,211,238,.16),transparent_25%),radial-gradient(circle_at_75%_20%,rgba(99,102,241,.12),transparent_25%)]" />
        <div className="max-w-4xl">
          <p className="text-xs font-black uppercase tracking-[0.24em] text-cyan-300">Open-world creature-bonding survival-restoration RPG</p>
          <h1 className="mt-5 text-5xl font-black tracking-[-0.05em] text-white sm:text-7xl lg:text-8xl">
            A living world should remember how you treated it.
          </h1>
          <p className="mt-6 max-w-2xl text-lg leading-8 text-white/60">
            Explore Rebearth, earn the trust of autonomous Eco-Kin, rebuild Sanctuary communities, and restore ecosystems scarred by the Blight. Your choices change the land, the people, and the creatures who live there.
          </p>
          <div className="mt-9 flex flex-col gap-3 sm:flex-row">
            <Link
              href="/eco-kin"
              className="inline-flex min-h-12 items-center justify-center rounded-xl bg-cyan-300 px-6 font-black text-slate-950 transition hover:bg-cyan-200 focus-visible:outline focus-visible:outline-2 focus-visible:outline-offset-2 focus-visible:outline-cyan-300"
            >
              Explore the EcoDex
            </Link>
            <a
              href="#pillars"
              className="inline-flex min-h-12 items-center justify-center rounded-xl border border-white/15 px-6 font-bold text-white/80 transition hover:bg-white/5 hover:text-white"
            >
              See the game pillars
            </a>
          </div>
        </div>
      </header>

      <section id="pillars" className="mx-auto max-w-7xl px-6 py-20">
        <div className="grid gap-4 lg:grid-cols-3">
          {[
            ["This world needs me.", "Restoration is visible. Regions recover, routes reopen, homes return, and the world reacts to what the player actually does."],
            ["These Eco-Kin are alive.", "Eco-Kin can flee, warn, defend, observe, remember, refuse, approach, and bond by choice rather than functioning like inventory."],
            ["My choices changed Rebearth.", "Story decisions, rescue outcomes, faction pressure, Sanctuary growth, and ecological repair persist across the campaign."],
          ].map(([title, copy]) => (
            <article key={title} className="rounded-3xl border border-white/10 bg-white/[0.03] p-7">
              <p className="text-2xl font-black text-white">{title}</p>
              <p className="mt-3 leading-7 text-white/55">{copy}</p>
            </article>
          ))}
        </div>
      </section>

      <section className="mx-auto max-w-7xl px-6 pb-24">
        <div className="mb-6 flex items-end justify-between gap-4">
          <div>
            <p className="text-xs font-black uppercase tracking-[0.2em] text-cyan-300">Featured roster</p>
            <h2 className="mt-2 text-4xl font-black tracking-tight">Meet the Eco-Kin</h2>
          </div>
          <Link href="/eco-kin" className="text-sm font-bold text-cyan-300 hover:text-cyan-200">
            View full index →
          </Link>
        </div>
        <div className="grid gap-5 md:grid-cols-2 xl:grid-cols-3">
          {featured.map((entry) => (
            <EcoKinCard key={entry.id} entry={entry} />
          ))}
        </div>
      </section>
    </main>
  );
}
