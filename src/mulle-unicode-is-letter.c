//
//  mulle_unicode_is_letter.h
//  mulle-unicode
//
//  Created by Nat! on 2016-04-15 17:24:35 +0200.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#include "mulle-unicode-is-letter.h"
#include "mulle-unicode-is-noncharacter.h"


int   mulle_unicode16_is_letter( uint16_t c)
{
   if( ! c)
      return( 0);

   switch( c)
   {
#include "unicode/isletter-utf16-inv.inc"
      return( 0);
   }
   return( mulle_unicode16_is_noncharacter( c) ? 0 : 1);
}


int   mulle_unicode_is_letter( int32_t c)
{
   if( c <= 0x7F)
      return( (c >='a' && c <= 'z') || (c >= 'A' && c <= 'Z'));

   if( c <= 0xFFFF)
      return( mulle_unicode16_is_letter( (uint16_t) c));

   if( ! mulle_unicode_is_letterplane( c >> 16))
      return( 0);

   switch( c)
   {
#include "unicode/isletter-utf32-inv.inc"
      return( 0);
   }
   return( mulle_unicode_is_noncharacter( c) ? 0 : 1);
}


int   mulle_unicode_is_letterplane( unsigned int plane)
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
