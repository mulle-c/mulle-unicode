//
//  mulle_unicode_toupper.h
//  mulle-unicode
//
//  Created by Nat! on 16.04.16.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#ifndef mulle_unicode_toupper_h__
#define mulle_unicode_toupper_h__

#include <stdint.h>

uint16_t   mulle_unicode16_toupper( uint16_t c);
int32_t   mulle_unicode_toupper( int32_t c);

uint16_t   mulle_unicode16_totitlecase( uint16_t c);
int32_t   mulle_unicode_totitlecase( int32_t c);

#endif /* mulle_unicode_toupper_h */
