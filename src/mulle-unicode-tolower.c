//
//  mulle_unicode_tolower.c
//  mulle-unicode
//
//  Created by Nat! on 16.04.16.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#include "mulle-unicode-tolower.h"

#include <ctype.h>

uint16_t   mulle_unicode16_nop( uint16_t c)
{
   return( c);
}


int32_t   mulle_unicode_nop( int32_t c)
{
   return( c);
}


uint16_t   mulle_unicode16_tolower( uint16_t c)
{
   switch( c)
   {
#include "unicode/tolower-utf16.inc"
   }
   return( c);
}


int32_t   mulle_unicode_tolower( int32_t c)
{
   if( c <= 0x7F)
   {
      if( c >= 'A' && c <= 'Z')
         return( c - 'A' + 'a');
      return( c);
   }

   if( c <= 0xFFFF)
      return( mulle_unicode16_tolower( (uint16_t) c));

   switch( c)
   {
#include "unicode/tolower-utf32.inc"
   }
   return( c);
}
