//
//  mulle_unicode_is_decimaldigit.h
//  mulle-unicode
//
//  Created by Nat! on 2016-04-15 17:24:35 +0200.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#ifndef mulle_unicode_is_decimaldigit_h__
#define mulle_unicode_is_decimaldigit_h__

#include <stdint.h>
#include <assert.h>


int   mulle_unicode16_is_decimaldigit( uint16_t c);
int   mulle_unicode_is_decimaldigit( int32_t c);


static inline int   mulle_unicode_is_decimaldigitplane( unsigned int plane)
{
   switch( plane)
   {
   case 0 :
   case 1 :
      return( 1);
   }
   return( 0);
}

#endif
