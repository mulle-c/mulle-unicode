//
//  mulle_unicode_is_validurlpath.h
//  mulle-unicode
//
//  Created by Nat! on 2016-05-16 16:34:06 +0200.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#ifndef mulle_unicode_is_validurlpath_h__
#define mulle_unicode_is_validurlpath_h__

#include <stdint.h>

int   mulle_unicode16_is_validurlpath( uint16_t c);
int   mulle_unicode_is_validurlpath( int32_t c);
int   mulle_unicode_is_validurlpathplane( unsigned int plane);

#endif /* mulle_unicode_is_validurlpath_h */