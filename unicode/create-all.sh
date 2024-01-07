#! /bin/sh

MAPSDIR="${1:-maps}"
SETSDIR="${2:-sets}"
BITMAPSDIR="${3:-bitmaps}"
FILE="${3:-UnicodeData.txt}"


create_dirs()
{
   mkdir -p "${MAPSDIR}" 2> /dev/null
   mkdir -p "${SETSDIR}" 2> /dev/null
   mkdir -p "${BITMAPSDIR}" 2> /dev/null
}


create_map_files()
{
   local file
   local suffix

   file="$1"
   suffix="$2"

   ./create-map.sh 12 "${file}" > "${MAPSDIR}/toupper${suffix}.inc"
   ./create-map.sh 13 "${file}" > "${MAPSDIR}/tolower${suffix}.inc"
   ./create-map.sh 14 "${file}" > "${MAPSDIR}/totitlecase${suffix}.inc"
}


create_set_files()
{
   local file
   local suffix
   local delete

   file="$1"
   suffix="$2"
   inverse="$3"

   if [ -z "${inverse}" ]
   then
      ./create-zero.sh "${file}" > "${SETSDIR}/iszerodigit${suffix}.inc"
   fi

   # all defined characters
   ./create-set.sh 1 "${file}" "${inverse}" > "${SETSDIR}/islegal${suffix}.inc"

   ./create-set.sh 5 "${file}" "${inverse}" > "${SETSDIR}/isdecomposable${suffix}.inc"
   ./create-set.sh 6 "${file}" "${inverse}" > "${SETSDIR}/isdecimaldigit${suffix}.inc"
   ./create-set.sh 7 "${file}" "${inverse}" > "${SETSDIR}/isdigit${suffix}.inc"
   ./create-set.sh 8 "${file}" "${inverse}" > "${SETSDIR}/isnumeric${suffix}.inc"

   # characters in Unicode General Category M*.
   ./create-category-set.sh 'M.'     "${file}" "${inverse}" > "${SETSDIR}/isnonbase${suffix}.inc"
   # characters in Unicode General Category Ll.
   ./create-category-set.sh 'Ll'     "${file}" "${inverse}" > "${SETSDIR}/islowercase${suffix}.inc"
   # characters in Unicode General Category Lu and Lt.
   ./create-category-set.sh 'L[ut]'  "${file}" "${inverse}" > "${SETSDIR}/isuppercase${suffix}.inc"
   # characters in Unicode General Categories L*, M*, and N*.
   ./create-category-set.sh '[LMN].' "${file}" "${inverse}" > "${SETSDIR}/isalphanumeric${suffix}.inc"
   # characters in Unicode General Category Lt
   ./create-category-set.sh 'Lt'     "${file}" "${inverse}" > "${SETSDIR}/iscapitalized${suffix}.inc"
   # characters in Unicode General Category L* & M*.
   ./create-category-set.sh '[LM].'  "${file}" "${inverse}" > "${SETSDIR}/isletter${suffix}.inc"
   # characters in Unicode General Category P*.
   ./create-category-set.sh 'P.'     "${file}" "${inverse}" > "${SETSDIR}/ispunctuation${suffix}.inc"
   # characters in Unicode General Category S*.
   ./create-category-set.sh 'S.'     "${file}" "${inverse}" > "${SETSDIR}/issymbol${suffix}.inc"
   # characters in Unicode General Category Cc and Cf.
   ./create-category-set.sh 'C[cf]'  "${file}" "${inverse}" > "${SETSDIR}/iscontrol${suffix}.inc"
   # characters in Unicode General Category Zs and CHARACTER TABULATION (U+0009).
   ./create-category-set.sh 'Z.'     "${file}" "${inverse}" > "${SETSDIR}/iswhitespace${suffix}.inc"

   ./create-category-set.sh 'Co'     "${file}" "${inverse}" > "${SETSDIR}/isprivate${suffix}.inc"

   ./create-category-set.sh 'Z[slp]' "${file}" "${inverse}" > "${SETSDIR}/isseparator${suffix}.inc"

   # characters as identifier starters
   # https://www.unicode.org/Public/UCD/latest/ucd/DerivedCoreProperties.txt
   # Derived Property: ID_Start
   #  Characters that can start an identifier.
   #  Generated from:
   #      Lu + Ll + Lt + Lm + Lo + Nl
   #    + Other_ID_Start
   #    - Pattern_Syntax
   #    - Pattern_White_Space
   #  NOTE: See UAX #31 for more information
   #
   # Lu: Uppercase Letter
   # Ll: Lowercase Letter
   # Lt: Titlecase Letter
   # Lm: Modifier Letter
   # Lo: Other Letter
   # Nl: Letter Number (like: Roman numerals: I, V, X, L, C, D, M) ??

   ./create-category-set.sh 'L[ultmol]'  "${file}" "${inverse}" > "${SETSDIR}/isidentifierstart${suffix}.inc"

   # i don't see any "weird" characters being added, so the subtraction must
   # me more conceptual than anything
   #    ID_Start
   #    Mn + Mc + Nd + Pc
   #
   #  Mn: Nonspacing Mark
   #  Mc: Spacing Mark
   #  Nd: Decimal Number
   #  Pc: Connector Punctuation

   ./create-category-set.sh 'L[ultmol]|M[nc]|Nd|Pc'  "${file}" "${inverse}" > "${SETSDIR}/isidentifiercontinuation${suffix}.inc"
}


