//
// fuzz-conversion.c — fuzz tolower/toupper/totitlecase for safety and
// consistency properties
//
#include "mulle-unicode.h"
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>


int LLVMFuzzerTestOneInput( const uint8_t *data, size_t size)
{
   int32_t    c;
   int32_t    lo, up, title;
   uint16_t   c16;

   if( size < 4)
      return( 0);

   // memcpy to avoid UB on shift into sign bit
   {
      uint32_t raw;
      memcpy( &raw, data, 4);
      c = (int32_t) raw;
   }

   // exercise conversions — must not crash
   lo    = mulle_unicode_tolower( c);
   up    = mulle_unicode_toupper( c);
   title = mulle_unicode_totitlecase( c);

   // idempotence: tolower(tolower(c)) == tolower(c)
   assert( mulle_unicode_tolower( lo) == lo);
   // idempotence: toupper(toupper(c)) == toupper(c)
   assert( mulle_unicode_toupper( up) == up);

   // tolower(toupper(c)) == tolower(c) — holds for most characters but not
   // all (e.g. U+0131 DOTLESS I: toupper -> I, tolower(I) -> i != ı)
   // So we just exercise the call path without asserting equality.
   (void) mulle_unicode_tolower( up);

   // BMP agreement
   if( c >= 0 && c <= 0xFFFF)
   {
      c16 = (uint16_t) c;
      assert( (int32_t) mulle_unicode16_tolower( c16) == lo);
      assert( (int32_t) mulle_unicode16_toupper( c16) == up);
      assert( (int32_t) mulle_unicode16_totitlecase( c16) == title);
   }

   (void) lo; (void) up; (void) title;

   return( 0);
}
