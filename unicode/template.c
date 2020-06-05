#include <stdio.h>
#include <string.h>


static int   is_in_set( int c)
{
   switch( c)
   {
#include "<|NAME|>-utf16.inc"
#include "<|NAME|>-utf32.inc"
      return( 1);
   }
   return( 0);
}

// A plane = 65536 bits takes up 8192 bytes.
// To conserve space we use miniplanes which are
// only 128 bytes large though (/ 64), and miniplanes
// which are all bit set ot cleared are treated
// differently.

#define N_PLANE          0x11
#define N_MINIPLANE      64

#define S_PLANE          (0x10000 / 8)
#define S_MINIPLANE      (S_PLANE / N_MINIPLANE)


static void   getMiniBytes( unsigned char *minibytes, int plane, int miniplane)
{
   int  c;
   int  i;
   unsigned char  byte[ 8];

   c = (plane << 16) | (miniplane << (7 + 3));
   for( i = 0; i < S_MINIPLANE; i++, c += 8)
   {
      byte[ 0] = is_in_set( c + 0);
      byte[ 1] = is_in_set( c + 1);
      byte[ 2] = is_in_set( c + 2);
      byte[ 3] = is_in_set( c + 3);
      byte[ 4] = is_in_set( c + 4);
      byte[ 5] = is_in_set( c + 5);
      byte[ 6] = is_in_set( c + 6);
      byte[ 7] = is_in_set( c + 7);
      minibytes[ i] = (byte[ 0] << 0) |
                      (byte[ 1] << 1) |
                      (byte[ 2] << 2) |
                      (byte[ 3] << 3) |
                      (byte[ 4] << 4) |
                      (byte[ 5] << 5) |
                      (byte[ 6] << 6) |
                      (byte[ 7] << 7);
   }
}


int   main( void)
{
   char            *sep;
   unsigned char   *p;
   unsigned char   bitmaps[ N_PLANE][ N_MINIPLANE];
   unsigned char   empty[ S_MINIPLANE];
   unsigned char   full[ S_MINIPLANE];
   unsigned char   minibytes[ S_MINIPLANE];
   unsigned char   planes[ N_PLANE];
   unsigned int    i;
   unsigned int    miniplane;
   unsigned int    plane;

   memset( empty, 0, sizeof( empty));
   memset( full, 0xFF, sizeof( full));
   memset( bitmaps, 0, sizeof( bitmaps));
   memset( planes, 0, sizeof( planes));

   /*
    * Print each miniplane, if interesting
    */
   for( plane = 0; plane < N_PLANE; plane++)
   {
      for( miniplane = 0; miniplane < N_MINIPLANE; miniplane++)
      {
         getMiniBytes( minibytes, plane, miniplane);
         if( ! memcmp( minibytes, empty, S_MINIPLANE))
            continue;

         planes[ plane] = 1;

         if( ! memcmp( minibytes, full, S_MINIPLANE))
         {
            bitmaps[ plane][ miniplane] = 1;
            continue;
         }

         bitmaps[ plane][ miniplane] = 2;
         // 1024 bits in this bitmap
         sep = "   ";
         fprintf( stdout, "static unsigned char   miniplane_%02x%02x[ %d] =\n{\n", plane, miniplane, S_MINIPLANE);

         p = minibytes;
         for( i = 0; i < S_MINIPLANE; i += 8)
         {
            fprintf( stdout, "%s0x%02x, 0x%02x, 0x%02x, 0x%02x,  0x%02x, 0x%02x, 0x%02x, 0x%02x",
                           sep,
                           p[ 0], p[ 1], p[ 2], p[ 3],
                           p[ 4], p[ 5], p[ 6], p[ 7]);
            if( i == S_MINIPLANE / 2 - 8)
               sep = ",\n\n   ";
            else
               sep = ",\n   ";
            p += 8;
         }
         fprintf( stdout, "\n};\n\n");
      }
   }

   /*
    * Print each plane
    */
   for( plane = 0; plane < N_PLANE; plane++)
   {
      if( ! planes[ plane])
         continue;

      fprintf( stdout, "static unsigned char   *plane_%02x[ %d] =\n{\n", plane, N_MINIPLANE);

      sep = "   ";
      for( miniplane = 0; miniplane < N_MINIPLANE; miniplane++)
      {
         switch( bitmaps[ plane][ miniplane])
         {
         case 0 : fprintf( stdout, "%s_MINIPLANE_CLR", sep); break;
         case 1 : fprintf( stdout, "%s_MINIPLANE_SET", sep); break;
         case 2 : fprintf( stdout, "%sminiplane_%02x%02x", sep, plane, miniplane); break;
         }
         if( miniplane % 4 == 3)
            sep = ",\n   ";
         else
            sep = ", ";
      }
      fprintf( stdout, "\n};\n");
   }

   /*
    *
    */
   fprintf( stdout, "\nstatic unsigned char   **planes[ 0x%02x] =\n{\n", N_PLANE);
   sep = "   ";
   for( plane = 0; plane < N_PLANE; plane++)
   {
      if( ! planes[ plane])
         fprintf( stdout, "%s_PLANE_NULL", sep);
      else
         fprintf( stdout, "%splane_%02x", sep, plane);
      sep = ",\n   ";
   }
   fprintf( stdout, "\n};\n");

   return( 0);
}

