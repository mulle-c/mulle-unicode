//
//  mulle_unicode_is_symbol.h
//  mulle-unicode
//
//  Created by Nat! on 2016-04-15 17:24:35 +0200.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#include "mulle-unicode-is-symbol.h"


int   mulle_unicode16_is_symbol( uint16_t c)
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


int   mulle_unicode_is_symbol( int32_t c)
{
   if( c <= 0xFFFF)
      return( mulle_unicode16_is_symbol( (uint16_t) c));

   switch( c)
   {
#include "unicode/issymbol-utf32.inc"
      return( 1);
   }
   return( 0);
}


int   mulle_unicode_is_symbolplane( unsigned int plane)
{
   switch( plane)
   {
   case 0 :
   case 1 :
      return( 1);
   }
   return( 0);
}
