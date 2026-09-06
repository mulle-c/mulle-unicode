# mulle-unicode Library Documentation for AI
<!-- Keywords: unicode, ctype, classification, case-conversion, utf16, table-driven -->

## 1. Introduction & Purpose

`mulle-unicode` is a compact C99 library that provides `<ctype.h>`-style
character classification and simple (1:1) case conversion for the **full
Unicode range** (U+0000–U+10FFFF). It is a component of the
`mulle-core` ecosystem (a dependency of `mulle-core`), and can also be used
standalone via `clib` or `mulle-sde`.

- The predicate and conversion data tables are generated from
  `UnicodeData.txt` (currently Unicode 12.1, see `src/unicode/README.md`)
  by the scripts in `unicode/`.
- Version 2.4.14 (`MULLE__UNICODE_VERSION`). Since 2.4.14 the predicates
  were hardened: all `is_*` predicates return `0` for inputs outside
  U+0000–U+10FFFF (negative or > U+10FFFF no longer wrap or misreport),
  `is_legalcharacter` now rejects surrogates (U+D800–U+DFFF), and
  `totitlecase` now covers the full 32-bit code-point range including
  supplementary planes.
- The library compiles to roughly 256KB and has no runtime allocations or
  global state; all functions are pure.

## 2. Key Concepts & Design Philosophy

- **Unicode-coddle, table-driven:** Character properties are encoded either as
  generated three-level sparse-trie bitmaps (`*-bitmap.inc`) or as flat
  generated `switch` statements (`is*-utf16.inc`, `is*-utf32.inc`,
  `tolower-*.inc`, `toupper-*.inc`, `totitlecase-*.inc`). Lookups are O(1) for
  any code point.
- **Three variants per predicate:** each predicate exists as
  `mulle_unicode_is_X( int32_t)` (full range), `mulle_unicode16_is_X( uint16_t)`
  (BMP only), and `mulle_unicode_is_Xplane( unsigned int)` (per-plane quick
  reject, planes 0–16).
- **Strict input contract:** the `int32_t` predicates accept the full
  `int32_t` domain; anything outside U+0000–U+10FFFF returns `0` (it is not a
  Unicode code point). Surrogates U+D800–U+DFFF are accepted as inputs but are
  only classified as `is_noncharacter`.
- **Simple (1:1) case mapping:** conversions map one code point to one code
  point; multi-character mappings, context-dependent and locale-dependent
  rules are not handled.
- **Pure and thread-safe:** no globals are written; functions can be called
  concurrently from any thread.

## 3. Core API & Data Structures

There are no public structs. Everything is a free function. The umbrella
header `mulle-unicode.h` includes every public header; `mulle-unicode-ctype.h`
includes only the `is_*` headers. The `MULLE__UNICODE_GLOBAL` macro prefix in
the headers expands to `extern` (or an export/import specifier when built
dynamically).

### 3.1. `mulle-unicode.h`

```
#define MULLE__UNICODE_VERSION  ((2UL << 20) | (4 << 8) | 14)
```
- **Purpose:** umbrella header; declares the library version (2.4.14) and
  includes all sub-headers below.

### 3.2. Predicate headers (`mulle-unicode-ctype.h` and `mulle-unicode-is-*.h`)

Every predicate header follows the identical pattern. Representative example
from `mulle-unicode-is-letter.h`:

```
int   mulle_unicode16_is_letter( uint16_t c);
int   mulle_unicode_is_letter( int32_t c);
int   mulle_unicode_is_letterplane( unsigned int plane);
```

- The `int32_t` variant runs over the full Unicode range; the `uint16_t`
  variant is the BMP-only equivalent; the `*plane` variant returns nonzero if
  any code point in plane `plane` (0–16) satisfies the predicate (plane ≥ 17
  returns 0, except `is_noncharacterplane`, which always returns 1).
- All return `1` (true) or `0` (false). For the `int32_t` variants, values
  `< 0` and `> 0x10FFFF` return `0`.

