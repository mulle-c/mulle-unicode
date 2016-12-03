//
//  mulle_utf_is_symbol.h
//  mulle-utf
//
//  Created by Nat! on 2016-04-15 17:24:35 +0200.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#include "mulle_utf_is_symbol.h"


int   mulle_utf16_is_symbol( mulle_utf16_t c)
{
   if( c < 0x0024)
      return( 0);

   switch( c)
   {
#include "unicode/issymbol-utf16.inc"
      return( 1);
   }
   return( 0);

}


int   mulle_utf32_is_symbol( mulle_utf32_t c)
{
   if( c <= 0xFFFF)
      return( mulle_utf16_is_symbol( (mulle_utf16_t) c));

   switch( c)
   {
#include "unicode/issymbol-utf32.inc"
      return( 1);
   }
   return( 0);
}


int   mulle_utf_is_symbolplane( unsigned int plane)
{
   switch( plane)
   {
   case 0 :
   case 1 :
      return( 1);
   }
   return( 0);
}
