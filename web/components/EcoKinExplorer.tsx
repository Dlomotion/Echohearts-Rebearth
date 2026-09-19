"use client";

import { useMemo, useState } from "react";
import { EcoKinCard } from "@/components/EcoKinCard";
import type { EcoKinEntry } from "@/types/ecoKin";

const ALL = "ALL";

export function EcoKinExplorer({ roster }: { roster: EcoKinEntry[] }) {
  const [query, setQuery] = useState("");
  const [element, setElement] = useState(ALL);
  const [status, setStatus] = useState(ALL);
  const [classification, setClassification] = useState(ALL);

  const elementOptions = useMemo(
    () => Array.from(new Set(roster.flatMap((entry) => entry.elements))).sort(),
    [roster],
  );

  const statusOptions = useMemo(
    () => Array.from(new Set(roster.map((entry) => entry.status))).sort(),
    [roster],
  );

  const classificationOptions = useMemo(
    () => Array.from(new Set(roster.map((entry) => entry.classification))).sort(),
    [roster],
  );

  const filtered = useMemo(() => {
    const normalized = query.trim().toLowerCase();

    return roster.filter((entry) => {
      const matchesSearch =
        !normalized ||
        entry.name.toLowerCase().includes(normalized) ||
        entry.id.toLowerCase().includes(normalized) ||
        entry.habitats.some((habitat) => habitat.toLowerCase().includes(normalized));
      const matchesElement = element === ALL || entry.elements.includes(element as EcoKinEntry["elements"][number]);
      const matchesStatus = status === ALL || entry.status === status;
      const matchesClassification = classification === ALL || entry.classification === classification;

      return matchesSearch && matchesElement && matchesStatus && matchesClassification;
    });
  }, [classification, element, query, roster, status]);

  function resetFilters() {
    setQuery("");
    setElement(ALL);
    setStatus(ALL);
    setClassification(ALL);
  }

  return (
    <section aria-labelledby="ecokin-grid-title" className="space-y-8">
      <div className="rounded-3xl border border-white/10 bg-white/[0.03] p-5 md:p-6">
        <div className="grid gap-4 md:grid-cols-2 xl:grid-cols-4">
          <label className="space-y-2 md:col-span-2 xl:col-span-1">
            <span className="text-xs font-black uppercase tracking-[0.16em] text-white/45">Search</span>
            <input
              type="search"
              value={query}
              onChange={(event) => setQuery(event.target.value)}
              placeholder="Name, EcoKinID, or habitat"
              className="min-h-12 w-full rounded-xl border border-white/10 bg-black/20 px-4 text-sm text-white outline-none transition placeholder:text-white/25 focus:border-cyan-300/50 focus:ring-2 focus:ring-cyan-300/15"
            />
          </label>

          <FilterSelect label="Element" value={element} onChange={setElement} options={elementOptions} />
          <FilterSelect label="Status" value={status} onChange={setStatus} options={statusOptions} />
          <FilterSelect label="Class" value={classification} onChange={setClassification} options={classificationOptions} />
        </div>

        <div className="mt-5 flex flex-wrap items-center justify-between gap-3 border-t border-white/10 pt-4">
          <p className="text-sm text-white/55" aria-live="polite">
            Showing <strong className="text-white">{filtered.length}</strong> of {roster.length} indexed Eco-Kin.
          </p>
          <button
            type="button"
            onClick={resetFilters}
            className="min-h-11 rounded-xl border border-white/10 px-4 text-sm font-bold text-white/70 transition hover:border-white/25 hover:text-white focus-visible:outline focus-visible:outline-2 focus-visible:outline-offset-2 focus-visible:outline-cyan-300"
          >
            Reset filters
          </button>
        </div>
      </div>

      <div>
        <div className="mb-5 flex items-end justify-between gap-4">
          <div>
            <p className="text-xs font-black uppercase tracking-[0.2em] text-cyan-300">Living roster</p>
            <h2 id="ecokin-grid-title" className="mt-2 text-3xl font-black tracking-tight text-white">
              Eco-Kin Data Grid
            </h2>
          </div>
          <p className="hidden max-w-md text-right text-sm leading-6 text-white/45 md:block">
            Entries expose development status so unfinished material is never mistaken for locked canon.
          </p>
        </div>

        {filtered.length ? (
          <div className="grid gap-5 md:grid-cols-2 xl:grid-cols-3">
            {filtered.map((entry) => (
              <EcoKinCard key={entry.id} entry={entry} />
            ))}
          </div>
        ) : (
          <div className="rounded-3xl border border-dashed border-white/15 p-10 text-center">
            <p className="text-lg font-bold text-white">No Eco-Kin match those filters.</p>
            <button type="button" onClick={resetFilters} className="mt-3 text-sm font-semibold text-cyan-300 hover:text-cyan-200">
              Clear the search
            </button>
          </div>
        )}
      </div>
    </section>
  );
}

function FilterSelect({
  label,
  value,
  onChange,
  options,
}: {
  label: string;
  value: string;
  onChange: (value: string) => void;
  options: string[];
}) {
  return (
    <label className="space-y-2">
      <span className="text-xs font-black uppercase tracking-[0.16em] text-white/45">{label}</span>
      <select
        value={value}
        onChange={(event) => onChange(event.target.value)}
        className="min-h-12 w-full rounded-xl border border-white/10 bg-slate-950 px-4 text-sm text-white outline-none transition focus:border-cyan-300/50 focus:ring-2 focus:ring-cyan-300/15"
      >
        <option value={ALL}>All</option>
        {options.map((option) => (
          <option key={option} value={option}>
            {option}
          </option>
        ))}
      </select>
    </label>
  );
}
