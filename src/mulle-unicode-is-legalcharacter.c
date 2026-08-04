//
//  mulle-unicode-is-legalcharacter.c
//  mulle-unicode
//
//  Copyright (c) 2020 Nat! - Mulle kybernetiK.
//  Copyright (c) 2019 Codeon GmbH.
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
#include "mulle-unicode-is-legalcharacter.h"

#include "miniplane.h"

#include "islegal-bitmap.inc"


int   mulle_unicode_is_legalcharacter( int32_t c)
{
   unsigned int    i;
   unsigned char   **plane;
   unsigned char   *miniplane;
   unsigned char   byte;
   int32_t         x;

   /* get plane */
   i = c >> 16;
   if( i >= 0x11)
      return( 0);
   plane = planes[ i];
   if( ! plane)
      return( 0);
   x = c & 0xFFFF;

   /* get miniplane */
   miniplane = plane[ x >> (7 + 3)];
   if( is_special_miniplane( miniplane))
      return( (miniplane == _MINIPLANE_CLR) ? 0 : 1);
   x &= 0x3FF;

   /* get byte */
   byte = miniplane[ x >> 3];
   x   &= 0x7;

   /* get bit */
   if( (1U << x) & byte)
      return( 1);
   return( 0);
}


int   mulle_unicode16_is_legalcharacter( uint16_t c)
{
   return( mulle_unicode_is_legalcharacter( c));
}


int   mulle_unicode_is_legalcharacterplane( unsigned int plane)
{
   if( plane >= 0x11)
      return( 0);
   return( planes[ plane] != _PLANE_NULL);
}
