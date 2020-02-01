#! /bin/sh

set -e
for inv in *-inv.inc
do
   file="`echo "${inv}" | sed 's/-inv//g'`"
   inv_lines="`wc -l "${inv}" | awk '{ print $1 }'`"


   if [ -f "${file}" ]
   then
      file_lines="`wc -l "${file}" | awk '{ print $1 }'`"

      if [ ${inv_lines} -lt ${file_lines} ]
      then
         if [ ${inv_lines} -eq 0 ]
         then
            echo "${inv} is empty so removing it" >&2
            rm "$inv"
         else
            echo "${inv} has only ${inv_lines} lines compared to ${file_lines}, so keeping it" >&2
         fi
         rm "$file"
      else
         if [ ${file_lines} -eq 0 ]
         then
            echo "${file} is empty so removing it" >&2
            rm "$file"
         else
            echo "${file} has only ${file_lines} lines compared to ${inv_lines}, so keeping it" >&2
         fi
         rm "$inv"
      fi
   fi
done
