#! /bin/sh
# 0 charcode
# 6 decimal digit
# 7 Digit
# 8 numeric

CATEGORY="${1:-L[ult]}"
FILE="${2:-UnicodeData.txt}"
INVERSE="$3"  # use !d for inverse


set -e

if [ -z "${INVERSE}" ]
then
   DELETE='d'
else
   DELETE='!d'
   INVERSE="-v"
fi

# Normative Categories

# Description
# Lu    Letter, Uppercase
# Ll    Letter, Lowercase
# Lt    Letter, Titlecase
# Mn    Mark, Non-Spacing
# Mc    Mark, Spacing Combining
# Me    Mark, Enclosing
# Nd    Number, Decimal Digit
# Nl    Number, Letter
# No    Number, Other
# Zs    Separator, Space
# Zl    Separator, Line
# Zp    Separator, Paragraph
# Cc    Other, Control
# Cf    Other, Format
# Cs    Other, Surrogate
# Co    Other, Private Use
# Cn    Other, Not Assigned (no characters in the file have this property)

# Informative Categories

# Description
# Lm    Letter, Modifier
# Lo    Letter, Other
# Pc    Punctuation, Connector
# Pd    Punctuation, Dash
# Ps    Punctuation, Open
# Pe    Punctuation, Close
# Pi    Punctuation, Initial quote (may behave like Ps or Pe depending on usage)
# Pf    Punctuation, Final quote (may behave like Ps or Pe depending on usage)
# Po    Punctuation, Other
# Sm    Symbol, Math
# Sc    Symbol, Currency
# Sk    Symbol, Modifier
# So    Symbol, Other

# 13 is just the inverse of 12, as field 13 is not specified ?

cut '-d;' -f 1,3 "${FILE}" | \
grep ${INVERSE} ";${CATEGORY}" |
sed 's/\(.*\);.*/   case 0x\1 :/'
