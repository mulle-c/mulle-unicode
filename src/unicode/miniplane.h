#define _MINIPLANE_CLR  ((unsigned char *) 0)
#define _PLANE_NULL     0
#define _MINIPLANE_SET  ((unsigned char *) 1)

static int   is_special_miniplane( unsigned char *miniplane)
{
   return( miniplane <= _MINIPLANE_SET);
}



static inline int   is_member_of_planes( unsigned char ***planes, int32_t c)
{
   unsigned int    i;
   unsigned char   **plane;
   unsigned char   *miniplane;
   unsigned char   byte;
   int32_t         x;

   /* get plane */
   i = c >> 16;
   if( i >= 0x11)
      return( 0);
   plane = planes[ i];
   if( ! plane)
      return( 0);
   x = c & 0xFFFF;

   /* get miniplane */
   miniplane = plane[ x >> (7 + 3)];
   if( is_special_miniplane( miniplane))
      return( (miniplane == _MINIPLANE_CLR) ? 0 : 1);
   x &= 0x3FF;

   /* get byte */
   byte = miniplane[ x >> 3];
   x   &= 0x7;

   /* get bit */
   if( (1U << x) & byte)
      return( 1);
   return( 0);
}

