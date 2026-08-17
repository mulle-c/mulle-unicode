# src/unicode/ — generated Unicode data tables

This directory contains `.inc` files generated from `UnicodeData.txt` (Unicode 12.1)
by the scripts in `unicode/`.

## Two kinds of tables

**Bitmap tables** (`*-bitmap.inc`) — compact three-level sparse tries used by the
actual predicate functions at runtime. These are `#include`d by the `.c` files in
`src/`.

**Switch-statement tables** (`is*-utf16.inc`, `is*-utf32.inc`) — flat `case 0xNNNN :`
lists. These are the *intermediate* representation used to *generate* the bitmaps
(see `unicode/template.c`). They are also useful as a human-readable reference and
as an alternative implementation for platforms where the bitmap lookup is undesirable.

The following switch-statement tables are not currently compiled into the library:

    iscapitalized-utf16.inc
    isdecomposable-utf16.inc    isdecomposable-utf32.inc
    isdigit-utf16.inc           isdigit-utf32.inc
    isidentifiercontinuation-utf16.inc  isidentifiercontinuation-utf32.inc
    isidentifierstart-utf16.inc         isidentifierstart-utf32.inc
    islegal-utf16.inc           islegal-utf32.inc
    islowercase-utf16.inc       islowercase-utf32.inc
    isnonbase-utf16.inc         isnonbase-utf32.inc
    isnumeric-utf16.inc         isnumeric-utf32.inc
    isprivate-utf16.inc         isprivate-utf32.inc
    ispunctuation-utf16.inc     ispunctuation-utf32.inc
    isseparator-utf16.inc
    issymbol-utf16.inc          issymbol-utf32.inc
    isuppercase-utf16.inc       isuppercase-utf32.inc

They are kept intentionally:
- As input for bitmap regeneration (`unicode/create-bitmap.sh` reads them)
- As a readable reference for which code points belong to each set
- As building blocks for future predicates (e.g. `isdigit`, `isnumeric`,
  `isprivate`, `isseparator` have tables but no exported function yet)

The **conversion tables** (`tolower-*.inc`, `toupper-*.inc`, `totitlecase-*.inc`)
are switch-statement tables that *are* compiled — the conversion functions use them
directly since a bitmap cannot encode a mapping.

## Regeneration

See `unicode/create-all.sh`. The workflow is:

    cd unicode
    ./create-all.sh          # produces sets/ and bitmaps/
    ./upgrade-after-create.sh  # copies into src/unicode/
