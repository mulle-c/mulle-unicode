//
//  mulle_unicode_is_control.h
//  mulle-unicode
//
//  Created by Nat! on 2016-04-15 17:24:35 +0200.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#include "mulle-unicode-is-control.h"


int   mulle_unicode16_is_control( uint16_t c)
{
   switch( c)
   {
#include "unicode/iscontrol-utf16.inc"
      return( 1);
   }
   return( 0);

}


int   mulle_unicode_is_control( int32_t c)
{
   if( c <= 0xFFFF)
      return( mulle_unicode16_is_control( (uint16_t) c));

   switch( c)
   {
#include "unicode/iscontrol-utf32.inc"
      return( 1);
   }

   return( 0);
}


int   mulle_unicode_is_controlplane( unsigned int plane)
{
   switch( plane)
   {
   case 0 :
   case 1 :
   case 14 :
      return( 1);
   }
   return( 0);
}
