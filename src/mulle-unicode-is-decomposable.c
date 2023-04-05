//
//  mulle_unicode_is_decomposable.h
//  mulle-unicode
//
//  Created by Nat! on 2016-04-15 17:24:35 +0200.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#include "mulle-unicode-is-decomposable.h"

#include "miniplane.h"

#include "isdecomposable-bitmap.inc"


int   mulle_unicode_is_decomposable( int32_t c)
{
   return( is_member_of_planes( planes, c));
}


int   mulle_unicode16_is_decomposable( uint16_t c)
{
   return( mulle_unicode_is_decomposable( c));
}


int   mulle_unicode_is_decomposableplane( unsigned int plane)
{
   if( plane >= 0x11)
      return( 0);
   return( planes[ plane] != _PLANE_NULL);
}

