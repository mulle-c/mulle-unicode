//
//  mulle_utf_is_validurlscheme.c
//  mulle-utf
//
//  Created by Nat! on 16.05.16.
//  Copyright © 2016 Mulle kybernetiK. All rights reserved.
//

#include "mulle_utf_is_validurlscheme.h"


int   mulle_utf16_is_validurlscheme( mulle_utf16_t c)
{
   if( c < 0x002b)
      return( 0);

   if( c > 0x007a)
      return( 0);

   switch( c)
   {
   case 0x002c :
   case 0x002f :
   case 0x003a :
   case 0x003b :
   case 0x003c :
   case 0x003d :
   case 0x003e :
   case 0x003f :
   case 0x0040 :
   case 0x005b :
   case 0x005c :
   case 0x005d :
   case 0x005e :
   case 0x005f :
   case 0x0060 :
      return( 0);
   }
   return( 1);
}


int   mulle_utf32_is_validurlscheme( mulle_utf32_t c)
{
   if( c <= 0xFFFF)
      return( mulle_utf16_is_validurlscheme( (mulle_utf16_t) c));

   return( 0);
}


int   mulle_utf_is_validurlschemeplane( unsigned int plane)
{
   switch( plane)
   {
   case 0 :
      return( 1);
   }
   return( 0);
}
