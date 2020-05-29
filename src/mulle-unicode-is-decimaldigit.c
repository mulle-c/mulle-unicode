//
//  mulle_unicode_is_decimaldigit.h
//  mulle-unicode
//
//  Created by Nat! on 2016-04-15 17:24:35 +0200.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#include "mulle-unicode-is-decimaldigit.h"


int   mulle_unicode16_is_decimaldigit( uint16_t c)
{
   switch( c)
   {
#include "unicode/isdecimaldigit-utf16.inc"
      return( 1);
   }
   return( 0);

}


int   mulle_unicode_is_decimaldigit( int32_t c)
{
   if( c <= 0x7F)
      return( c >= '0' && c <= '9');

   if( c <= 0xFFFF)
      return( mulle_unicode16_is_decimaldigit( (uint16_t) c));

   switch( c)
   {
#include "unicode/isdecimaldigit-utf32.inc"
      return( 1);
   }
   return( 0);

}
