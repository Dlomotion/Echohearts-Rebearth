# ECHOHEARTS: REBEARTH — EBOOK CROSS-PLATFORM PUBLICATION STANDARD

**Date:** 2026-10-05  
**Status:** PUBLICATION CONTRACT / NOT YET VERIFIED  
**Primary interchange target:** EPUB 3.3  
**Future-watch target:** EPUB 3.4 Candidate Recommendation compatibility review  
**Canon rule:** publication exports must consume approved Echohearts canon; they may not become a second canon authority.

---

## 1. Purpose

Create one reusable digital-publication pipeline for Echohearts: Rebearth lore, game-universe books, guides, story material, codices, and companion publications that can be validated across major ebook ecosystems without forking text or canon independently per storefront.

The publication strategy is:

> **One canonical manuscript source → validated EPUB master → platform-specific derivatives only where required.**

## 2. Canon source-of-truth rule

Before publication, names, locations, Eco-Kin identities, forms, story events, and terminology must be checked against the repository's active canon sources.

Publication work must preserve:

- Rebearth as the target planet;
- Eco-Kin terminology;
- Nature's current canonical role;
- the 125-ID Permanent Dex authority;
- Forms/Evolutions linkage to base Eco-Kin;
- Vibrance, Density, Harmony, and Purity where game attributes are discussed;
- established story chronology and current canon locks;
- originality boundaries.

The ebook is a distribution surface, not a new Master Bible.

## 3. Master format

Use **EPUB 3.3** as the stable publication baseline because it is a W3C Recommendation.

Track EPUB 3.4 separately while it remains a Candidate Recommendation. Do not make a draft standard mandatory for production unless the major target reading systems demonstrate acceptable compatibility.

Useful standards:

- EPUB 3.3: https://www.w3.org/TR/epub-33/
- EPUB Accessibility 1.1: https://www.w3.org/TR/epub-a11y-11/

## 4. Publication outputs

Required output candidates:

- validated `.epub` master;
- Kindle-compatible EPUB upload package;
- optional KPF derivative when Kindle-specific production benefits justify it;
- Apple Books-compatible EPUB;
- Kobo-compatible EPUB;
- Google Play Books-compatible EPUB;
- accessible digital PDF where specifically required;
- print PDF generated from a separate print-layout path rather than treating ebook reflow as print layout.

Do not treat MOBI as the canonical source format.

## 5. Reflowable-first rule

Default Echohearts prose/lore books should be reflowable.

Use fixed layout only when the publication's function truly depends on exact spatial composition, such as:

- art books;
- illustrated field guides;
- map-heavy reference books;
- graphic narratives;
- image-led design documents intended for public release.

Fixed layout must not be selected merely to preserve desktop word-processor page appearance.

## 6. Semantic document structure

Every ebook should use meaningful structure:

```text
Book
├── Front Matter
│   ├── Title
│   ├── Copyright
│   ├── Edition / Version
│   └── Accessibility / Content Notes where needed
├── Navigation
├── Main Matter
│   ├── Part
│   ├── Chapter
│   ├── Section
│   ├── Figures
│   ├── Tables
│   └── Notes
└── Back Matter
    ├── Glossary
    ├── Eco-Kin Index where appropriate
    ├── Lore/Location Index where appropriate
    └── Credits
```

Heading levels must reflect document hierarchy rather than visual styling.

## 7. Navigation requirements

Every publication must include:

- EPUB navigation document;
- logical table of contents;
- landmark navigation where appropriate;
- working internal chapter links;
- return links for notes/footnotes where used;
- no dead links;
- no navigation that depends only on page numbers from a print edition.

## 8. Typography and CSS

Required behavior:

- body text remains reflowable;
- reader font-size controls are respected;
- avoid fixed pixel text sizes for body copy;
- avoid forcing a single font when the reading system/user overrides it;
- line height remains readable at large text sizes;
- headings do not clip when enlarged;
- dark/light reading themes remain legible;
- color is not the only carrier of meaning;
- decorative fonts are limited to display roles.

## 9. Images and art

For each image:

- use an appropriate compressed format;
- retain sufficient resolution for target reading systems;
- avoid oversized source files that inflate downloads without visible benefit;
- include alt text for meaningful images;
- mark purely decorative images appropriately;
- preserve approved Eco-Kin identity and naming;
- never insert unapproved/rejected concept art as canonical by accident.

Image captions must remain associated with the correct image during reflow.

## 10. Accessibility baseline

Every public Echohearts ebook should target EPUB Accessibility 1.1 principles.

At minimum:

