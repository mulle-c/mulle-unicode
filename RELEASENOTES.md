### 2.4.15


* Document `mulle-unicode-is-ascii.h` ASCII-only classification predicates `(`is_asciidigit`,` ``is_asciiuppercase`,` ``is_asciilowercase`,` ``is_asciiletter`,` ``is_asciispace`,` ``is_asciiidentifierstart`,` ``is_asciiidentifiercontinuation`)`
* Explain that these are deliberate ASCII-only counterparts, not drop-in replacements for the Unicode-aware predicates



feature: add ASCII-only character classification predicates

* new `mulle-unicode-is-ascii.h` header with ASCII-only counterparts to the Unicode-aware classifiers
* add ``mulle_unicode_is_asciidigit`,` ``mulle_unicode_is_asciiuppercase`,` ``mulle_unicode_is_asciilowercase`,` ``mulle_unicode_is_asciiletter`,` ``mulle_unicode_is_asciispace``
* add ``mulle_unicode_is_asciiidentifierstart`` `(`[A-Za-z_]`)` and ``mulle_unicode_is_asciiidentifiercontinuation`` `(`[A-Za-z0-9_]`)` for lexer/parser alphabets
* also exposed through `mulle-unicode.h` and `mulle-unicode-ctype.h`

### 2.4.14





* ``is_legalcharacter`` now rejects surrogates (U+D800–U+DFFF), which are encoding artifacts, not Unicode scalar values
* ``is_noncharacter`` and the other ``is_*`` predicates now return 0 for negative or > U+10FFFF inputs instead of wrapping into the BMP or misreporting
* `totitlecase` now maps the full 32-bit code point range including supplementary planes (previously BMP-only)

### 2.4.13

Various small improvements
