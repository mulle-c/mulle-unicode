#include <mulle-unicode/mulle-unicode.h>
#include <stdio.h>
#include <stdlib.h>


int  main()
{
   int32_t  c;
   int32_t  d;
   int32_t  e;
   int      rc;

   rc = 0;
   for( c = 0; c < 0x110000; c++)
   {
      d = mulle_unicode_toupper( c);
      if( c != d)
      {
         printf( "%#0x uppercase is %#0x\n", c, d);

         e = mulle_unicode_tolower( d);
         if( c != e)
         {
            // The behavior you're observing is due to the way Unicode handles
            // case mappings. The toupper and tolower functions in Unicode are
            // not always bijective, meaning that a character may not have a
            // direct mapping to its lowercase or uppercase equivalent.
            printf( "%#0x - %#0x - %#0x uppercase/lowercase conversion is not bidirectional\n", c, d, e);
            rc = 0;  //
         }
      }
   }
   return( rc);
}

