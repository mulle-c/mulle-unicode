### 2.4.14





* ``is_legalcharacter`` now rejects surrogates (U+D800–U+DFFF), which are encoding artifacts, not Unicode scalar values
* ``is_noncharacter`` and the other ``is_*`` predicates now return 0 for negative or > U+10FFFF inputs instead of wrapping into the BMP or misreporting
* `totitlecase` now maps the full 32-bit code point range including supplementary planes (previously BMP-only)

### 2.4.13

Various small improvements
