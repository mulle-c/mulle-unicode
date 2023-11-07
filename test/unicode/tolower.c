#include <mulle-unicode/mulle-unicode.h>
#include <stdio.h>
#include <stdlib.h>


int  main()
{
   int32_t  c;
   int32_t  d;

   // coverage
   if( mulle_unicode16_nop( 1) != 1)
      return( 1);
   if( mulle_unicode_nop( 1) != 1)
      return( 1);

   for( c = 0; c < 0x100; c++)
   {
      d = mulle_unicode16_tolower( c);
      if( c != d && mulle_unicode_tolower( c) != d)
         return( 1);
   }

   for( c = 0; c < 0x110000; c++)
   {
      d = mulle_unicode_tolower( c);
      if( c != d)
         printf( "%#0x lowercase is %#0x\n", c, d);
   }
   return( 0);
}