#### Letters and identifiers

`mulle-unicode-is-letter.h`
```
int   mulle_unicode16_is_letter( uint16_t c);
int   mulle_unicode_is_letter( int32_t c);
int   mulle_unicode_is_letterplane( unsigned int plane);
```
- **`mulle_unicode_is_letter`:** letters (general categories `L.`) **including**
  combining marks / nonbase marks (`M.`). Empirically `is_letter(0x0301) == 1`.
  Letter-numbers `Nl` (e.g. U+2160) are **not** letters.

`mulle-unicode-is-uppercase.h`
```
int   mulle_unicode16_is_uppercase( uint16_t c);
int   mulle_unicode_is_uppercase( int32_t c);
int   mulle_unicode_is_uppercaseplane( unsigned int plane);
```
- **`mulle_unicode_is_uppercase`:** uppercase letters (`Lu`) **including**
  titlecase letters (`Lt`, e.g. U+01C5 returns true).

`mulle-unicode-is-lowercase.h`
```
int   mulle_unicode16_is_lowercase( uint16_t c);
int   mulle_unicode_is_lowercase( int32_t c);
int   mulle_unicode_is_lowercaseplane( unsigned int plane);
```
- **`mulle_unicode_is_lowercase`:** lowercase letters (`Ll`).

`mulle-unicode-is-capitalized.h`
```
int   mulle_unicode16_is_capitalized( uint16_t c);
int   mulle_unicode_is_capitalized( int32_t c);
int   mulle_unicode_is_capitalizedplane( unsigned int plane);
```
- **`mulle_unicode_is_capitalized`:** titlecase letters only (`Lt`, e.g.
  U+01C5 "Dž").

`mulle-unicode-is-identifierstart.h`
```
int   mulle_unicode_is_identifierstart( int32_t c);
int   mulle_unicode16_is_identifierstart( uint16_t c);
int   mulle_unicode_is_identifierstartplane( unsigned int plane);
```
- **`mulle_unicode_is_identifierstart`:** letters (`L.`) only. Empirically
  combining marks (U+0301) and underscore `_` (U+005F) are **not** identifier
  starts.

`mulle-unicode-is-identifiercontinuation.h`
```
int   mulle_unicode_is_identifiercontinuation( int32_t c);
int   mulle_unicode16_is_identifiercontinuation( uint16_t c);
int   mulle_unicode_is_identifiercontinuationplane( unsigned int plane);
```
- **`mulle_unicode_is_identifiercontinuation`:** letters (`L.`), combining
  marks (`M.`), decimal digits (`Nd`), connector punctuation (`Pc`, e.g. `_`).
  Letter-numbers (`Nl`, e.g. U+2160) and format chars such as ZWNJ (U+200C)
  are empirically **excluded**.

#### Numbers

`mulle-unicode-is-decimaldigit.h`
```
int   mulle_unicode16_is_decimaldigit( uint16_t c);
int   mulle_unicode_is_decimaldigit( int32_t c);

static inline
int   mulle_unicode_is_decimaldigitplane( unsigned int plane);
```
- **`mulle_unicode_is_decimaldigit`:** decimal-digit category `Nd` (characters
  forming contiguous 0–9 runs in each script). `is_decimaldigitplane` is a
  `static inline` that returns 1 for planes 0 and 1 only.

`mulle-unicode-is-zerodigit.h`
```
int   mulle_unicode16_is_zerodigit( uint16_t c);
int   mulle_unicode_is_zerodigit( int32_t c);

static inline
int   mulle_unicode_is_zerodigitplane( unsigned int plane);
```
- **`mulle_unicode_is_zerodigit`:** the "zero" character of a decimal run
  (e.g. U+0030 '0', U+0660 '٠'). Use `digit - zerodigit` to get the
  numeric value. `is_zerodigitplane` is `static inline`; returns 1 for planes
  0, 1 and 14.

#### Separators and whitespace

