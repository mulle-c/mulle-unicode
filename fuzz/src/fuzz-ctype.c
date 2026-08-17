//
// fuzz-ctype.c — fuzz all is_* predicates for consistency and safety
//
#include "mulle-unicode.h"
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>


int LLVMFuzzerTestOneInput( const uint8_t *data, size_t size)
{
   int32_t   c;
   uint16_t  c16;

   if( size < 4)
      return( 0);

   // memcpy to avoid UB on shift into sign bit
   {
      uint32_t raw;
      memcpy( &raw, data, 4);
      c = (int32_t) raw;
   }

   // exercise all predicates — must not crash on any input
   int alnum   = mulle_unicode_is_alphanumeric( c);
   int capital = mulle_unicode_is_capitalized( c);
   int control = mulle_unicode_is_control( c);
   int decimal = mulle_unicode_is_decimaldigit( c);
   int decomp  = mulle_unicode_is_decomposable( c);
   int letter  = mulle_unicode_is_letter( c);
   int lower   = mulle_unicode_is_lowercase( c);
   int newline = mulle_unicode_is_newline( c);
   int nonbase = mulle_unicode_is_nonbase( c);
   int nonchar = mulle_unicode_is_noncharacter( c);
   int punct   = mulle_unicode_is_punctuation( c);
   int symbol  = mulle_unicode_is_symbol( c);
   int upper   = mulle_unicode_is_uppercase( c);
   int ws      = mulle_unicode_is_whitespace( c);
   int wsnl    = mulle_unicode_is_whitespaceornewline( c);
   int legal   = mulle_unicode_is_legalcharacter( c);
   int idstart = mulle_unicode_is_identifierstart( c);
   int idcont  = mulle_unicode_is_identifiercontinuation( c);
   int zero    = mulle_unicode_is_zerodigit( c);

   // consistency: newline implies whitespaceornewline
   if( newline)
      assert( wsnl);

   // consistency: whitespace implies whitespaceornewline
   if( ws)
      assert( wsnl);

   // consistency: identifier start implies identifier continuation
   if( idstart)
      assert( idcont);

   // consistency: lowercase or uppercase implies letter
   // (not always true for all Unicode, but for this lib's definition check)
   // Actually skip — capitalized titlecase chars may not be upper or lower

   // BMP agreement: for code points 0..0xFFFF, the 16-bit variants must agree
   if( c >= 0 && c <= 0xFFFF)
   {
      c16 = (uint16_t) c;
      assert( mulle_unicode16_is_alphanumeric( c16) == alnum);
      assert( mulle_unicode16_is_capitalized( c16) == capital);
      assert( mulle_unicode16_is_control( c16) == control);
      assert( mulle_unicode16_is_decimaldigit( c16) == decimal);
      assert( mulle_unicode16_is_decomposable( c16) == decomp);
      assert( mulle_unicode16_is_letter( c16) == letter);
      assert( mulle_unicode16_is_lowercase( c16) == lower);
      assert( mulle_unicode16_is_newline( c16) == newline);
      assert( mulle_unicode16_is_nonbase( c16) == nonbase);
      assert( mulle_unicode16_is_punctuation( c16) == punct);
      assert( mulle_unicode16_is_symbol( c16) == symbol);
      assert( mulle_unicode16_is_uppercase( c16) == upper);
      assert( mulle_unicode16_is_whitespace( c16) == ws);
      assert( mulle_unicode16_is_whitespaceornewline( c16) == wsnl);
      assert( mulle_unicode16_is_legalcharacter( c16) == legal);
      assert( mulle_unicode16_is_zerodigit( c16) == zero);
   }

   (void) alnum; (void) capital; (void) control; (void) decimal;
   (void) decomp; (void) letter; (void) lower; (void) newline;
   (void) nonbase; (void) nonchar; (void) punct; (void) symbol;
   (void) upper; (void) ws; (void) wsnl; (void) legal;
   (void) idstart; (void) idcont; (void) zero;

   return( 0);
}
