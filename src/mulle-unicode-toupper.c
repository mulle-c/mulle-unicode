//
//  mulle-unicode-toupper.c
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
#include "mulle-unicode-toupper.h"


uint16_t   mulle_unicode16_toupper( uint16_t c)
{
   switch( c)
   {
#include "toupper-utf16.inc"
   }
   return( c);
}


int32_t   mulle_unicode_toupper( int32_t c)
{
   if( c <= 0x7F)
   {
      if( c >= 'a' && c <= 'z')
         return( c - 'a' + 'A');
      return( c);
   }

   if( c <= 0xFFFF)
      return( mulle_unicode16_toupper( (uint16_t) c));

   switch( c)
   {
#include "toupper-utf32.inc"
   }
   return( c);
}


// diff with to upper
uint16_t   mulle_unicode16_totitlecase( uint16_t c)
{
   switch( c)
   {
   case 0x01c4 : return( 0x01c5);
   case 0x01c5 : return( 0x01c5);
   case 0x01c6 : return( 0x01c5);
   case 0x01c7 : return( 0x01c8);
   case 0x01c8 : return( 0x01c8);
   case 0x01c9 : return( 0x01c8);
   case 0x01ca : return( 0x01cb);
   case 0x01cb : return( 0x01cb);
   case 0x01cc : return( 0x01cb);
   case 0x01f1 : return( 0x01f2);
   case 0x01f2 : return( 0x01f2);
   case 0x01f3 : return( 0x01f2);
   }
   return( mulle_unicode16_toupper( c));
}


int32_t   mulle_unicode_totitlecase( int32_t c)
{
   return( mulle_unicode16_totitlecase( (uint16_t) c));
}