`mulle-unicode-is-whitespace.h`
```
int   mulle_unicode16_is_whitespace( uint16_t c);
int   mulle_unicode_is_whitespace( int32_t c);
int   mulle_unicode_is_whitespaceplane( unsigned int plane);
```
- **`mulle_unicode_is_whitespace`:** space separators (`Zs`) plus U+0009 TAB.
  Newlines like U+000A and U+2028 are **not** whitespace (use
  `is_whitespaceornewline` / `is_newline`).

`mulle-unicode-is-newline.h`
```
int   mulle_unicode16_is_newline( uint16_t c);
int   mulle_unicode_is_newline( int32_t c);
int   mulle_unicode_is_newlineplane( unsigned int plane);
```
- **`mulle_unicode_is_newline`:** line and paragraph terminators:
  U+000A–U+000D, U+0085, U+2028, U+2029.

`mulle-unicode-is-whitespaceornewline.h`
```
int   mulle_unicode16_is_whitespaceornewline( uint16_t c);
int   mulle_unicode_is_whitespaceornewline( int32_t c);
int   mulle_unicode_is_whitespaceornewlineplane( unsigned int plane);
```
- **`mulle_unicode_is_whitespaceornewline`:** union of `is_whitespace` and
  `is_newline`.

#### Other classes

`mulle-unicode-is-alphanumeric.h`
```
int   mulle_unicode16_is_alphanumeric( uint16_t c);
int   mulle_unicode_is_alphanumeric( int32_t c);
int   mulle_unicode_is_alphanumericplane( unsigned int plane);
```
- **`mulle_unicode_is_alphanumeric`:** letters + marks + all numbers
  (`L.`, `M.`, `N.`). Note it includes combining marks.

`mulle-unicode-is-punctuation.h`
```
int   mulle_unicode16_is_punctuation( uint16_t c);
int   mulle_unicode_is_punctuation( int32_t c);
int   mulle_unicode_is_punctuationplane( unsigned int plane);
```
- **`mulle_unicode_is_punctuation`:** punctuation (`P.`).

`mulle-unicode-is-symbol.h`
```
int   mulle_unicode16_is_symbol( uint16_t c);
int   mulle_unicode_is_symbol( int32_t c);
int   mulle_unicode_is_symbolplane( unsigned int plane);
```
- **`mulle_unicode_is_symbol`:** symbols (`S.`: math, currency, modifier,
  letterlike, etc.).

`mulle-unicode-is-control.h`
```
int   mulle_unicode16_is_control( uint16_t c);
int   mulle_unicode_is_control( int32_t c);
int   mulle_unicode_is_controlplane( unsigned int plane);
```
- **`mulle_unicode_is_control`:** control and format characters (C0 custom
  U+0001–U+001F, C1 U+007F–U+009F, and various `Cf` such as U+00AD, U+200E,
  U+2060). Empirically U+0000 (NUL) and U+2028 (`Zl`) are **not** classified
  as control. `is_controlplane` returns 1 for planes 0, 1 and 14.

`mulle-unicode-is-nonbase.h`
```
int   mulle_unicode16_is_nonbase( uint16_t c);
int   mulle_unicode_is_nonbase( int32_t c);
int   mulle_unicode_is_nonbaseplane( unsigned int plane);
```
- **`mulle_unicode_is_nonbase`:** combining (non-spacing/spacing/enclosing)
  marks (`M.`).

#### Validation

`mulle-unicode-is-legalcharacter.h`
```
int   mulle_unicode16_is_legalcharacter( uint16_t c);
int   mulle_unicode_is_legalcharacter( int32_t c);
int   mulle_unicode_is_legalcharacterplane( unsigned int plane);
```
- **`mulle_unicode_is_legalcharacter`:** a code point is "legal" if it is
  defined in the Unicode data, excluding surrogates and noncharacters.
  Empirically U+D800, U+DFFF, U+10FFFF, and unassigned points like U+0378
  return 0; U+0020 returns 1.

