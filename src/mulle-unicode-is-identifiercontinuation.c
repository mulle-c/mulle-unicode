//
//  mulle-unicode-is-identifiercontinuation.c
//  mulle-unicode
//
//  Copyright (c) 2023 Nat! - Mulle kybernetiK.
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
#include "mulle-unicode-is-identifiercontinuation.h"

#include "include-private.h"

#include "miniplane.h"
#include "isidentifiercontinuation-bitmap.inc"

#include <assert.h>


int   mulle_unicode_is_identifiercontinuation( int32_t c)
{
   int   flag;

   flag = is_member_of_planes( planes, c);
   if( flag)
   {
      // https://www.unicode.org/reports/tr31/#R3
      assert( c < 0xA || c > 0xD);
      assert( c != 0x85);
      assert( c != 0x2028);
      assert( c != 0x2029);

      assert( c != 0x061C);
      assert( c < 0x2066 || c > 0x2069);
      assert( c < 0x202A || c > 0x202F);
   }
   return( flag);
}


int   mulle_unicode16_is_identifiercontinuation( uint16_t c)
{
   return( mulle_unicode_is_identifiercontinuation( c));
}


int   mulle_unicode_is_identifiercontinuationplane( unsigned int plane)
{
   if( plane >= 0x11)
      return( 0);
   return( planes[ plane] != _PLANE_NULL);
}
