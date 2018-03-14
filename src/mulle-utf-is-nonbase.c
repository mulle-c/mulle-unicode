//
//  mulle_utf_is_nonbase.h
//  mulle-utf
//
//  Created by Nat! on 2016-04-15 17:24:35 +0200.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#include "mulle-utf-is-nonbase.h"


int   mulle_utf16_is_nonbase( mulle_utf16_t c)
{
   if( c < 0x0300)
      return( 0);

   if( c > 0xfe2d)
      return( 0);

   switch( c)
   {
#include "unicode/isnonbase-utf16.inc"
      return( 1);
   }
   return( 0);

}


int   mulle_utf32_is_nonbase( mulle_utf32_t c)
{
   if( c <= 0xFFFF)
      return( mulle_utf16_is_nonbase( (mulle_utf16_t) c));

   switch( c)
   {
#include "unicode/isnonbase-utf32.inc"
      return( 1);
   }
   return( 0);
}


int   mulle_utf_is_nonbaseplane( unsigned int plane)
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
