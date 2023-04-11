//
//  mulle_unicode_is_punctuation.h
//  mulle-unicode
//
//  Created by Nat! on 2016-04-15 17:24:35 +0200.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#include "mulle-unicode-is-punctuation.h"

#include "miniplane.h"

#include "ispunctuation-bitmap.inc"


int   mulle_unicode_is_punctuation( int32_t c)
{
   return( is_member_of_planes( planes, c));
}


int   mulle_unicode16_is_punctuation( uint16_t c)
{
   return( mulle_unicode_is_punctuation( c));
}


int   mulle_unicode_is_punctuationplane( unsigned int plane)
{
   if( plane >= 0x11)
      return( 0);
   return( planes[ plane] != _PLANE_NULL);
}
