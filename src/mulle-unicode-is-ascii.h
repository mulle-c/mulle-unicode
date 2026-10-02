//
//  mulle-unicode-is-ascii.h
//  mulle-unicode
//
//  Copyright (c) 2026 Nat! - Mulle kybernetiK.
//  All rights reserved.
//
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are met:
//
//  Redistributions of source code must retain the above copyright notice, this
//  list of conditions and the following disclaimer.
//
//  Redistributions in binary form must reproduce the above copyright notice,
//  this list of conditions and the following disclaimer in the documentation
//  and/or other materials provided with the distribution.
//
//  Neither the name of Mulle kybernetiK nor the names of its contributors
//  may be used to endorse or promote products derived from this software
//  without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
//  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
//  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
//  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
//  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
//  POSSIBILITY OF SUCH DAMAGE.
//
//  The ASCII-only counterparts of the classification predicates. A parser's
//  alphabet is usually ASCII *on purpose* - a cmake command name is
//  [A-Za-z_], not "a Unicode letter" - and the difference is silent:
//  mulle_unicode_is_letter() answers yes for a great many codepoints that
//  [A-Za-z] does not match, so a Unicode-aware predicate is not a drop-in.
//
//  The `ascii` in the name is the guard: these must not be substituted for
//  the Unicode-aware functions without deciding that is what is meant.
//
//  `is_asciispace` is the whitespace of a lexer - space, tab, newline, CR,
//  form feed, vertical tab - and deliberately not isspace() and not
//  mulle_unicode_is_whitespace(), which also match Unicode whitespace such as
//  NBSP.
//
#ifndef mulle_unicode_is_ascii_h__
#define mulle_unicode_is_ascii_h__

#include "include.h"
#include <stdint.h>


static inline int   mulle_unicode_is_asciidigit( int32_t c)
{
   return( c >= '0' && c <= '9');
}


static inline int   mulle_unicode_is_asciiuppercase( int32_t c)
{
   return( c >= 'A' && c <= 'Z');
}


static inline int   mulle_unicode_is_asciilowercase( int32_t c)
{
   return( c >= 'a' && c <= 'z');
}


static inline int   mulle_unicode_is_asciiletter( int32_t c)
{
   return( mulle_unicode_is_asciiuppercase( c) ||
           mulle_unicode_is_asciilowercase( c));
}


static inline int   mulle_unicode_is_asciispace( int32_t c)
{
   switch( c)
   {
   case ' '  :
   case '\t' :
   case '\n' :
   case '\r' :
   case '\f' :
   case '\v' : return( 1);
   }
   return( 0);
}


// [A-Za-z_]
static inline int   mulle_unicode_is_asciiidentifierstart( int32_t c)
{
   return( mulle_unicode_is_asciiletter( c) || c == '_');
}


// [A-Za-z0-9_]
static inline int   mulle_unicode_is_asciiidentifiercontinuation( int32_t c)
{
   return( mulle_unicode_is_asciiidentifierstart( c) ||
           mulle_unicode_is_asciidigit( c));
}

#endif
