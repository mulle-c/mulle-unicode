#include <mulle-unicode/mulle-unicode.h>
#include <mulle-fprintf/mulle-fprintf.h>
#include <stdio.h>
#include <stdlib.h>


int  main()
{
   int32_t        c;
   unsigned int   column;

   column = 0;
   for( c = 0; c < 0x110000; c++)
   {
      if( mulle_unicode_is_identifierstart( c))
      {
         if( column++ == 78)
         {
            column = 0;
            mulle_printf( "\n");
         }

         mulle_printf( "%.1lS", &c);
      }
   }
   mulle_printf( "\n");
   return( 0);
}

