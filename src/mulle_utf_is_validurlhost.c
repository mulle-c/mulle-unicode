//
//  mulle_utf_is_validurlhost.h
//  mulle-utf
//
//  Created by Nat! on 2016-04-15 17:24:35 +0200.
//  Copyright © 2016 Mulle kybernetiK. All rights reserved.
//

#include "mulle_utf_is_validurlhost.h"


int   mulle_utf16_is_validurlhost( mulle_utf16_t c)
{
   switch( c)
   {
   case 0x0022 :
   case 0x0023 :
   case 0x0025 :
   case 0x002f :
   case 0x003c :
   case 0x003e :
   case 0x003f :
   case 0x0040 :
   case 0x005c :
   case 0x005e :
   case 0x0060 :
   case 0x007b :
   case 0x007c :
   case 0x007d :
      return( 1);
   }
   return( 0);

}


int   mulle_utf32_is_validurlhost( mulle_utf32_t c)
{
   return( mulle_utf16_is_validurlhost( (mulle_utf16_t) c));
}


int   mulle_utf_is_validurlhostplane( unsigned int plane)
{
   switch( plane)
   {
   case 0 :
      return( 1);
   }
   return( 0);
}
