//
//  mulle_unicode_is_newline.h
//  mulle-unicode
//
//  Created by Nat! on 2016-04-15 17:24:35 +0200.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#ifndef mulle_unicode_is_newline_h__
#define mulle_unicode_is_newline_h__

#include "include.h"
#include <stdint.h>

MULLE_UNICODE_EXTERN_GLOBAL
int   mulle_unicode16_is_newline( uint16_t c);
MULLE_UNICODE_EXTERN_GLOBAL
int   mulle_unicode_is_newline( int32_t c);
MULLE_UNICODE_EXTERN_GLOBAL
int   mulle_unicode_is_newlineplane( unsigned int plane);

#endif /* mulle_unicode_is_newline_h */
