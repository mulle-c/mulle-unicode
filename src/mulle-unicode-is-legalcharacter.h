//
//  mulle_unicode_is_legalcharacter.h
//  mulle-unicode
//
//  Created by Nat! on 15.04.16.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#ifndef mulle_unicode_is_legalcharacter_h__
#define mulle_unicode_is_legalcharacter_h__

#include "include.h"
#include <stdint.h>

// all characters defined in the unicode standard

MULLE__UNICODE_GLOBAL
int   mulle_unicode16_is_legalcharacter( uint16_t c);
MULLE__UNICODE_GLOBAL
int   mulle_unicode_is_legalcharacter( int32_t c);
MULLE__UNICODE_GLOBAL
int   mulle_unicode_is_legalcharacterplane( unsigned int plane);

#endif /* mulle_unicode_is_alphanumeric_h */
