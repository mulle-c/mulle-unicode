//
//  mulle_unicode_is_legalcharacter.c
//  mulle-unicode
//
//  Created by Nat! on 06.06.19
//  Copyright © 2019 Mulle kybernetiK.
//  Copyright (c) 2019 Codeon GmbH.
//  All rights reserved.
//

#include "mulle-unicode-is-legalcharacter.h"

#include "miniplane.h"

#include "islegal-bitmap.inc"


int   mulle_unicode_is_legalcharacter( int32_t c)
{
   unsigned int    i;
   unsigned char   **plane;
   unsigned char   *miniplane;
   unsigned char   byte;
   int32_t         x;

   /* get plane */
   i = c >> 16;
   if( i >= 0x11)
      return( 0);
   plane = planes[ i];
   if( ! plane)
      return( 0);
   x = c & 0xFFFF;

   /* get miniplane */
   miniplane = plane[ x >> (7 + 3)];
   if( is_special_miniplane( miniplane))
      return( (miniplane == _MINIPLANE_CLR) ? 0 : 1);
   x &= 0x3FF;

   /* get byte */
   byte = miniplane[ x >> 3];
   x   &= 0x7;

   /* get bit */
   if( (1U << x) & byte)
      return( 1);
   return( 0);
}


int   mulle_unicode16_is_legalcharacter( uint16_t c)
{
   return( mulle_unicode_is_legalcharacter( c));
}


int   mulle_unicode_is_legalcharacterplane( unsigned int plane)
{
   if( plane >= 0x11)
      return( 0);
   return( planes[ plane] != _PLANE_NULL);
}
