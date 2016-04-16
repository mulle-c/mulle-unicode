//
//  mulle_utf_is_capitalized.h
//  mulle-utf
//
//  Created by Nat! on 2016-04-15 17:24:35 +0200.
//  Copyright © 2016 Mulle kybernetiK. All rights reserved.
//

#include "mulle_utf_is_capitalized.h"


int   mulle_utf16_is_capitalized( mulle_utf16char_t c)
{
   switch( c)
   {
#include "unicode/iscapitalized-utf16.inc"
      return( 1);
   }
   return( 0);

}


int   mulle_utf32_is_capitalized( mulle_utf32char_t c)
{
   return( mulle_utf16_is_capitalized( (mulle_utf16char_t) c));
}


int   mulle_utf_is_capitalizedplane( unsigned int plane)
{
   switch( plane)
   {
   case 0 :
      return( 1);
   }
   return( 0);
}
