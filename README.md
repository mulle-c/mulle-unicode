# mulle-utf

🔤 UTF8-16-32 analysis, conversion, classification library

a C (C99) library to analyze and convert unicode strings. It also contains some
limited `<string.h>` functionality for UTF16 and UTF32. And it contains some
fairly extensive `<ctype.h>` functionality for UTF16 and UTF32 based on the
Unicode 3.0.0 specification.

It is the backbone of **NSString** and **NSCharacterSet**.


Build Status | Release Version
-------------|-----------------------------------
[![Build Status](https://travis-ci.org/mulle-c/mulle-utf.svg?branch=release)](https://travis-ci.org/mulle-c/mulle-utf) | ![Mulle kybernetiK tag](https://img.shields.io/github/tag/mulle-c/mulle-utf.svg) [![Build Status](https://travis-ci.org/mulle-c/mulle-utf.svg?branch=release)](https://travis-ci.org/mulle-c/mulle-utf)


## Install

Install the prerequisites first:

| Prerequisites                                           |
|---------------------------------------------------------|
| [mulle-allocator](//github.com/mulle-c/mulle-allocator) |

Then build and install

```
mkdir build 2> /dev/null
(
   cd build ;
   cmake .. ;
   make install
)
```

Or let [mulle-sde](//github.com/mulle-sde) do it all for you.


## Encode strings as integers

* **mulle_char5** is a compression scheme, that uses a set of 31 characters
to encode strings into integers of varying sizes. This can be useful for small
strings with typical Objective-C "keys" and small common mostly lowercase words.
* **mulle_char7** is a compression scheme placing 7 bit ASCII characters into
ints of varying sizes. A 64 bit integer can hold up to 8 characters.


> Naming: UTF is a transfer encoding for Unicode. So everything
eventually maps to (32 bit) unicode characters. That operations are done on
UTF directly is kinda questionable, but I believe common.


>> TODO (maybe): split this up into mulle_unicode, mulle_unitype, mulle_utf


## API

File                                    | Description
--------------------------------------- | ----------------------------------------
[`mulle_char7`](dox/API_CHAR7.md)       | Encode small ASCII strings into integers
[`mulle_char5`](dox/API_CHAR5.md)       | Encode some more smallish ASCII strings integers
[`Conversion`](dox/API_CONVERSION.md)   | Convert back and forth between UTF8, UTF16, UTF32,
[`Information`](dox/API_INFORMATION.md) | Analyze and classify string encodings
[`String`](dox/API_STRING.md)           | Primitive UTF16 and UTF32 string handling
[`Ctype`](dox/API_CTYPE.md)             | `<ctype.h>` like functionality for UTF32 and UTF16 strings


### Platforms and Compilers

All platforms and compilers supported by
[mulle-c11](//github.com/mulle-c/mulle-c11) and
[mulle-thread](//github.com/mulle-c/mulle-thread).


## Author

[Nat!](//www.mulle-kybernetik.com/weblog) for
[Mulle kybernetiK](//www.mulle-kybernetik.com) and
[Codeon GmbH](//www.codeon.de)
