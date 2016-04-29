//
//  mulle_utf_toupper.c
//  mulle-utf
//
//  Created by Nat! on 16.04.16.
//  Copyright © 2016 Mulle kybernetiK. All rights reserved.
//

#include "mulle_utf_toupper.h"


int   mulle_utf16_toupper( mulle_utf16_t c)
{
   switch( c)
   {
#include "unicode/toupper-utf16.inc"
   }
   return( c);
}


int   mulle_utf32_toupper( mulle_utf32_t c)
{
   if( c <= 0xFFFF)
      return( mulle_utf16_toupper( (mulle_utf16_t) c));
   
   switch( c)
   {
#include "unicode/toupper-utf32.inc"
   }
   return( c);
}


// diff with to upper
int   mulle_utf16_totitlecase( mulle_utf16_t c)
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
   return( mulle_utf16_toupper( c));
}


int   mulle_utf32_totitlecase( mulle_utf32_t c)
{
   return( mulle_utf16_totitlecase( (mulle_utf16_t) c));
}


