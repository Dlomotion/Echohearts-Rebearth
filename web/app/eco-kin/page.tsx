import Link from "next/link";
import { EcoKinExplorer } from "@/components/EcoKinExplorer";
import { ecoKinRoster } from "@/data/ecoKin";

export const metadata = {
  title: "Eco-Kin Data Grid",
  description: "Search and filter the living Eco-Kin roster for ECHOHEARTS: REBEARTH.",
};

export default function EcoKinIndexPage() {
  return (
    <main className="min-h-screen bg-slate-950 text-white">
      <nav className="border-b border-white/10 bg-slate-950/90 backdrop-blur-xl">
        <div className="mx-auto flex max-w-7xl items-center justify-between px-6 py-4">
          <Link href="/" className="text-sm font-black tracking-[0.18em] text-white">
            ECHOHEARTS: <span className="text-cyan-300">REBEARTH</span>
          </Link>
          <Link href="/" className="text-sm font-semibold text-white/60 hover:text-white">
            Back to world
          </Link>
        </div>
      </nav>

      <section className="mx-auto max-w-7xl px-6 pb-24 pt-16">
        <div className="mb-10 max-w-3xl">
          <p className="text-xs font-black uppercase tracking-[0.22em] text-cyan-300">EcoDex Archive</p>
          <h1 className="mt-3 text-5xl font-black tracking-[-0.04em] sm:text-6xl">Eco-Kin Data Grid</h1>
          <p className="mt-5 text-lg leading-8 text-white/55">
            Search the current development roster by name, EcoKinID, element, class, habitat, or canon status. Numeric V/D/H/P values only appear after balance values are actually locked.
          </p>
        </div>

        <EcoKinExplorer roster={ecoKinRoster} />
      </section>
    </main>
  );
}
