#include <mulle-utf/mulle-utf.h>

#include <stdio.h>
#include <stdlib.h>



static void  test( char *name,
                   int (*member_f)( mulle_utf32_t))
{
   printf( "%s zero %s member\n", name, (*member_f)( 0) ? "IS" : "is not");
}


int  main()
{
   test( "alphanumeric", mulle_utf32_is_alphanumeric);
   test( "capitalized", mulle_utf32_is_capitalized);
   test( "control", mulle_utf32_is_control);
   test( "decimaldigit", mulle_utf32_is_decimaldigit);
   test( "decomposable", mulle_utf32_is_decomposable);
   test( "legalcharacter", mulle_utf32_is_legalcharacter);
   test( "letter", mulle_utf32_is_letter);
   test( "lowercase", mulle_utf32_is_lowercase);
   test( "newline", mulle_utf32_is_newline);
   test( "nonbase", mulle_utf32_is_nonbase);
   test( "noncharacter", mulle_utf32_is_noncharacter);
   test( "nonpercentescape", mulle_utf32_is_nonpercentescape);
   test( "privatecharacter", mulle_utf32_is_privatecharacter);
   test( "punctuation", mulle_utf32_is_punctuation);
   test( "symbol", mulle_utf32_is_symbol);
   test( "uppercase", mulle_utf32_is_uppercase);
   test( "validurlfragment", mulle_utf32_is_validurlfragment);
   test( "validurlhost", mulle_utf32_is_validurlhost);
   test( "validurlpassword", mulle_utf32_is_validurlpassword);
   test( "validurlpath", mulle_utf32_is_validurlpath);
   test( "validurlquery", mulle_utf32_is_validurlquery);
   test( "validurlscheme", mulle_utf32_is_validurlscheme);
   test( "validurluser", mulle_utf32_is_validurluser);
   test( "whitespace", mulle_utf32_is_whitespace);
   test( "whitespaceornewline", mulle_utf32_is_whitespaceornewline);
   return( 0);
}

