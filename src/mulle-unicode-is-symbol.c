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

#include "miniplane.h"

#include "issymbol-bitmap.inc"


int   mulle_unicode_is_symbol( int32_t c)
{
   return( is_member_of_planes( planes, c));
}


int   mulle_unicode16_is_symbol( uint16_t c)
{
   return( mulle_unicode_is_symbol( c));
}


int   mulle_unicode_is_symbolplane( unsigned int plane)
{
   if( plane >= 0x11)
      return( 0);
   return( planes[ plane] != _PLANE_NULL);
}
