//
//  mulle_utf_tolower.c
//  mulle-utf
//
//  Created by Nat! on 16.04.16.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#include "mulle-utf-tolower.h"


mulle_utf16_t   mulle_utf16_nop( mulle_utf16_t c)
{
   return( c);
}


mulle_utf32_t   mulle_utf32_nop( mulle_utf32_t c)
{
   return( c);
}


mulle_utf16_t   mulle_utf16_tolower( mulle_utf16_t c)
{
   switch( c)
   {
#include "unicode/tolower-utf16.inc"
   }
   return( c);
}


mulle_utf32_t   mulle_utf32_tolower( mulle_utf32_t c)
{
   if( c <= 0xFFFF)
      return( mulle_utf16_tolower( (mulle_utf16_t) c));

   switch( c)
   {
#include "unicode/tolower-utf32.inc"
   }
   return( c);
}
