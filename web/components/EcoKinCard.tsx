import Link from "next/link";
import type { EcoKinEntry } from "@/types/ecoKin";

const statusStyles: Record<EcoKinEntry["status"], string> = {
  CANON: "border-emerald-400/30 bg-emerald-400/10 text-emerald-200",
  "APPROVED-PENDING": "border-amber-400/30 bg-amber-400/10 text-amber-200",
  "IN DEVELOPMENT": "border-indigo-400/30 bg-indigo-400/10 text-indigo-200",
};

export function EcoKinCard({ entry }: { entry: EcoKinEntry }) {
  return (
    <article className="group overflow-hidden rounded-3xl border border-white/10 bg-white/[0.035] shadow-2xl shadow-black/20 transition duration-300 hover:-translate-y-1 hover:border-cyan-300/30 motion-reduce:transform-none">
      <div className="relative min-h-48 overflow-hidden border-b border-white/10 bg-[radial-gradient(circle_at_top,rgba(34,211,238,.24),transparent_45%),linear-gradient(145deg,#101827,#05070b_68%)] p-6">
        <div className="absolute inset-0 opacity-30 [background-image:linear-gradient(rgba(255,255,255,.04)_1px,transparent_1px),linear-gradient(90deg,rgba(255,255,255,.04)_1px,transparent_1px)] [background-size:24px_24px]" />
        <div className="relative flex h-full min-h-36 flex-col justify-between">
          <div className="flex items-start justify-between gap-4">
            <span className="text-xs font-bold tracking-[0.18em] text-cyan-200/80">{entry.id}</span>
            <span className={`rounded-full border px-2.5 py-1 text-[10px] font-black tracking-[0.14em] ${statusStyles[entry.status]}`}>
              {entry.status}
            </span>
          </div>
          <div>
            <p className="text-sm font-medium text-white/50">{entry.classification}</p>
            <h2 className="mt-1 text-3xl font-black tracking-tight text-white">{entry.name}</h2>
          </div>
        </div>
      </div>

      <div className="space-y-5 p-6">
        <p className="min-h-20 text-sm leading-6 text-white/65">{entry.summary}</p>

        <div className="flex flex-wrap gap-2" aria-label="Elements">
          {entry.elements.map((element) => (
            <span key={element} className="rounded-full border border-white/10 bg-white/[0.04] px-3 py-1 text-xs font-semibold text-white/80">
              {element}
            </span>
          ))}
        </div>

        <dl className="grid grid-cols-2 gap-4 border-t border-white/10 pt-4 text-sm">
          <div>
            <dt className="text-xs uppercase tracking-[0.14em] text-white/35">Role</dt>
            <dd className="mt-1 font-semibold text-white/80">{entry.role}</dd>
          </div>
          <div>
            <dt className="text-xs uppercase tracking-[0.14em] text-white/35">Stat focus</dt>
            <dd className="mt-1 font-semibold text-white/80">{entry.statFocus.join(" / ")}</dd>
          </div>
        </dl>

        <Link
          href={`/eco-kin/${entry.slug}`}
          className="inline-flex min-h-11 w-full items-center justify-center rounded-xl border border-cyan-300/20 bg-cyan-300/10 px-4 text-sm font-bold text-cyan-100 transition hover:bg-cyan-300 hover:text-slate-950 focus-visible:outline focus-visible:outline-2 focus-visible:outline-offset-2 focus-visible:outline-cyan-300"
        >
          Open EcoDex profile
        </Link>
      </div>
    </article>
  );
}
