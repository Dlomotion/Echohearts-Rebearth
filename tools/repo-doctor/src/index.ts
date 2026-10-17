import { existsSync, readFileSync, readdirSync } from "node:fs";
import { join, relative } from "node:path";

type Finding = { severity: "error" | "warning"; code: string; path: string; message: string };

const root = process.cwd();
const findings: Finding[] = [];
const requiredCanon = ["00_Canon_Lock", "03_EcoKin_Dex", "04_Systems", "09_Technical"];
const bannedStats = /\b(Strength|Mana|Agility)\b/g;
const canonicalStats = ["Vibrance", "Density", "Harmony", "Purity"];

function add(severity: Finding["severity"], code: string, path: string, message: string) {
  findings.push({ severity, code, path, message });
}

for (const dir of requiredCanon) {
  if (!existsSync(join(root, dir))) add("error", "EH001", dir, "Required canonical project directory is missing.");
}

const projectFiles = readdirSync(root).filter((x) => x.endsWith(".uproject"));
if (projectFiles.length > 1) add("error", "EH002", ".", `Multiple .uproject files found: ${projectFiles.join(", ")}`);

for (const file of [".gitignore", ".gitattributes"]) {
  if (!existsSync(join(root, file))) add("warning", "EH003", file, "Repository policy file is missing.");
}

function walk(dir: string) {
  for (const entry of readdirSync(dir, { withFileTypes: true })) {
    if ([".git", "node_modules", "Binaries", "DerivedDataCache", "Intermediate", "Saved"].includes(entry.name)) continue;
    const full = join(dir, entry.name);
    if (entry.isDirectory()) walk(full);
    else if (/\.(md|json|ini|yml|yaml|ts|js|cs|h|hpp|cpp|csproj|Build\.cs)$/i.test(entry.name)) inspect(full);
  }
}

function inspect(file: string) {
  let text: string;
  try { text = readFileSync(file, "utf8"); } catch { return; }
  const path = relative(root, file);
  const bad = [...text.matchAll(bannedStats)].map((m) => m[0]);
  if (bad.length) add("warning", "EH010", path, `Generic RPG stat names found: ${[...new Set(bad)].join(", ")}. Review against the canonical attribute matrix.`);
  if (/Legendary Monarch/i.test(text)) add("error", "EH011", path, 'Forbidden Nature classification "Legendary Monarch" found.');
  if (/Echo-Kin/i.test(text)) add("warning", "EH012", path, 'Use canonical classification "Eco-Kin" unless quoting historical material.');
}

walk(root);

const canonText = existsSync(join(root, ".github", "copilot-instructions.md"))
  ? readFileSync(join(root, ".github", "copilot-instructions.md"), "utf8")
  : "";
for (const stat of canonicalStats) {
  if (!canonText.includes(stat)) add("error", "EH020", ".github/copilot-instructions.md", `Canonical stat missing from Copilot contract: ${stat}`);
}

console.log(JSON.stringify({ ok: !findings.some((x) => x.severity === "error"), findings }, null, 2));
process.exitCode = findings.some((x) => x.severity === "error") ? 1 : 0;
