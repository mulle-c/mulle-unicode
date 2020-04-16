//
//  mulle_unicode_is_whitespace.h
//  mulle-unicode
//
//  Created by Nat! on 2016-04-15 17:24:36 +0200.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#include "mulle-unicode-is-whitespace.h"


int   mulle_unicode16_is_whitespace( uint16_t c)
{
   switch( c)
   {
   case 0x0009 :
#include "unicode/iswhitespace-utf16.inc"
      return( 1);
   }
   return( 0);

}


int   mulle_unicode_is_whitespace( int32_t c)
{
   if( c <= 0xFFFF)
      return( mulle_unicode16_is_whitespace( (uint16_t) c));
   return( 0);
}


int   mulle_unicode_is_whitespaceplane( unsigned int plane)
{
   return( plane == 0);
}
