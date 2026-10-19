export type EcoKinStatus = "CANON" | "APPROVED-PENDING" | "IN DEVELOPMENT";

export type EcoKinElement =
  | "Solar"
  | "Lunar"
  | "Hydro"
  | "Magma"
  | "Aero"
  | "Flora"
  | "Volt"
  | "Terra"
  | "Iron/Tech"
  | "Spirit"
  | "Chaos"
  | "Radiant";

export type EcoKinStatKey = "Vibrance" | "Density" | "Harmony" | "Purity";

export interface EcoKinStats {
  vibrance?: number;
  density?: number;
  harmony?: number;
  purity?: number;
}

export interface EcoKinEntry {
  id: string;
  slug: string;
  name: string;
  classification: string;
  elements: EcoKinElement[];
  habitats: string[];
  role: string;
  growthStage: string;
  status: EcoKinStatus;
  availability: string;
  summary: string;
  statFocus: EcoKinStatKey[];
  stats?: EcoKinStats;
  forms?: string[];
}