`mulle-unicode-is-noncharacter.h`
```
int   mulle_unicode16_is_noncharacter( uint16_t c);
int   mulle_unicode_is_noncharacter( int32_t c);
int   mulle_unicode_is_noncharacterplane( unsigned int plane);
```
- **`mulle_unicode_is_noncharacter`:** the 66 permanently reserved
  noncharacters: U+FDD0–U+FDEF and the last two code points of each plane
  (U+xFFFE/U+xFFFF, planes 0–16). Surrogates U+D800–U+DFFF are also reported
  as true. Returns 0 for inputs `< 0` or `> 0x10FFFF`.
  `is_noncharacterplane` always returns 1.

`mulle-unicode-is-decomposable.h`
```
int   mulle_unicode16_is_decomposable( uint16_t c);
int   mulle_unicode_is_decomposable( int32_t c);
int   mulle_unicode_is_decomposableplane( unsigned int plane);
```
- **`mulle_unicode_is_decomposable`:** the code point has a canonical or
  compatibility decomposition (e.g. U+00E9 'é' is decomposable).

### 3.3. Conversion functions

`mulle-unicode-tolower.h`
```
uint16_t   mulle_unicode16_tolower( uint16_t c);
int32_t    mulle_unicode_tolower( int32_t c);

uint16_t   mulle_unicode16_nop( uint16_t c);
int32_t    mulle_unicode_nop( int32_t c);
```
- **`mulle_unicode_tolower`:** simple lowercase mapping; returns `c` unchanged
  when there is no mapping. Covers the full 32-bit range.
- **`mulle_unicode_nop` / `mulle_unicode16_nop`:** identity functions
  (useful as callback placeholders).

`mulle-unicode-toupper.h`
```
uint16_t   mulle_unicode16_toupper( uint16_t c);
int32_t    mulle_unicode_toupper( int32_t c);

uint16_t   mulle_unicode16_totitlecase( uint16_t c);
int32_t    mulle_unicode_totitlecase( int32_t c);
```
- **`mulle_unicode_toupper`:** simple uppercase mapping; unchanged if no
  mapping. Covers the full 32-bit range (e.g. U+10428 → U+10400).
- **`mulle_unicode_totitlecase`:** titlecase mapping. Since 2.4.14 this
  handles the full 32-bit range including supplementary planes (previously
  BMP-only). For most characters it equals uppercase; it differs for
  digraph ligatures: U+01C6 'dž' → U+01C5 'Dž' (uppercase would give U+01C4).

**Conversion semantics (important):** all mappings are *simple* (1:1). There
is no case-expansion — e.g. U+00DF 'ß' stays U+00DF under `toupper`
(no "SS"), and U+0130 'İ' maps to U+0069 'i' (losing the combining dot).
Out-of-range inputs are returned unchanged (no crash, no wrap).

## 4. Performance Characteristics

- **Classification:** O(1) per code point for every predicate. Bitmap-based
  predicates (letter, uppercase, lowercase, capitalized, alphanumeric,
  decomposable, legalcharacter, nonbase, punctuation, symbol,
  identifierstart, identifiercontinuation) resolve through a generated
  three-level sparse trie (plane → miniplane → byte/bit). Switch-based
  predicates (control, newline, whitespace, whitespaceornewline, zerodigit,
  decimaldigit) are small generated `switch` statements.
- **Conversion:** O(1) generated `switch` lookups over the UTF-16 and UTF-32
  tables.
- **Input guards:** the 32-bit predicates add a cheap range check
  (`< 0 || > 0x10FFFF → return 0`) before lookup; this does not change the
  asymptotic cost.
- **Memory:** the generated data (bitmaps + switch tables) is compact; the
  whole library compiles to roughly 256KB.
- **Concurrency:** all functions are pure and stateless — fully thread-safe,
  no allocation, no global mutable state.

## 5. AI Usage Recommendations & Patterns

### Best Practices

