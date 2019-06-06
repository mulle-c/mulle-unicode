#! /bin/sh

MAPSDIR="${1:-maps}"
SETSDIR="${2:-sets}"
FILE="${3:-UnicodeData.txt}"


create_dirs()
{
   mkdir -p "${MAPSDIR}" 2> /dev/null
   mkdir -p "${SETSDIR}" 2> /dev/null
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
create_set_files "${UTF16FILE}" "-utf16-inv" "YES"
create_set_files "${UTF32FILE}" "-utf32-inv" "YES"

rm "${UTF16FILE}" "${UTF32FILE}"

