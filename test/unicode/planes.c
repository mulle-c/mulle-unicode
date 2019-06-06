#include <mulle-utf/mulle-utf.h>

#include <stdio.h>
#include <stdlib.h>



static void  test( char *name,
                   int (*member_f)( mulle_utf32_t),
                   int (*plane_f)( unsigned int))
{
   mulle_utf32_t   c;
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
   test( "alphanumeric", mulle_utf32_is_alphanumeric, mulle_utf_is_alphanumericplane);
   test( "capitalized", mulle_utf32_is_capitalized, mulle_utf_is_capitalizedplane);
   test( "control", mulle_utf32_is_control, mulle_utf_is_controlplane);
   test( "decimaldigit", mulle_utf32_is_decimaldigit, mulle_utf_is_decimaldigitplane);
   test( "decomposable", mulle_utf32_is_decomposable, mulle_utf_is_decomposableplane);
   test( "legalcharacter", mulle_utf32_is_legalcharacter, mulle_utf_is_legalcharacterplane);
   test( "letter", mulle_utf32_is_letter, mulle_utf_is_letterplane);
   test( "lowercase", mulle_utf32_is_lowercase, mulle_utf_is_lowercaseplane);
   test( "newline", mulle_utf32_is_newline, mulle_utf_is_newlineplane);
   test( "nonbase", mulle_utf32_is_nonbase, mulle_utf_is_nonbaseplane);
   test( "noncharacter", mulle_utf32_is_noncharacter, mulle_utf_is_noncharacterplane);
   test( "nonpercentescape", mulle_utf32_is_nonpercentescape, mulle_utf_is_nonpercentescapeplane);
   test( "privatecharacter", mulle_utf32_is_privatecharacter, mulle_utf_is_privatecharacterplane);
   test( "punctuation", mulle_utf32_is_punctuation, mulle_utf_is_punctuationplane);
   test( "symbol", mulle_utf32_is_symbol, mulle_utf_is_symbolplane);
   test( "uppercase", mulle_utf32_is_uppercase, mulle_utf_is_uppercaseplane);
   test( "validurlfragment", mulle_utf32_is_validurlfragment, mulle_utf_is_validurlfragmentplane);
   test( "validurlhost", mulle_utf32_is_validurlhost, mulle_utf_is_validurlhostplane);
   test( "validurlpassword", mulle_utf32_is_validurlpassword, mulle_utf_is_validurlpasswordplane);
   test( "validurlpath", mulle_utf32_is_validurlpath, mulle_utf_is_validurlpathplane);
   test( "validurlquery", mulle_utf32_is_validurlquery, mulle_utf_is_validurlqueryplane);
   test( "validurlscheme", mulle_utf32_is_validurlscheme, mulle_utf_is_validurlschemeplane);
   test( "validurluser", mulle_utf32_is_validurluser, mulle_utf_is_validurluserplane);
   test( "whitespace", mulle_utf32_is_whitespace, mulle_utf_is_whitespaceplane);
   test( "whitespaceornewline", mulle_utf32_is_whitespaceornewline, mulle_utf_is_whitespaceornewlineplane);
   return( 0);
}

