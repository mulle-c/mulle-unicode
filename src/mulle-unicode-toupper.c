//
//  mulle_unicode_toupper.c
//  mulle-unicode
//
//  Created by Nat! on 16.04.16.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#include "mulle-unicode-toupper.h"

#include <ctype.h>


uint16_t   mulle_unicode16_toupper( uint16_t c)
{
   switch( c)
   {
#include "unicode/toupper-utf16.inc"
   }
   return( c);
}


int32_t   mulle_unicode_toupper( int32_t c)
{
   if( c <= 0x7F)
   {
      if( c >= 'a' && c <= 'z')
         return( c - 'a' + 'A');
      return( c);
   }

   if( c <= 0xFFFF)
      return( mulle_unicode16_toupper( (uint16_t) c));

   switch( c)
   {
#include "unicode/toupper-utf32.inc"
   }
   return( c);
}


// diff with to upper
uint16_t   mulle_unicode16_totitlecase( uint16_t c)
{
   switch( c)
   {
   case 0x01c4 : return( 0x01c5);
   case 0x01c5 : return( 0x01c5);
   case 0x01c6 : return( 0x01c5);
   case 0x01c7 : return( 0x01c8);
   case 0x01c8 : return( 0x01c8);
   case 0x01c9 : return( 0x01c8);
   case 0x01ca : return( 0x01cb);
   case 0x01cb : return( 0x01cb);
   case 0x01cc : return( 0x01cb);
   case 0x01f1 : return( 0x01f2);
   case 0x01f2 : return( 0x01f2);
   case 0x01f3 : return( 0x01f2);
   }
   return( mulle_unicode16_toupper( c));
}


int32_t   mulle_unicode_totitlecase( int32_t c)
{
   return( mulle_unicode16_totitlecase( (uint16_t) c));
}


