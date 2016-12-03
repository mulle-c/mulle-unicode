//
//  mulle_utf_is_validurluser.h
//  mulle-utf
//
//  Created by Nat! on 2016-05-16 16:34:06 +0200.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#include "mulle_utf_is_validurluser.h"


int   mulle_utf16_is_validurluser( mulle_utf16_t c)
{
   if( c < 0x0021)
      return( 0);

   if( c > 0x007e)
      return( 0);

   switch( c)
   {
   case 0x0022 :
   case 0x0023 :
   case 0x0025 :
   case 0x002f :
   case 0x003a :
   case 0x003c :
   case 0x003e :
   case 0x003f :
   case 0x0040 :
   case 0x005b :
   case 0x005c :
   case 0x005d :
   case 0x005e :
   case 0x0060 :
   case 0x007b :
   case 0x007c :
   case 0x007d :
      return( 0);
   }
   return( 1);

}


int   mulle_utf32_is_validurluser( mulle_utf32_t c)
{
   if( c <= 0xFFFF)
      return( mulle_utf16_is_validurluser( (mulle_utf16_t) c));

   return( 0);
}


int   mulle_utf_is_validurluserplane( unsigned int plane)
{
   switch( plane)
   {
   case 0 :
      return( 1);
   }
   return( 0);
}
