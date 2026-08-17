# Ctype — Unicode character classification

`mulle-unicode` provides `<ctype.h>`-style character classification for the full
Unicode range (planes 0–16). Each predicate comes in three variants:

| Variant | Signature | Scope |
|---------|-----------|-------|
| 32-bit  | `int mulle_unicode_is_X( int32_t c)` | Full Unicode (U+0000–U+10FFFF) |
| 16-bit  | `int mulle_unicode16_is_X( uint16_t c)` | BMP only (U+0000–U+FFFF) |
| Plane   | `int mulle_unicode_is_Xplane( unsigned int plane)` | Quick reject by plane (0–16) |

All functions return 1 (true) or 0 (false). Invalid inputs (negative values,
values > U+10FFFF) return 0.

The data is derived from Unicode 12.1 `UnicodeData.txt`.

---

## Predicates

### Letters and identifiers

| Function | Unicode categories | Notes |
|----------|--------------------|-------|
| `is_letter` | `L.` (Lu, Ll, Lt, Lm, Lo) + `M.` (Mn, Mc, Me) | Includes combining marks |
| `is_uppercase` | `Lu`, `Lt` | Includes titlecase letters |
| `is_lowercase` | `Ll` | |
| `is_capitalized` | `Lt` | Titlecase letters only (e.g. U+01C5 Dž) |
| `is_identifierstart` | `L.` + `Nl` | Letters plus letter-numbers (e.g. Roman numerals) |
| `is_identifiercontinuation` | `L.` + `M.` + `Nd` + `Nl` + `Pc` | Adds digits, marks, connector punctuation |

### Numbers

| Function | Unicode categories / fields | Notes |
|----------|----------------------------|-------|
| `is_decimaldigit` | `Nd` | Decimal digits with contiguous 0–9 runs |
| `is_zerodigit` | `Nd` with numeric value 0 | Start of a 0–9 run; use `c - zero` for digit value |

### Separators and whitespace

| Function | Matches | Notes |
|----------|---------|-------|
| `is_whitespace` | `Zs` + U+0009 (TAB) | Unicode space separators plus TAB |
| `is_newline` | U+000A–U+000D, U+0085, U+2028, U+2029 | Line/paragraph terminators |
| `is_whitespaceornewline` | `is_whitespace` ∪ `is_newline` | |

### Classification

| Function | Unicode categories | Notes |
|----------|--------------------|-------|
| `is_alphanumeric` | `L.` + `M.` + `N.` | Letters, marks, and all numbers |
| `is_punctuation` | `P.` | All punctuation categories |
| `is_symbol` | `S.` | All symbol categories |
| `is_control` | `Cc` + `Cf` | Control and format characters |
| `is_nonbase` | `M.` | Combining marks (non-spacing, spacing, enclosing) |

### Validation

| Function | Meaning | Notes |
|----------|---------|-------|
| `is_legalcharacter` | Defined in Unicode, excluding surrogates | U+D800–U+DFFF return 0 |
| `is_noncharacter` | Permanently reserved code points | U+FDD0–U+FDEF, U+xFFFE, U+xFFFF |
| `is_decomposable` | Has a canonical or compatibility decomposition | |

---

## Input contract

All `int32_t` functions accept the full range of `int32_t`. Values outside
U+0000–U+10FFFF return 0 for all predicates (they are not Unicode code points).
Surrogates (U+D800–U+DFFF) are valid inputs but are not letters, digits,
whitespace, etc. — only `is_noncharacter` reports them as true.

The `uint16_t` variants are equivalent to the `int32_t` variants for BMP code
points. They cannot express supplementary characters.

## Plane functions

The `*plane( unsigned int plane)` functions answer "does plane N contain any
character with property X?" — useful as a quick reject before doing per-character
lookup. Plane values 0–16 are valid; values ≥ 17 return 0 (except
`is_noncharacterplane` which returns 1 for all planes, since every plane contains
noncharacters at its top two code points).

## Usage example

```c
#include <mulle-unicode/mulle-unicode.h>

// classify a code point
int32_t c = 0x1F600;  // 😀
if( mulle_unicode_is_symbolplane( c >> 16))
   if( mulle_unicode_is_symbol( c))
      printf( "it's a symbol\n");

// extract digit value using zerodigit
int32_t digit = 0x0669;  // ٩ (Arabic-Indic Nine)
int32_t zero  = 0x0660;  // ٠ (Arabic-Indic Zero)
if( mulle_unicode_is_zerodigit( zero) && mulle_unicode_is_decimaldigit( digit))
{
   int value = digit - zero;  // 9
}
```
