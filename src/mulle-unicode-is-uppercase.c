//
//  mulle_unicode_is_uppercase.h
//  mulle-unicode
//
//  Created by Nat! on 2016-04-15 17:24:35 +0200.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#include "mulle-unicode-is-uppercase.h"


int   mulle_unicode16_is_uppercase( uint16_t c)
{
   switch( c)
   {
#include "unicode/isuppercase-utf16.inc"
      return( 1);
   }
   return( 0);
}


int   mulle_unicode_is_uppercase( int32_t c)
{
   // common shortcut
   if( c <= 0x7F)
      return( c >= 'A' && c <= 'Z');

   if( c <= 0xFFFF)
      return( mulle_unicode16_is_uppercase( (uint16_t) c));

   switch( c)
   {
#include "unicode/isuppercase-utf32.inc"
      return( 1);
   }
   return( 0);
}


int   mulle_unicode_is_uppercaseplane( unsigned int plane)
{
   switch( plane)
   {
   case 0 :
   case 1 :
      return( 1);
   }
   return( 0);
}