- logical reading order;
- semantic headings;
- meaningful image alt text;
- decorative images identified as decorative;
- descriptive link text;
- adequate text/background contrast for authored styles;
- no information conveyed only by color;
- tables use real table structure where appropriate;
- language metadata is correct;
- page-list metadata is added when matching a print edition and useful;
- accessibility metadata is included when known;
- keyboard/screen-reader navigation does not depend on pointer-only interaction.

## 11. Metadata

Every release should define:

- title;
- subtitle where applicable;
- creator/author credit;
- contributor credits;
- language;
- identifier/ISBN where assigned;
- publisher/imprint;
- publication/modification date;
- rights statement;
- series information;
- volume/edition;
- accessibility metadata;
- cover metadata.

Repository commit/tag or internal publication version should be retained in production records even if not exposed to readers.

## 12. Storefront compatibility targets

### Kindle

Amazon KDP accepts EPUB and recommends validating/previewing with Kindle Previewer. Test at minimum:

- Kindle E Ink class;
- Kindle app on iOS;
- Kindle app on Android;
- Kindle app on desktop where available;
- Fire tablet class when relevant.

### Apple Books

Test:

- iPhone;
- iPad;
- macOS Apple Books;
- portrait/landscape where applicable;
- dynamic text/font changes;
- dark/light themes.

### Kobo

Test:

- Kobo E Ink class;
- Kobo mobile application where available;
- font resizing;
- navigation;
- image scaling.

### Google Play Books

Test:

- Android;
- iOS where available;
- web/desktop reading surface where supported;
- font/theme changes;
- TOC and internal navigation.

## 13. Validation toolchain

Before upload:

1. build EPUB;
2. run EPUBCheck;
3. fix all actionable errors;
4. review warnings;
5. test accessibility with automated tooling where available;
6. inspect manually in multiple reading systems;
7. run Kindle Previewer for Kindle distribution;
8. inspect Apple Books import/render;
9. inspect Kobo/Google Play Books preview or uploaded proof where available;
10. archive the exact release artifact and checksum.

An EPUB that merely opens on one device is not cross-platform verified.

## 14. Functional ebook test suite

Test:

- file opens;
- cover displays;
- metadata displays correctly;
- TOC works;
- chapter order is correct;
- next/previous navigation works;
- internal links work;
- external links are intentional and secure;
- footnotes/endnotes return correctly;
- images scale without clipping;
- captions remain attached;
- large text does not overlap;
- dark mode remains readable;
- landscape remains readable where applicable;
- search finds expected text;
- bookmarks/highlights work where supported;
- reading progress behaves normally;
- screen reader follows logical order;
- offline reading does not depend on remote essential assets.

## 15. Cross-device visual test matrix

At minimum record results for:

| Class | Required checks |
|---|---|
| E Ink small | reflow, chapter navigation, image grayscale/readability, large fonts |
| Phone | portrait, large text, dark mode, image scaling |
| Tablet | portrait/landscape, art scaling, tables |
| Desktop | wide-window reflow, navigation, image sizing |
| Accessibility | screen reader, reading order, alt text, keyboard navigation where supported |

## 16. Publication verification vocabulary

Use:

- **DRAFT** — manuscript/content incomplete.
- **CANON-REVIEWED** — story/names/terminology checked against repository authority.
- **EPUB-BUILT** — EPUB artifact generated.
- **VALIDATED** — automated EPUB validation passes required gates.
- **RENDER-TESTED** — manually tested on named reading systems/devices.
- **STOREFRONT-READY** — target storefront preview/submission checks pass.
- **VERIFIED** — exact artifact, checksum, test matrix, and review record retained.

Do not use `VERIFIED` when only an export exists.

## 17. Suggested repository production record

For each release:

```text
11_Publication/Releases/<Title>/<Version>/
├── PUBLICATION_MANIFEST.md
├── CANON_REVIEW.md
├── VALIDATION_RESULTS.md
├── DEVICE_TEST_MATRIX.md
├── ACCESSIBILITY_REVIEW.md
├── STORE_PREVIEW_RESULTS.md
└── CHECKSUMS.txt
```

Binary release artifacts may live in approved release storage rather than bloating the repository; the manifest should point to the controlled artifact location or release attachment.

## 18. Canon-change handling

When canon changes after publication:

1. classify whether the published text is still valid for its edition;
2. do not silently rewrite historical editions without versioning;
3. update the canonical manuscript source;
4. increment edition/version;
5. rebuild and revalidate;
6. record what changed;
7. retest affected links/navigation/rendering.

## 19. Current verification boundary

This standard does not claim that any Echohearts ebook has already passed Kindle, Apple Books, Kobo, Google Play Books, EPUBCheck, screen-reader, or device-matrix testing.

Actual storefront/device verification requires the built publication artifact and recorded test evidence.
