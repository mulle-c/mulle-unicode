#! /bin/sh

find . -name "*.[hm]" -exec grep -o -E '\w+' {} \; | sort > words
sort < words > words.unique
uniq -c words | sort -n -r > words.stats
egrep -o -E '.' < words.unique | sort | uniq -c | sort -n -r > char.stats
