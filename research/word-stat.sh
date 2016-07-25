#! /bin/sh

if [ ! -f words ]
then
   find . -name "*.[hm]" -exec grep -o -E '\w+' {} \; | sort > words
fi

# remove small strings that are used by char7

sed '/^.$/d;/^..$/d;/^...$/d;/^....$/d;/^.....$/d;/^......$/d;/^.......$/d;/^........$/d' < words > words.large
sort -u < words.large > words.unique
uniq -c words.large | sort -n -r > words.stats
egrep -o -E '.' < words.unique | sort | uniq -c | sort -n -r > char.stats
