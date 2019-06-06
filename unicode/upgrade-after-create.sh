#! /bin/sh

(
   cd maps
   for i in *.inc 
   do  
      if [ -f "../../src/unicode/$i" ]
      then      
         cp -v "$i" "../../src/unicode/"
      fi
   done
)

(
   cd sets
   for i in *.inc 
   do  
      if [ -f "../../src/unicode/$i" ]
      then      
         cp -v "$i" "../../src/unicode/"
      fi
   done
)

