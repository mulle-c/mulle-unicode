# mulle-unicode

🈚 Unicode ctype like library

a C (C99) library to convert unicode strings. And it contains some
fairly extensive `<ctype.h>` functionality for UTF16 and UTF32 based on the
Unicode 3.0.0 specification.

The library uses the Unicode specification data to create C code.

It extends **NSCharacterSet**.


Build Status | Release Version
-------------|-----------------------------------
[![Build Status](https://travis-ci.org/mulle-c/mulle-unicode.svg?branch=release)](https://travis-ci.org/mulle-c/mulle-unicode) | ![Mulle kybernetiK tag](https://img.shields.io/github/tag/mulle-c/mulle-unicode.svg) [![Build Status](https://travis-ci.org/mulle-c/mulle-unicode.svg?branch=release)](https://travis-ci.org/mulle-c/mulle-unicode)



## API

File                                    | Description
--------------------------------------- | ----------------------------------------
[`Ctype`](dox/API_CTYPE.md)             | `<ctype.h>` like functionality for UTF32 and UTF16 strings


## Add

Use [mulle-sde](//github.com/mulle-sde) to add mulle-unicode to your project:

```
mulle-sde dependency add --c --github mulle-c mulle-unicode
```

## Install

### mulle-sde

Use [mulle-sde](//github.com/mulle-sde) to build and install mulle-unicode and all dependencies:

```
mulle-sde install --linkorder --prefix /usr/local \
   https://github.com/mulle-c/mulle-unicode/archive/latest.tar.gz
```

### Manual Installation

Install into `/usr/local`:

```
mkdir build 2> /dev/null
(
   cd build ;
   cmake -DCMAKE_INSTALL_PREFIX=/usr/local \
         -DCMAKE_PREFIX_PATH=/usr/local \
         -DCMAKE_BUILD_TYPE=Release .. ;
   make install
)
```

## Platforms and Compilers

All platforms and compilers supported by
[mulle-c11](//github.com/mulle-c/mulle-c11) and
[mulle-thread](//github.com/mulle-c/mulle-thread).


## Author

[Nat!](//www.mulle-kybernetik.com/weblog) for
[Mulle kybernetiK](//www.mulle-kybernetik.com) and
[Codeon GmbH](//www.codeon.de)
