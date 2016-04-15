//
//  mulle_utf_is_noncharacter.c
//  mulle-utf
//
//  Created by Nat! on 15.04.16.
//  Copyright © 2016 Mulle kybernetiK. All rights reserved.
//

#include "mulle_utf_is_noncharacter.h"


// Q: Which code points are noncharacters?
int   mulle_utf_is_noncharacter( unichar c)
{
   // quick check for most
   if( c < 0x0FFF)
      return( 0);

   // above 0x10FFFF is not unicode
   if( c > 0x10FFFF)
      return( 1);
   
   // a contiguous range of 32 noncharacters: U+FDD0..U+FDEF in the BMP
   if( c >= 0xFDD0 && c <= 0xFDEF)
      return( 1);
   
   // the last two code points of the BMP, U+FFFE and U+FFFF
   // the last two code points of each of the 16 supplementary planes: U+1FFFE, U+1FFFF, U+2FFFE, U+2FFFF, ... U+10FFFE, U+10FFFF
   switch( c & 0xffff)
   {
   case 0xfffe  :
   case 0xffff  :
      return( 1);
   }
   return( 0);
}


int   mulle_utf_is_privatecharacter( unichar c)
{
   // quick check for most
   if( c < 0xE000)
      return( 0);
   
   if( c <= 0xF8FF)
      return( 1);

   
   if( c >= 0xF0000 && c <= 0xFFFFD)
      return( 1);
   if( c >= 0x100000 && c <= 0x10FFFD)
      return( 1);

   return( 0);
}

