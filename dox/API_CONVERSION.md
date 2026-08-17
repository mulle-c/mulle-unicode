# Conversion — Simple Unicode case mapping

`mulle-unicode` provides simple (1:1) case conversion for Unicode code points.
Each function maps a single code point to a single code point.

The data is derived from Unicode 12.1 `UnicodeData.txt`.

---

## Functions

| Function | Description |
|----------|-------------|
| `int32_t mulle_unicode_tolower( int32_t c)` | Simple lowercase mapping |
| `int32_t mulle_unicode_toupper( int32_t c)` | Simple uppercase mapping |
| `int32_t mulle_unicode_totitlecase( int32_t c)` | Simple titlecase mapping |
| `uint16_t mulle_unicode16_tolower( uint16_t c)` | BMP-only lowercase |
| `uint16_t mulle_unicode16_toupper( uint16_t c)` | BMP-only uppercase |
| `uint16_t mulle_unicode16_totitlecase( uint16_t c)` | BMP-only titlecase |

All functions return the mapped code point, or `c` unchanged if no mapping exists.

---

## Simple vs. full case mapping

These are **simple** case mappings: one code point in, one code point out. This
means they cannot handle cases where Unicode specifies a length change:

- U+00DF ß → "SS" (toupper is a no-op here, returns ß)
- U+0130 İ → U+0069 + U+0307 (tolower returns U+0069, loses the dot)
- Context-dependent mappings (Greek final sigma, Turkish dotless-i)

For case-insensitive comparison, use proper case folding (not provided by this
library) rather than `tolower`.

---

## Titlecase

`totitlecase` maps to the Unicode titlecase form. For most characters this is the
same as uppercase. The difference matters for digraph ligatures:

| Input | toupper | totitlecase |
|-------|---------|-------------|
| U+01C6 dž | U+01C4 DŽ | U+01C5 Dž |
| U+01C9 lj | U+01C7 LJ | U+01C8 Lj |
| U+01F3 dz | U+01F1 DZ | U+01F2 Dz |

---

## Usage example

```c
#include <mulle-unicode/mulle-unicode.h>

int32_t c = 0x10428;  // 𐐨 Deseret Small Letter Long I
int32_t u = mulle_unicode_toupper( c);      // 0x10400 𐐀 Deseret Capital Letter Long I
int32_t l = mulle_unicode_tolower( u);      // 0x10428 round-trips back
int32_t t = mulle_unicode_totitlecase( c);  // 0x10400 (same as toupper for Deseret)
```
