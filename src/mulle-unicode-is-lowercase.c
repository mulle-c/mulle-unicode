//
//  mulle_unicode_is_lowercase.h
//  mulle-unicode
//
//  Created by Nat! on 2016-04-15 17:24:35 +0200.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#include "mulle-unicode-is-lowercase.h"

#include "unicode/miniplane.h"

#include "unicode/islowercase-bitmap.inc"


int   mulle_unicode_is_lowercase( int32_t c)
{
   // ASCII shortcut
   if( c <= 0x7F)
      return( c >= 'a' && c <= 'z');

   return( is_member_of_planes( planes, c));
}


int   mulle_unicode16_is_lowercase( uint16_t c)
{
   return( mulle_unicode_is_lowercase( c));
}


int   mulle_unicode_is_lowercaseplane( unsigned int plane)
{
   if( plane >= 0x11)
      return( 0);
   return( planes[ plane] != _PLANE_NULL);
}

