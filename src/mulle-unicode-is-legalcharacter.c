//
//  mulle_unicode_is_legalcharacter.c
//  mulle-unicode
//
//  Created by Nat! on 06.06.19
//  Copyright © 2019 Mulle kybernetiK.
//  Copyright (c) 2019 Codeon GmbH.
//  All rights reserved.
//

#include "mulle-unicode-is-legalcharacter.h"


int   mulle_unicode16_is_legalcharacter( uint16_t c)
{
   switch( c)
   {
#include "unicode/islegal-utf16.inc"
      return( 1);
   }
   return( 0);

}


int   mulle_unicode_is_legalcharacter( int32_t c)
{
   if( c <= 0xFFFF)
      return( mulle_unicode16_is_legalcharacter( (uint16_t) c));

   switch( c)
   {
#include "unicode/islegal-utf32.inc"
      return( 1);
   }

   return( 0);
}


int   mulle_unicode_is_legalcharacterplane( unsigned int plane)
{
   switch( plane)
   {
   case 0x0  :
   case 0x1  :
   case 0x2  :
   case 0xE  :
   case 0xF  :
   case 0x10 :
      return( 1);
   }
   return( 0);
}
