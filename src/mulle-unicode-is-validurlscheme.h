//
//  mulle_unicode8_is_validurlscheme.h
//  mulle-unicode
//
//  Created by Nat! on 16.05.16.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#ifndef mulle_unicode_is_validurlscheme_h__
#define mulle_unicode_is_validurlscheme_h__

#include <stdint.h>

int   mulle_unicode16_is_validurlscheme( uint16_t c);
int   mulle_unicode_is_validurlscheme( int32_t c);
int   mulle_unicode_is_validurlschemeplane( unsigned int plane);

#endif /* mulle_unicode8_is_validurlscheme_h */
