# mulle-unicode

#### 🈚 Unicode ctype like library

a C (C99) library to classify and convert unicode characters, based on the
Unicode 3.0.0 specification.
The library uses the Unicode specification data to create C code.
mulle-unicode is fairly compact for what it does, compiling down to around
256KB.


| Release Version                                       | Release Notes
|-------------------------------------------------------|--------------
| ![Mulle kybernetiK tag](https://img.shields.io/github/tag/mulle-c/mulle-unicode.svg?branch=release) [![Build Status](https://github.com/mulle-c/mulle-unicode/workflows/CI/badge.svg?branch=release)](//github.com/mulle-c/mulle-unicode/actions)| [RELEASENOTES](RELEASENOTES.md) |


## API

| File                             | Description
|----------------------------------| ----------------------------------------
| [`Ctype`](dox/API_CTYPE.md)      | `<ctype.h>` like functionality for UTF32 and UTF16 strings
| [`Conversion`](dox/API_CTYPE.md) | Converting strings back and forth




### You are here

![Overview](overview.dot.svg)





## Add

Use [mulle-sde](//github.com/mulle-sde) to add mulle-unicode to your project:

``` sh
mulle-sde add github:mulle-c/mulle-unicode
```

To only add the sources of mulle-unicode with dependency
sources use [clib](https://github.com/clibs/clib):


``` sh
clib install --out src/mulle-c mulle-c/mulle-unicode
```

Add `-isystem src/mulle-c` to your `CFLAGS` and compile all the sources that were downloaded with your project.


## Install

### Install with mulle-sde

Use [mulle-sde](//github.com/mulle-sde) to build and install mulle-unicode and all dependencies:

``` sh
mulle-sde install --prefix /usr/local \
   https://github.com/mulle-c/mulle-unicode/archive/latest.tar.gz
```

### Manual Installation

Install the requirements:

| Requirements                                 | Description
|----------------------------------------------|-----------------------
| [mulle-c11](https://github.com/mulle-c/mulle-c11)             | 🔀 Cross-platform C compiler glue (and some cpp conveniences)

Install **mulle-unicode** into `/usr/local` with [cmake](https://cmake.org):

``` sh
cmake -B build \
      -DCMAKE_INSTALL_PREFIX=/usr/local \
      -DCMAKE_PREFIX_PATH=/usr/local \
      -DCMAKE_BUILD_TYPE=Release &&
cmake --build build --config Release &&
cmake --install build --config Release
```


## Author

[Nat!](https://mulle-kybernetik.com/weblog) for Mulle kybernetiK



