//
//  mulle-unicode.h
//  mulle-unicode
//
//  Created by Nat! on 18.03.16.
//  Copyright © 2016 Mulle kybernetiK.
//  Copyright (c) 2016 Codeon GmbH.
//  All rights reserved.
//
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are met:
//
//  Redistributions of source code must retain the above copyright notice, this
//  list of conditions and the following disclaimer.
//
//  Redistributions in binary form must reproduce the above copyright notice,
//  this list of conditions and the following disclaimer in the documentation
//  and/or other materials provided with the distribution.
//
//  Neither the name of Mulle kybernetiK nor the names of its contributors
//  may be used to endorse or promote products derived from this software
//  without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
//  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
//  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
//  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
//  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
//  POSSIBILITY OF SUCH DAMAGE.
//
#ifndef mulle_unicode_h__
#define mulle_unicode_h__

#define MULLE_UNICODE_VERSION  ((2 << 20) | (4 << 8) | 5)

#include "include.h"

#include <stdint.h>

// #include "_mulle-unicode-provide.h"

// manual inclusion of headers, because we don't want to expose all the
// .inc files

#include "mulle-unicode-ctype.h"
#include "mulle-unicode-is-alphanumeric.h"
#include "mulle-unicode-is-capitalized.h"
#include "mulle-unicode-is-control.h"
#include "mulle-unicode-is-decimaldigit.h"
#include "mulle-unicode-is-decomposable.h"
#include "mulle-unicode-is-legalcharacter.h"
#include "mulle-unicode-is-letter.h"
#include "mulle-unicode-is-lowercase.h"
#include "mulle-unicode-is-newline.h"
#include "mulle-unicode-is-nonbase.h"
#include "mulle-unicode-is-noncharacter.h"
#include "mulle-unicode-is-punctuation.h"
#include "mulle-unicode-is-symbol.h"
#include "mulle-unicode-is-uppercase.h"
#include "mulle-unicode-is-whitespace.h"
#include "mulle-unicode-is-whitespaceornewline.h"
#include "mulle-unicode-is-zerodigit.h"
#include "mulle-unicode-tolower.h"
#include "mulle-unicode-toupper.h"

#ifdef __has_include
# if __has_include( "_mulle-unicode-versioncheck.h")
#  include "_mulle-unicode-versioncheck.h"
# endif
#endif


#endif /* mulle_unicode_h */
