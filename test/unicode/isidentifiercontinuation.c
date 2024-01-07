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
      if( mulle_unicode_is_identifiercontinuation( c))
      {
         mulle_printf( "'%.1lS'", &c);

         if( column == 10)
            mulle_printf( "  | ");
         else
            mulle_printf( " ");

         if( column == 20)
         {
            mulle_printf( "\n");
            column = -1;
         }
         ++column;
      }
   }
   mulle_printf( "\n");
   return( 0);
}

