#include <mulle-unicode/mulle-unicode.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void  test( char *name,
                   int (*member_f)( int32_t),
                   int (*plane_f)( unsigned int))
{
   int32_t         c;
   unsigned int    planes[ 0x11];
   unsigned int    i;
   unsigned int    expect;

   memset( planes, 0, sizeof( planes));

   for( c = 0; c < 0x110000; c++)
      if( (*member_f)( c))
      {
         planes[ c >> 16] = 1;
         c  = c & ~0xFFFF;
         c += 0xFFFF;
         continue;
      }


   for( i = 0; i < 0x11; i++)
   {
      printf( "%s plane #%d : ", name, i);
      expect = (*plane_f)( i);
      if( expect == planes[ i])
         printf( "pass\n");
      else
         printf( "failed (expect: %d, result: %d)\n", expect, planes[ i]);
   }
}


int  main()
{
   test( "alphanumeric", mulle_unicode_is_alphanumeric, mulle_unicode_is_alphanumericplane);
   test( "capitalized", mulle_unicode_is_capitalized, mulle_unicode_is_capitalizedplane);
   test( "control", mulle_unicode_is_control, mulle_unicode_is_controlplane);
   test( "decimaldigit", mulle_unicode_is_decimaldigit, mulle_unicode_is_decimaldigitplane);
   test( "decomposable", mulle_unicode_is_decomposable, mulle_unicode_is_decomposableplane);
   test( "legalcharacter", mulle_unicode_is_legalcharacter, mulle_unicode_is_legalcharacterplane);
   test( "letter", mulle_unicode_is_letter, mulle_unicode_is_letterplane);
   test( "lowercase", mulle_unicode_is_lowercase, mulle_unicode_is_lowercaseplane);
   test( "newline", mulle_unicode_is_newline, mulle_unicode_is_newlineplane);
   test( "nonbase", mulle_unicode_is_nonbase, mulle_unicode_is_nonbaseplane);
   test( "noncharacter", mulle_unicode_is_noncharacter, mulle_unicode_is_noncharacterplane);
   test( "punctuation", mulle_unicode_is_punctuation, mulle_unicode_is_punctuationplane);
   test( "symbol", mulle_unicode_is_symbol, mulle_unicode_is_symbolplane);
   test( "uppercase", mulle_unicode_is_uppercase, mulle_unicode_is_uppercaseplane);
   test( "whitespace", mulle_unicode_is_whitespace, mulle_unicode_is_whitespaceplane);
   test( "whitespaceornewline", mulle_unicode_is_whitespaceornewline, mulle_unicode_is_whitespaceornewlineplane);
   return( 0);
}

