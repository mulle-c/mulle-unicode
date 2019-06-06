//
//  mulle_utf_is_alphanumeric.h
//  mulle-utf
//
//  Created by Nat! on 2016-04-15 17:24:35 +0200.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#include "mulle-utf-is-alphanumeric.h"
#include "mulle-utf-is-noncharacter.h"


// TODO: make this a bitmap
int   mulle_utf16_is_alphanumeric( mulle_utf16_t c)
{
   if( c < 0x0030)
      return( 0);

   if( c > 0xffdc)
      return( 0);

   switch( c)
   {
#include "unicode/isalphanumeric-utf16-inv.inc"
      return( 0);
   }

   return( mulle_utf16_is_noncharacter( c) ? 0 : 1);
}


int   mulle_utf32_is_alphanumeric( mulle_utf32_t c)
{
   if( c <= 0xFFFF)
      return( mulle_utf16_is_alphanumeric( (mulle_utf16_t) c));

   if( ! mulle_utf_is_alphanumericplane( c >> 16))
      return( 0);

   switch( c)
   {
#include "unicode/isalphanumeric-utf32-inv.inc"
      return( 0);
   }
   return( mulle_utf32_is_noncharacter( c) ? 0 : 1);
}


int   mulle_utf_is_alphanumericplane( unsigned int plane)
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
