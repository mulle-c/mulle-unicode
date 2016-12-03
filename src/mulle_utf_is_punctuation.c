//
//  mulle_utf_is_punctuation.h
//  mulle-utf
//
//  Created by Nat! on 2016-04-15 17:24:35 +0200.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#include "mulle_utf_is_punctuation.h"


int   mulle_utf16_is_punctuation( mulle_utf16_t c)
{
   switch( c)
   {
#include "unicode/ispunctuation-utf16.inc"
      return( 1);
   }
   return( 0);

}


int   mulle_utf32_is_punctuation( mulle_utf32_t c)
{
   if( c <= 0xFFFF)
      return( mulle_utf16_is_punctuation( (mulle_utf16_t) c));

   switch( c)
   {
#include "unicode/ispunctuation-utf32.inc"
      return( 1);
   }
   return( 0);
}


int   mulle_utf_is_punctuationplane( unsigned int plane)
{
   switch( plane)
   {
   case 0 :
   case 1 :
      return( 1);
   }
   return( 0);
}
