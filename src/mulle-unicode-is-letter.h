//
//  mulle_unicode_is_letter.h
//  mulle-unicode
//
//  Created by Nat! on 2016-04-15 17:24:35 +0200.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#ifndef mulle_unicode_is_letter_h__
#define mulle_unicode_is_letter_h__

#include <stdint.h>

int   mulle_unicode16_is_letter( uint16_t c);
int   mulle_unicode_is_letter( int32_t c);
int   mulle_unicode_is_letterplane( unsigned int plane);

#endif /* mulle_unicode_is_letter_h */
