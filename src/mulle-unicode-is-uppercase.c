//
//  mulle_unicode_is_uppercase.h
//  mulle-unicode
//
//  Created by Nat! on 2016-04-15 17:24:35 +0200.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#include "mulle-unicode-is-uppercase.h"

#include "unicode/miniplane.h"

#include "unicode/isuppercase-bitmap.inc"


int   mulle_unicode_is_uppercase( int32_t c)
{
   // ASCII shortcut
   if( c <= 0x7F)
      return( c >= 'A' && c <= 'Z');

   return( is_member_of_planes( planes, c));
}


int   mulle_unicode16_is_uppercase( uint16_t c)
{
   return( mulle_unicode_is_uppercase( c));
}


int   mulle_unicode_is_uppercaseplane( unsigned int plane)
{
   if( plane >= 0x11)
      return( 0);
   return( planes[ plane] != _PLANE_NULL);
}
