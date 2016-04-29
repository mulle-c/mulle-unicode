//
//  mulle_utf_is_uppercase.h
//  mulle-utf
//
//  Created by Nat! on 2016-04-15 17:24:35 +0200.
//  Copyright © 2016 Mulle kybernetiK. All rights reserved.
//

#include "mulle_utf_is_uppercase.h"


int   mulle_utf16_is_uppercase( mulle_utf16_t c)
{
   // common shortcut
   if( c <= 127)
      return( c >= 'A' && c <= 'Z');
   
   switch( c)
   {
#include "unicode/isuppercase-utf16.inc"
      return( 1);
   }
   return( 0);
}


int   mulle_utf32_is_uppercase( mulle_utf32_t c)
{
   if( c <= 0xFFFF)
      return( mulle_utf16_is_uppercase( (mulle_utf16_t) c));

   switch( c)
   {
#include "unicode/isuppercase-utf32.inc"
      return( 1);
   }
   return( 0);
}


int   mulle_utf_is_uppercaseplane( unsigned int plane)
{
   switch( plane)
   {
   case 0 :
   case 1 :
      return( 1);
   }
   return( 0);
}
