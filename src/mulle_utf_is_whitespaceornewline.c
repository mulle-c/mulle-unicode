//
//  mulle_utf_is_whitespaceornewline.h
//  mulle-utf
//
//  Created by Nat! on 2016-04-15 17:24:35 +0200.
//  Copyright © 2016 Mulle kybernetiK. All rights reserved.
//

#include "mulle_utf_is_whitespaceornewline.h"


int   mulle_utf16_is_whitespaceornewline( mulle_utf16char_t c)
{
   switch( c)
   {
   case 0x0009 :
   case 0x000a :
   case 0x000b :
   case 0x000c :
   case 0x000d :
   case 0x0085 :
#include "unicode/iswhitespace-utf16.inc"
      return( 1);
   }
   return( 0);

}


int   mulle_utf32_is_whitespaceornewline( mulle_utf32char_t c)
{
  return( mulle_utf16_is_whitespaceornewline( (mulle_utf16char_t) c));
}


int   mulle_utf_is_whitespaceornewlineplane( unsigned int plane)
{
   switch( plane)
   {
   case 0 :
      return( 1);
   }
   return( 0);
}
