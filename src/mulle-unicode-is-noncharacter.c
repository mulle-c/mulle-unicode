//
//  mulle-unicode-is-noncharacter.c
//  mulle-unicode
//
//  Copyright (c) 2020 Nat! - Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
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
#include "mulle-unicode-is-noncharacter.h"


int   mulle_unicode16_is_noncharacter( uint16_t c)
{
   //
   // Die Codebereiche von U+D800 bis U+DBFF (High-Surrogates) und von U+DC00 bis U+DFFF (Low-Surrogates)
   // sind speziell für solche UTF-16-Ersatzzeichen reserviert und enthalten daher keine eigenständigen Zeichen.)
   // surrogates in utf32 ? it's a non-character IMO
   //
   if( c >= 0xD800 && c < 0xE000)
      return( 1);
         // a contiguous range of 32 noncharacters: U+FDD0..U+FDEF in the BMP

   // the last two code points of the BMP, U+FFFE and U+FFFF
   // the last two code points of each of the 16 supplementary planes: U+1FFFE, U+1FFFF, U+2FFFE, U+2FFFF, ... U+10FFFE, U+10FFFF

   if( c >= 0xFDD0 && c <= 0xFDEF)
      return( 1);

   if( c >= 0xfffe /*&& c <= 0xffff*/)
      return( 1);
   return( 0);
}


// Q: Which code points are noncharacters?
int   mulle_unicode_is_noncharacter( int32_t c)
{
   if( c < 0x10000)
   {
      if( c < 0x0FFF)
        return( 0);
      if( mulle_unicode16_is_noncharacter( (uint16_t) c))
         return( 1);
   }

   // above 0x10FFFF is not unicode
   if( c > 0x10FFFF)
      return( 1);

   // the last two code points of the BMP, U+FFFE and U+FFFF
   // the last two code points of each of the 16 supplementary planes: U+1FFFE, U+1FFFF, U+2FFFE, U+2FFFF, ... U+10FFFE, U+10FFFF
   switch( c & 0xffff)
   {
   case 0xfffe  :
   case 0xffff  :
      return( 1);
   }

   return( 0);
}


int   mulle_unicode_is_noncharacterplane( unsigned int plane)
{
   MULLE_C_UNUSED( plane);

   return( 1);
}
