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

   ./create-set.sh 5 "${file}" > "${SETSDIR}/isdecomposable${suffix}.inc" "${inverse}"
   ./create-set.sh 6 "${file}" > "${SETSDIR}/isdecimaldigit${suffix}.inc" "${inverse}"
   ./create-set.sh 7 "${file}" > "${SETSDIR}/isdigit${suffix}.inc" "${inverse}"
   ./create-set.sh 8 "${file}" > "${SETSDIR}/isnumeric${suffix}.inc" "${inverse}"

   ./create-category-set.sh 'M.' "${file}" > "${SETSDIR}/isnonbase${suffix}.inc" "${inverse}"
   ./create-category-set.sh 'Ll' "${file}" > "${SETSDIR}/islowercase${suffix}.inc" "${inverse}"
   ./create-category-set.sh 'L[ut]' "${file}" > "${SETSDIR}/isuppercase${suffix}.inc" "${inverse}"
   ./create-category-set.sh '[LMN].' "${file}" > "${SETSDIR}/isalphanumeric${suffix}.inc" "${inverse}"
   ./create-category-set.sh 'Lt' "${file}" > "${SETSDIR}/iscapitalized${suffix}.inc" "${inverse}"
   ./create-category-set.sh '[LM].' "${file}" > "${SETSDIR}/isletter${suffix}.inc" "${inverse}"
   ./create-category-set.sh 'P.' "${file}" > "${SETSDIR}/ispunctuation${suffix}.inc" "${inverse}"
   ./create-category-set.sh 'S.' "${file}" > "${SETSDIR}/issymbol${suffix}.inc" "${inverse}"
   ./create-category-set.sh 'C[cf]' "${file}" > "${SETSDIR}/iscontrol${suffix}.inc" "${inverse}"
   ./create-category-set.sh 'Z.' "${file}" > "${SETSDIR}/iswhitespace${suffix}.inc" "${inverse}"

   ./create-category-set.sh 'Co' "${file}" > "${SETSDIR}/isprivate${suffix}.inc" "${inverse}"
   ./create-category-set.sh 'Z[slp]' "${file}" > "${SETSDIR}/isseparator${suffix}.inc" "${inverse}"
}


UTF16FILE=utf16.txt
UTF32FILE=utf32.txt

# https://unix.stackexchange.com/questions/11305/grep-show-all-the-file-up-to-the-match

set -e
sed '/^FFFD;/q' "${FILE}" > "${UTF16FILE}"
sed -n '/^10000/,$ p' "${FILE}" > "${UTF32FILE}"

create_dirs
create_map_files "${UTF16FILE}" "-utf16"
create_map_files "${UTF32FILE}" "-utf32"

create_set_files "${UTF16FILE}" "-utf16"
create_set_files "${UTF32FILE}" "-utf32"
create_set_files "${UTF16FILE}" "-utf16-inv" "YES"
create_set_files "${UTF32FILE}" "-utf32-inv" "YES"

rm "${UTF16FILE}" "${UTF32FILE}"

