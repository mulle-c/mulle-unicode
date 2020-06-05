#! /bin/sh
# 0 charcode
# 6 decimal digit
# 7 Digit
# 8 numeric

NAME="$1"
SETSDIR="$2"
BITMAPSDIR="$3"


set -e

# 13 is just the inverse of 12, as field 13 is not specified ?

#
# *** this fails for example for isletter where 0x378 or 0x379
#     are not part of the normal or the inverse. why ???
#
if [ ! -f "${SETSDIR}/${NAME}-utf16.inc" ]
then
   echo "Create ${SETSDIR} first"
   exit 1
fi

sed "s/<|NAME|>/${NAME}/" < template.c > "tmp.c" &&
cc -o "tmp" -I"${SETSDIR}" -O0 -g "tmp.c" &&
"./tmp" > "${BITMAPSDIR}/${NAME}-bitmap.inc"
