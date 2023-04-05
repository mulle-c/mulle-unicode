//
//  mulle_unicode_is_whitespaceornewline.h
//  mulle-unicode
//
//  Created by Nat! on 2016-04-15 17:24:35 +0200.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#include "mulle-unicode-is-whitespaceornewline.h"


int   mulle_unicode16_is_whitespaceornewline( uint16_t c)
{
   switch( c)
   {
   case 0x0009 :
   case 0x000a :
   case 0x000b :
   case 0x000c :
   case 0x000d :
   case 0x0085 :
#include "iswhitespace-utf16.inc"
      return( 1);
   }
   return( 0);

}


int   mulle_unicode_is_whitespaceornewline( int32_t c)
{
   if( c <= 0xFFFF)
      return( mulle_unicode16_is_whitespaceornewline( (uint16_t) c));
   return( 0);
}


int   mulle_unicode_is_whitespaceornewlineplane( unsigned int plane)
{
   switch( plane)
   {
   case 0 :
      return( 1);
   }
   return( 0);
}
