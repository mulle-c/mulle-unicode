//
//  mulle_utf_is_decomposable.h
//  mulle-utf
//
//  Created by Nat! on 2016-04-15 17:24:35 +0200.
//  Copyright © 2016 Mulle kybernetiK. All rights reserved.
//

#include "mulle_utf_is_decomposable.h"


int   mulle_utf16_is_decomposable( mulle_utf16char_t c)
{
   switch( c)
   {
#include "unicode/isdecomposable-utf16.inc"
      return( 1);
   }
   return( 0);
}


int   mulle_utf32_is_decomposable( mulle_utf32char_t c)
{
   if( c <= 0xFFFF)
      return( mulle_utf16_is_decomposable( (mulle_utf16char_t) c));

   if( c < 0x1109a)
      return( 0);

   if( c > 0x2fa1d)
      return( 0);

   switch( c)
   {
#include "unicode/isdecomposable-utf16.inc"
      return( 1);
   }
   return( 0);
}


int   mulle_utf_is_decomposableplane( unsigned int plane)
{
   switch( plane)
   {
   case 0 :
   case 1 :
   case 2 :
      return( 1);
   }
   return( 0);
}
