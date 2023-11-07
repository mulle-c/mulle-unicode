#include <mulle-unicode/mulle-unicode.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void  test( char *name,
                   int (*member_f)( int32_t),
                   int (*plane_f)( unsigned int))
{
   int32_t        c;
   unsigned int   planes[ 0x12];
   unsigned int   i;
   unsigned int   expect;

   memset( planes, 0, sizeof( planes));

   for( c = 0; c <= 0x110000; c++)
      if( (*member_f)( c))
      {
         planes[ c >> 16] = 1;
//         c  = c & ~0xFFFF;
//         c += 0xFFFF;
//         continue;
      }

   for( i = 0; i < 0x12; i++)
   {
      printf( "%s plane #%d : ", name, i);
      expect = (*plane_f)( i);
      if( (expect == planes[ i]) ||
          (expect == 0 && i == 0x11) ||
          (strcmp( name, "noncharacter") || (expect == 1 && i == 0x11)))
      {
         printf( "pass\n");
      }
      else
      {
         printf( "failed (expect: %d, result: %d)\n", expect, planes[ i]);
      }
   }
}


// somewhat bullshit code for coverage
static void  test16( char *name,
                     int (*member_f)( uint16_t),
                     int (*plane_f)( unsigned int))
{
   int32_t        c;
   unsigned int   planes[ 0x1];
   unsigned int   i;
   unsigned int   expect;

   memset( planes, 0, sizeof( planes));

   for( c = 0; c < 0x10000; c++)
      if( (*member_f)( c))
         planes[ 0] = 1;

   for( i = 0; i < 0x1; i++)
   {
      printf( "%s plane #%d : ", name, i);
      expect = (*plane_f)( i);
      if( expect == planes[ i])
      {
         printf( "pass\n");
      }
      else
      {
         printf( "failed (expect: %d, result: %d)\n", expect, planes[ i]);
      }
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

   test16( "alphanumeric", mulle_unicode16_is_alphanumeric, mulle_unicode_is_alphanumericplane);
   test16( "capitalized", mulle_unicode16_is_capitalized, mulle_unicode_is_capitalizedplane);
   test16( "control", mulle_unicode16_is_control, mulle_unicode_is_controlplane);
   test16( "decimaldigit", mulle_unicode16_is_decimaldigit, mulle_unicode_is_decimaldigitplane);
   test16( "decomposable", mulle_unicode16_is_decomposable, mulle_unicode_is_decomposableplane);
   test16( "legalcharacter", mulle_unicode16_is_legalcharacter, mulle_unicode_is_legalcharacterplane);
   test16( "letter", mulle_unicode16_is_letter, mulle_unicode_is_letterplane);
   test16( "lowercase", mulle_unicode16_is_lowercase, mulle_unicode_is_lowercaseplane);
   test16( "newline", mulle_unicode16_is_newline, mulle_unicode_is_newlineplane);
   test16( "nonbase", mulle_unicode16_is_nonbase, mulle_unicode_is_nonbaseplane);
   test16( "noncharacter", mulle_unicode16_is_noncharacter, mulle_unicode_is_noncharacterplane);
   test16( "punctuation", mulle_unicode16_is_punctuation, mulle_unicode_is_punctuationplane);
   test16( "symbol", mulle_unicode16_is_symbol, mulle_unicode_is_symbolplane);
   test16( "uppercase", mulle_unicode16_is_uppercase, mulle_unicode_is_uppercaseplane);
   test16( "whitespace", mulle_unicode16_is_whitespace, mulle_unicode_is_whitespaceplane);
   test16( "whitespaceornewline", mulle_unicode16_is_whitespaceornewline, mulle_unicode_is_whitespaceornewlineplane);


   return( 0);
}

