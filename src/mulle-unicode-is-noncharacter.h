//
//  mulle_unicode_noncharacter.h
//  mulle-utf
//
//  Created by Nat! on 15.04.16.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#ifndef mulle_unicode_noncharacter_h__
#define mulle_unicode_noncharacter_h__

#include "include.h"
#include <stdint.h>


MULLE_UNICODE_EXTERN_GLOBAL
int   mulle_unicode16_is_noncharacter( uint16_t c);
MULLE_UNICODE_EXTERN_GLOBAL
int   mulle_unicode_is_noncharacter( int32_t c);
MULLE_UNICODE_EXTERN_GLOBAL
int   mulle_unicode_is_noncharacterplane( unsigned int plane);

#endif /* mulle_unicode_is_alphanumeric_h */
