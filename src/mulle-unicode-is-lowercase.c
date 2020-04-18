//
//  mulle_unicode_is_lowercase.h
//  mulle-unicode
//
//  Created by Nat! on 2016-04-15 17:24:35 +0200.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#include "mulle-unicode-is-lowercase.h"


int   mulle_unicode16_is_lowercase( uint16_t c)
{
   // common shortcut
   if( c <= 127)
      return( c >= 'a' && c <= 'z');

   switch( c)
   {
#include "unicode/islowercase-utf16.inc"
      return( 1);
   }
   return( 0);

}


int   mulle_unicode_is_lowercase( int32_t c)
{
   if( c <= 0xFFFF)
      return( mulle_unicode16_is_lowercase( (uint16_t) c));

   switch( c)
   {
#include "unicode/islowercase-utf32.inc"
      return( 1);
   }
   return( 0);

}


int   mulle_unicode_is_lowercaseplane( unsigned int plane)
{
   switch( plane)
   {
   case 0 :
   case 1 :
      return( 1);
   }
   return( 0);
}
