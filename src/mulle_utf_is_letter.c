//
//  mulle_utf_is_letter.h
//  mulle-utf
//
//  Created by Nat! on 2016-04-15 17:24:35 +0200.
//  Copyright © 2016 Mulle kybernetiK. All rights reserved.
//

#include "mulle_utf_is_letter.h"


int   mulle_utf16_is_letter( mulle_utf16_t c)
{
   switch( c)
   {
#include "unicode/isletter-utf16-inv.inc"
      return( 0);
   }
   return( 1);
}


int   mulle_utf32_is_letter( mulle_utf32_t c)
{
   if( c <= 0xFFFF)
      return( mulle_utf16_is_letter( (mulle_utf16_t) c));

   switch( c)
   {
#include "unicode/isletter-utf32-inv.inc"
      return( 0);
   }
   return( 1);
}


int   mulle_utf_is_letterplane( unsigned int plane)
{
   switch( plane)
   {
   case 0 :
   case 1 :
   case 2 :
   case 14 :
      return( 1);
   }
   return( 0);
}
