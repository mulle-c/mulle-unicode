#include <mulle-unicode/mulle-unicode.h>

#include <stdio.h>
#include <stdlib.h>



static void  test( char *name,
                   int (*member_f)( int32_t))
{
   printf( "%s zero %s member\n", name, (*member_f)( 0) ? "IS" : "is not");
}


int  main()
{
   test( "alphanumeric", mulle_unicode_is_alphanumeric);
   test( "capitalized", mulle_unicode_is_capitalized);
   test( "control", mulle_unicode_is_control);
   test( "decimaldigit", mulle_unicode_is_decimaldigit);
   test( "decomposable", mulle_unicode_is_decomposable);
   test( "legalcharacter", mulle_unicode_is_legalcharacter);
   test( "letter", mulle_unicode_is_letter);
   test( "lowercase", mulle_unicode_is_lowercase);
   test( "newline", mulle_unicode_is_newline);
   test( "nonbase", mulle_unicode_is_nonbase);
   test( "noncharacter", mulle_unicode_is_noncharacter);
   test( "privatecharacter", mulle_unicode_is_privatecharacter);
   test( "punctuation", mulle_unicode_is_punctuation);
   test( "symbol", mulle_unicode_is_symbol);
   test( "uppercase", mulle_unicode_is_uppercase);
   test( "whitespace", mulle_unicode_is_whitespace);
   test( "whitespaceornewline", mulle_unicode_is_whitespaceornewline);
   return( 0);
}