- Validate untrusted input with `mulle_unicode_is_legalcharacter` first; since
  2.4.14 it accurately excludes surrogates and noncharacters.
- Use the `int32_t` variants for anything that may contain supplementary
  planes; the `uint16_t` variants cannot represent them (BMP only).
- Use the `*plane( unsigned int)` functions as a fast pre-filter before doing
  per-character lookups over a large block, e.g.
  `if( mulle_unicode_is_letterplane( c >> 16))`.
- For digit values use `c - mulle_unicode_is_zerodigit( zero)` after checking
  both `is_zerodigit(zero)` and `is_decimaldigit(digit)`.
- Use `is_identifierstart` + `is_identifiercontinuation` for identifier
  validation rather than rolling your own with `is_letter`.
- Use the `_nop` functions when a callback needs a case conversion that does
  nothing.
- Fuzz harnesses exist at `fuzz/fuzz-ctype` and `fuzz/fuzz-conversion` if you
  want to validate your own assumptions against the data.

### Common Pitfalls

- **No `is_digit` / `isprint` functions exist.** Use `is_decimaldigit`,
  `is_zerodigit`, `is_control`, `is_symbol`, etc.
- **`is_letter` includes combining marks** (`M.`), so "letter" is broader than
  you may expect; `is_identifierstart` does **not** include marks.
- **`is_noncharacter` returns 1 for surrogates** (U+D800–U+DFFF) whereas
  `is_legalcharacter` returns 0 for them — do not treat the two as opposites.
- **Simple case mapping only:** `toupper(U+00DF)` does not produce "SS";
  `tolower(U+0130)` loses the dot. For case-insensitive comparison implement
  proper case folding instead.
- **`is_control` is not the complement of `isprint`:** U+0000 and U+2028 are
  not classified as control.
- **UTF-16 variants cannot express supplementary characters**; feeding a UTF-16
  surrogate pair to `mulle_unicode16_*` is meaningless.

### Idiomatic Usage

```c
// classify one code point with a plane pre-check
int   c;
int   is_symbol;

c         = 0x1F600;   // 😀
is_symbol = mulle_unicode_is_symbolplane( c >> 16)
            && mulle_unicode_is_symbol( c);
```

## 6. Integration Examples

Style follows the library: 3-space indent, Allman braces, aligned
declarations, C89 variable rules, and `return( expr);`.

### Example 1: Character Classification Loop

```c
#include <mulle-unicode/mulle-unicode.h>
#include <stdio.h>


int   main( void)
{
   int32_t   chars[ 6];
   int32_t   c;
   int       i;

   chars[ 0] = 'A';
   chars[ 1] = 'a';
   chars[ 2] = '1';
   chars[ 3] = ' ';
   chars[ 4] = 0x00C9;   // É
   chars[ 5] = 0x03B1;   // α Greek alpha

   for( i = 0; i < 6; i++)
   {
      c = chars[ i];
      printf( "U+%04X: ", c);
      if( mulle_unicode_is_letter( c))
         printf( "LETTER ");
      if( mulle_unicode_is_decimaldigit( c))
         printf( "DIGIT ");
      if( mulle_unicode_is_whitespace( c))
         printf( "WHITESPACE ");
      if( mulle_unicode_is_punctuation( c))
         printf( "PUNCT ");
      printf( "\n");
   }
   return( 0);
}
```

### Example 2: Case Conversion Including Titlecase

```c
#include <mulle-unicode/mulle-unicode.h>
#include <stdio.h>


int   main( void)
{
   int32_t   d;

   d = mulle_unicode_toupper( 'z');         // 'Z'
   d = mulle_unicode_tolower( 0x1E9E);      // ẞ -> ß
   d = mulle_unicode_totitlecase( 0x01C6);  // dž -> Dž (U+01C5)
   d = mulle_unicode_toupper( 0x10428);     // Deseret small long i -> U+10400

   printf( "%#x\n", d);
   return( 0);
}
```

### Example 3: Identifier Validation

