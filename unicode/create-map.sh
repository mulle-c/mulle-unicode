#! /bin/sh
# 0 charcode
# 12 toupper
# 13 tolower
# 14 Title Case

FIELD=${1:-12}
FILE=${2:-UnicodeData.txt}

set -e

if [ ! -f "${FILE}" -a "${FILE}" = "UnicodeData.txt" ]
then
   curl -O "http://www.unicode.org/Public/UNIDATA/UnicodeData.txt"
fi

# 13 is just the inverse of 12, as field 13 is not specified ?

FIELD=`expr $FIELD + 1`  # for cut

cut '-d;' -f 1,"${FIELD}" "${FILE}" | \
sed '/^.*;$/d' | \
sed 's/\(.*\);\(.*\)/   case 0x\1 : return( 0x\2);/' | \
tr '[:upper:]' '[:lower:]'
