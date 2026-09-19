# ECHOHEARTS: REBEARTH Website — Eco-Kin Bestiary

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

## Canon Status
APPROVED-PENDING IMPLEMENTATION QA

## Player-Experience Reason
The public website should make the Eco-Kin roster feel alive, searchable, and trustworthy while clearly separating locked canon from material still in development.

## First Release Scope
- Public home page with the project Heart Statement.
- `/eco-kin` searchable/filterable Data Grid.
- `/eco-kin/[slug]` profile routes.
- Filters for Element, Canon Status, and Classification.
- Search by canonical name, EcoKinID, or habitat.
- V/D/H/P visualization that refuses to invent balance values.
- Responsive cards and keyboard-accessible controls.
- Reduced-motion support.

## Data Rules
The React UI renders from structured Eco-Kin data. Do not maintain separate hard-coded card lists.

Each web entry currently contains:
- EcoKinID
- slug
- canonical/display name
- classification
- canonical elements
- habitats
- gameplay role
- growth stage
- canon status
- availability
- public summary
- V/D/H/P stat focus
- optional locked numeric V/D/H/P values
- optional growth/forms path

## Canon Status Labels
- `CANON`: sufficiently locked for public display.
- `APPROVED-PENDING`: direction approved but still needs final canon/balance/art verification.
- `IN DEVELOPMENT`: visible only when intentionally exposing development material.

## Public Truthfulness Rule
Do not publish implementation claims such as dedicated-server completion, procedural voxel completion, shipping platform support, or verified Unreal systems unless repository/build/test evidence supports them.

## Technology Direction
- Next.js App Router
- React
- TypeScript
- Tailwind CSS v4 through `@tailwindcss/postcss`
- `@import "tailwindcss";` in global CSS

## Source Files
Website implementation lives under `/web`.

## QA Acceptance Criteria
- [ ] `npm install` succeeds.
- [ ] `npm run build` succeeds.
- [ ] `/` renders without console errors.
- [ ] `/eco-kin` search/filter interactions work with keyboard and pointer.
- [ ] Empty search state is understandable.
- [ ] Every Eco-Kin card links to a valid profile route.
- [ ] Numeric V/D/H/P values never appear unless explicitly present in source data.
- [ ] Status labels match source data.
- [ ] Reduced-motion preference is respected.
- [ ] Mobile layout remains usable at 320 CSS px width.
- [ ] No unverified engineering claims appear in public copy.

## Verification Status
NOT YET VERIFIED. Code has been committed for review, but install/build/browser/accessibility testing has not yet been run in this repository environment.