create_bitmap_files()
{
   ./create-bitmap.sh 'isalphanumeric'           "${SETSDIR}" "${BITMAPSDIR}"
   ./create-bitmap.sh 'iscapitalized'            "${SETSDIR}" "${BITMAPSDIR}"
   ./create-bitmap.sh 'isdecomposable'           "${SETSDIR}" "${BITMAPSDIR}"
   ./create-bitmap.sh 'islegal'                  "${SETSDIR}" "${BITMAPSDIR}"
   ./create-bitmap.sh 'isletter'                 "${SETSDIR}" "${BITMAPSDIR}"
   ./create-bitmap.sh 'islowercase'              "${SETSDIR}" "${BITMAPSDIR}"
   ./create-bitmap.sh 'isnonbase'                "${SETSDIR}" "${BITMAPSDIR}"
   ./create-bitmap.sh 'ispunctuation'            "${SETSDIR}" "${BITMAPSDIR}"
   ./create-bitmap.sh 'issymbol'                 "${SETSDIR}" "${BITMAPSDIR}"
   ./create-bitmap.sh 'isuppercase'              "${SETSDIR}" "${BITMAPSDIR}"
   ./create-bitmap.sh 'isidentifierstart'        "${SETSDIR}" "${BITMAPSDIR}"
   ./create-bitmap.sh 'isidentifiercontinuation' "${SETSDIR}" "${BITMAPSDIR}"
}


UTF16FILE=utf16.txt
UTF32FILE=utf32.txt

# https://unix.stackexchange.com/questions/11305/grep-show-all-the-file-up-to-the-match

set -e
sed -e '/^FFFD;/q' -e '/^0000;/d' "${FILE}" > "${UTF16FILE}"
sed -n -e '/^10000/,$ p' "${FILE}" > "${UTF32FILE}"

create_dirs
create_map_files "${UTF16FILE}" "-utf16"
create_map_files "${UTF32FILE}" "-utf32"

create_set_files "${UTF16FILE}" "-utf16"
create_set_files "${UTF32FILE}" "-utf32"

#
# not doing inverses anymore, they produced some questionable content
# and in general have been superseded by bitmaps
#

# create_set_files "${UTF16FILE}" "-utf16-inv" "YES"
# create_set_files "${UTF32FILE}" "-utf32-inv" "YES"

create_bitmap_files

rm "${UTF16FILE}" "${UTF32FILE}"

