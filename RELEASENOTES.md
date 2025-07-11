### 2.4.10

Various small improvements

### 2.4.9

Various small improvements

### 2.4.8

Various small improvements

### 2.4.7

* added isidentifiercontinuation and isidentifierstart queries to parse unicode identifiers

### 2.4.6

* remove package.json as it conflicts with clib.json

### 2.4.5

* Various small improvements

### 2.4.4

* GLOBAL change for Windows

### 2.4.3

* Various small improvements

### 2.4.1

* Various small improvements

## 2.4.0

* updated project for github actions etc.
* move http validation functions to mulle-http
* remove files belonging to mulle-url now
* improve library binary size and speed, by replacing large cases with bitmaps
* speed up some functions for ASCII greatly, with relative little cost for the rest of unicode

### 2.3.3

* remove files belonging to mulle-url now

### 2.3.2

* sent privatecharacter back to mulle-utf

### 2.3.1

* add missing inc files, don't install inc files though

## 2.2.0

* added `mulle_unicode8_strnstr`, `mulle_unicode8_strnchr`, `mulle_unicode8_strnspn`, `mulle_unicode8_strncspn`
* add rover functionality to step through UTF strings
* added a longlong ascii conversion


## 2.1.0

* added `mulle_unicode…_nop` functions for nop callbacks
* added `_mulle_unicode32_as_utf8` for quick conversions w/o error checks
* struct `mulle_unicode8_data` added
* updated to Unicode 12.1
* added legal characterset, though its pretty large
* fixed a lot of bugs with respect to charactersets


### 2.0.11

* modernized mulle-sde
* Added a check for NULL pointer input

### 2.0.10

* modernized to mulle-sde with .mulle folder

### 2.0.9

* use memmove in a strategic place

### 2.0.8

* upgrade to newest mulle-sde

### 2.0.7

* fix a linux warning about strnlen the hard way

### 2.0.6

* remove obsolete file

### 2.0.5

* fix mingw, update sde

### 2.0.4

* Various small improvements

### 2.0.3

* modernized mulle-sde

### 2.0.2

* fix missing eval

### 2.0.1

* fix travis.yml

# 2.0.0

* migrated to mulle-sde
* made headernames hyphenated
* no longer distributed as a homebrew package


### 1.1.13

* migrate to mulle-project
* fix glaring regression in mulle_unicode8_information

### 1.1.11

* don't use failing extrachar function in information routine

### 1.1.9

* support new mulle-tests

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
* allow len to be passed as -1 to `mulle_unicode<>_information` for convenience.


0.4
===

* Unify all utf8/16/32_info structs into one `mulle_unicode_information`.
* added mulle_unicode_is_validurlscheme.h


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

* renamed mulle_unicode8char_t and friends to mulle_unicode8_t
