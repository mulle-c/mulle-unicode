//
//  mulle_unicode_is_privatecharacter.h
//  mulle-unicode
//
//  Created by Nat! on 15.04.16.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//

#ifndef mulle_unicode_is_privatecharacter_h__
#define mulle_unicode_is_privatecharacter_h__

#include <stdint.h>
int   mulle_unicode16_is_privatecharacter( uint16_t c);
int   mulle_unicode_is_privatecharacter( int32_t c);
int   mulle_unicode_is_privatecharacterplane( unsigned int plane);

#endif /* mulle_unicode_is_privatecharacter_h */
