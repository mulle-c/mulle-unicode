#! /bin/sh
# 0 charcode
# 6 decimal digit
# 7 Digit
# 8 numeric

FIELD="${1:-6}"
FILE="${2:-UnicodeData.txt}"
INVERSE="${3}"  # use !d for inverse


set -e

# 13 is just the inverse of 12, as field 13 is not specified ?

if [ -z "${INVERSE}" ]
then
   DELETE='d'
else
   DELETE='!d'
fi


FIELD=`expr $FIELD + 1`  # for cut

cut '-d;' -f 1,"${FIELD}" "${FILE}" | \
sed '/^.*;$/'"${DELETE}" | \
sed 's/\(.*\);.*/   case 0x\1 :/' | \
tr '[:upper:]' '[:lower:]'
