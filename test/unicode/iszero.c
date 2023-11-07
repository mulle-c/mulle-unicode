#include <mulle-unicode/mulle-unicode.h>
#include <stdio.h>
#include <stdlib.h>


int  main()
{
   int32_t  c;

   for( c = 0; c < 0x110000; c++)
   {
      if( mulle_unicode_is_zerodigit( c))
         printf( "%#0x is zero\n", c);
   }
   return( 0);
}

