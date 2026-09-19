import Link from "next/link";
import { notFound } from "next/navigation";
import { ecoKinBySlug, ecoKinRoster } from "@/data/ecoKin";

export function generateStaticParams() {
  return ecoKinRoster.map((entry) => ({ slug: entry.slug }));
}

export default async function EcoKinProfilePage({ params }: { params: Promise<{ slug: string }> }) {
  const { slug } = await params;
  const entry = ecoKinBySlug[slug];

  if (!entry) notFound();

  const statRows = [
    ["Vibrance", entry.stats?.vibrance],
    ["Density", entry.stats?.density],
    ["Harmony", entry.stats?.harmony],
    ["Purity", entry.stats?.purity],
  ] as const;

  return (
    <main className="min-h-screen bg-slate-950 text-white">
      <nav className="border-b border-white/10">
        <div className="mx-auto flex max-w-6xl items-center justify-between px-6 py-4">
          <Link href="/eco-kin" className="text-sm font-bold text-cyan-300 hover:text-cyan-200">
            ← Eco-Kin Data Grid
          </Link>
          <Link href="/" className="text-sm font-black tracking-[0.16em] text-white">
            ECHOHEARTS: REBEARTH
          </Link>
        </div>
      </nav>

      <article className="mx-auto max-w-6xl px-6 py-16">
        <header className="grid gap-8 lg:grid-cols-[1.25fr_.75fr] lg:items-end">
          <div>
            <div className="flex flex-wrap items-center gap-3 text-xs font-black uppercase tracking-[0.16em]">
              <span className="text-cyan-300">{entry.id}</span>
              <span className="rounded-full border border-white/10 bg-white/5 px-3 py-1 text-white/60">{entry.status}</span>
            </div>
            <h1 className="mt-5 text-6xl font-black tracking-[-0.05em] sm:text-7xl">{entry.name}</h1>
            <p className="mt-4 max-w-3xl text-lg leading-8 text-white/60">{entry.summary}</p>
          </div>
          <div className="rounded-3xl border border-white/10 bg-white/[0.03] p-6">
            <p className="text-xs font-black uppercase tracking-[0.16em] text-white/35">Availability</p>
            <p className="mt-2 font-bold text-white/85">{entry.availability}</p>
            <p className="mt-5 text-xs font-black uppercase tracking-[0.16em] text-white/35">Growth stage</p>
            <p className="mt-2 font-bold text-white/85">{entry.growthStage}</p>
          </div>
        </header>

        <div className="mt-12 grid gap-6 lg:grid-cols-2">
          <section className="rounded-3xl border border-white/10 bg-white/[0.03] p-7">
            <h2 className="text-2xl font-black">Biological profile</h2>
            <dl className="mt-6 space-y-5 text-sm">
              <ProfileRow label="Classification" value={entry.classification} />
              <ProfileRow label="Elements" value={entry.elements.join(" / ")} />
              <ProfileRow label="Habitats" value={entry.habitats.join(", ")} />
              <ProfileRow label="Role" value={entry.role} />
              <ProfileRow label="Stat focus" value={entry.statFocus.join(" / ")} />
            </dl>
          </section>

          <section className="rounded-3xl border border-white/10 bg-white/[0.03] p-7">
            <h2 className="text-2xl font-black">V/D/H/P profile</h2>
            <p className="mt-2 text-sm leading-6 text-white/45">
              Exact numbers stay hidden until balance values are approved. The public site must not invent stats.
            </p>
            <div className="mt-6 space-y-4">
              {statRows.map(([label, value]) => (
                <div key={label}>
                  <div className="mb-2 flex items-center justify-between text-sm">
                    <span className="font-bold text-white/75">{label}</span>
                    <span className="text-white/35">{value ?? "Pending balance"}</span>
                  </div>
                  <div className="h-2 overflow-hidden rounded-full bg-white/10">
                    <div className="h-full rounded-full bg-cyan-300/70" style={{ width: value ? `${Math.min(100, value)}%` : "0%" }} />
                  </div>
                </div>
              ))}
            </div>
          </section>
        </div>

        {entry.forms?.length ? (
          <section className="mt-6 rounded-3xl border border-white/10 bg-white/[0.03] p-7">
            <h2 className="text-2xl font-black">Growth path</h2>
            <div className="mt-5 flex flex-wrap items-center gap-3">
              {entry.forms.map((form, index) => (
                <div key={form} className="flex items-center gap-3">
                  <span className="rounded-xl border border-white/10 bg-black/20 px-4 py-3 text-sm font-bold text-white/80">{form}</span>
                  {index < entry.forms!.length - 1 ? <span className="text-white/25">→</span> : null}
                </div>
              ))}
            </div>
          </section>
        ) : null}
      </article>
    </main>
  );
}

function ProfileRow({ label, value }: { label: string; value: string }) {
  return (
    <div className="grid gap-1 border-b border-white/10 pb-4 sm:grid-cols-[9rem_1fr]">
      <dt className="font-semibold text-white/35">{label}</dt>
      <dd className="font-semibold text-white/80">{value}</dd>
    </div>
  );
}
