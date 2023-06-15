//
//  mulle_unicode_tolower.h
//  mulle-unicode
//
//  Created by Nat! on 16.04.16.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#ifndef mulle_unicode_tolower_h__
#define mulle_unicode_tolower_h__

#include "include.h"
#include <stdint.h>

MULLE__UNICODE_GLOBAL
uint16_t   mulle_unicode16_tolower( uint16_t c);
MULLE__UNICODE_GLOBAL
int32_t    mulle_unicode_tolower( int32_t c);


// sometimes useful for callbacks, returns c unchanged
MULLE__UNICODE_GLOBAL
uint16_t   mulle_unicode16_nop( uint16_t c);
MULLE__UNICODE_GLOBAL
int32_t    mulle_unicode_nop( int32_t c);


#endif /* mulle_unicode_tolower_h */
