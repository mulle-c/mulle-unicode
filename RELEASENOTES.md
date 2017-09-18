### 1.1.7

* fixed scion wrapper command

### 1.1.5

* follow mulle-configuration 3.1 changes and move .travis.yml to trusty

### 1.1.3

* fixes for _WIN32

### 1.0.13

* make it a cmake "C" project


### 1.0.11

* modernize project

1.0.9
===

* improve documentation
* fix homebrew formula generation

1.0.7
===

* improve documentation
* consistent errno return value for bufferconvert


1.0.5
===

* improve documentation
* reintroduce bom16 functions

1.0.3
===

* add travis.yml

1.0.1
===

* changed the char5 characterset to match typical Objective-C identifiers
better. Need to update the compiler too.
* redid the API to be more consistent with other projects

0.5.1
===

* improve the documentation somewhat

0.5
===

* incorporated some code from `mulle_regex`, namely those `_string` functions.
* add dependency to `mulle_allocator` for convenience methods
* changed parameter order in bytebuffer conversion functions!
* allow len to be passed as -1 to `mulle_utf<>_information` for convenience.


0.4
===

* Unify all utf8/16/32_info structs into one `mulle_utf_information`.
* added mulle_utf_is_validurlscheme.h


0.3
===

* add routines to iterate over utf8/utf16/utf32 forwards and (!) backwards
* fixed some bugs with respect to surrogate asserts in utf32


0.2
===

* removed BOM check from most routines. It is now expected that you strip
  the BOM away yourself
* added mulle_char5 encoding
* surrogate pairs are considered non-characters in utf32 encoding


0.1
===

* started versioning

* changed the callback scheme to a uniform `add`. This is nice,
  because by default the utf routines will use host order. If you want
  to have flipped output just change the `add`routine.

* renamed mulle_utf8char_t and friends to mulle_utf8_t