```c
#include <mulle-unicode/mulle-unicode.h>
#include <stdio.h>


static int   is_identifier( int32_t *chars, int len)
{
   int   i;

   if( len <= 0)
      return( 0);
   if( ! mulle_unicode_is_identifierstart( chars[ 0]))
      return( 0);
   for( i = 1; i < len; i++)
      if( ! mulle_unicode_is_identifiercontinuation( chars[ i]))
         return( 0);
   return( 1);
}


int   main( void)
{
   int32_t   name[ 3];

   name[ 0] = '_';   // underscore is NOT an identifier start
   name[ 1] = 'v';
   name[ 2] = '1';
   printf( "_v1 %s valid\n", is_identifier( name, 3) ? "is" : "is not");

   name[ 0] = 'v';
   name[ 1] = '1';
   printf( "v1 %s valid\n", is_identifier( name, 2) ? "is" : "is not");
   return( 0);
}
```

### Example 4: Digit Value Extraction with zerodigit

```c
#include <mulle-unicode/mulle-unicode.h>
#include <stdio.h>


int   main( void)
{
   int32_t   zero;
   int32_t   digit;
   int       value;

   zero  = 0x0660;   // ٠ Arabic-Indic zero
   digit = 0x0669;   // ٩ Arabic-Indic nine

   if( mulle_unicode_is_zerodigit( zero) && mulle_unicode_is_decimaldigit( digit))
   {
      value = digit - zero;   // 9
      printf( "value: %d\n", value);
   }
   return( 0);
}
```

### Example 5: Plane Pre-check and Legal Character Validation

```c
#include <mulle-unicode/mulle-unicode.h>
#include <stdio.h>


int   main( void)
{
   int32_t   c;

   c = 0x1F600;  // 😀
   if( mulle_unicode_is_legalcharacter( c))
      if( mulle_unicode_is_symbolplane( c >> 16) && mulle_unicode_is_symbol( c))
         printf( "U+%X is a symbol\n", c);

   // surrogates are not legal characters since 2.4.14
   printf( "surrogate legal: %d\n", mulle_unicode_is_legalcharacter( 0xD800));
   return( 0);
}
```

### Example 6: UTF-16 (BMP) Processing

```c
#include <mulle-unicode/mulle-unicode.h>
#include <stdio.h>


int   main( void)
{
   uint16_t   text[ 4];
   uint16_t   c;
   int        i;

   text[ 0] = 'H';
   text[ 1] = 'i';
   text[ 2] = 0x00E9;   // é
   text[ 3] = '!';

   for( i = 0; i < 4; i++)
   {
      c = text[ i];
      printf( "U+%04X", c);
      if( mulle_unicode16_is_lowercase( c))
         printf( " LOWER");
      printf( " -> upper U+%04X\n", mulle_unicode16_toupper( c));
   }
   return( 0);
}
```

## 7. Dependencies

Direct mulle-sde dependencies (see `.mulle/etc/sourcetree/config`):

- `mulle-c11` (minimum version 4.9.0 per `_mulle-unicode-versioncheck.h`):
  cross-platform compiler glue macros (`MULLE_C_GLOBAL`,
  `MULLE_C_EXTERN_GLOBAL`, `MULLE_C_UNUSED`).

Only used at build time (no other library is linked at runtime).

## 8. Revision Note

The previous `index.md` was last committed as `ddc01b3` (2026-08-04). This
revision incorporates the API-behavior changes from commit `946c064`
"fix: harden ctype predicates against invalid inputs and exclude surrogates"
and `6b72e6d`:

- predicates now return `0` for out-of-range inputs (negative or > U+10FFFF)
- `is_legalcharacter` rejects surrogates U+D800–U+DFFF
- `totitlecase` covers the full 32-bit range including supplementary planes
- version bumped to 2.4.14; Unicode data tables regenerated from Unicode 12.1
- fuzz targets `fuzz-ctype` / `fuzz-conversion` added

Behavior notes were verified by compiling the released sources.