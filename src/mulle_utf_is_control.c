//
//  mulle_utf_is_control.h
//  mulle-utf
//
//  Created by Nat! on 2016-04-15 17:24:35 +0200.
//  Copyright © 2016 Mulle kybernetiK. All rights reserved.
//

#include "mulle_utf_is_control.h"


int   mulle_utf16_is_control( mulle_utf16char_t c)
{
   switch( c)
   {
#include "unicode/iscontrol-utf16.inc"
      return( 1);
   }
   return( 0);

}


int   mulle_utf32_is_control( mulle_utf32char_t c)
{
   if( c <= 0xFFFF)
      return( mulle_utf16_is_control( (mulle_utf16char_t) c));

   switch( c)
   {
#include "unicode/iscontrol-utf32.inc"
      return( 1);
   }

   return( 0);
}


int   mulle_utf_is_controlplane( unsigned int plane)
{
   switch( plane)
   {
   case 0 :
   case 1 :
   case 14 :
      return( 1);
   }
   return( 0);
}
