//
//  mulle_utf_tolower.c
//  mulle-utf
//
//  Created by Nat! on 16.04.16.
//  Copyright © 2016 Mulle kybernetiK. All rights reserved.
//

#include "mulle_utf_tolower.h"


int   mulle_utf16_tolower( mulle_utf16_t c)
{
   switch( c)
   {
#include "unicode/tolower-utf16.inc"
   }
   return( c);
}


int   mulle_utf32_tolower( mulle_utf32_t c)
{
   if( c <= 0xFFFF)
      return( mulle_utf16_tolower( (mulle_utf16_t) c));
   
   switch( c)
   {
#include "unicode/tolower-utf32.inc"
   }
   return( c);
}
