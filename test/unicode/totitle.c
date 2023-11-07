#include <mulle-unicode/mulle-unicode.h>
#include <stdio.h>
#include <stdlib.h>


int  main()
{
   int32_t  c;
   int32_t  d;

   for( c = 0; c < 0x110000; c++)
   {
      d = mulle_unicode_totitlecase( c);
      if( c != d)
         printf( "%#0x titlecase is %#0x\n", c, d);
   }
   return( 0);
}

