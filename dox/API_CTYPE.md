# ctype


## Detection

UTF32 detection routines are uniformly prefixed with `mulle_utf32_is_` and
take a sole `mulle_utf32_t` argument. UTF16 detection routines are uniformly
prefixed with `mulle_utf16_is_` and take a sole `mulle_utf16_t` argument.

E.g.

`alphanumeric` is `int  mulle_utf32_is_alphanumeric( mulle_utf32_t c)` and
`int  mulle_utf16_is_alphanumeric( mulle_utf16_t c)`


### Unicode 3.0 Detection

The naming and the semantics are derived from the
[Unicode 3.0](http://unicode.org/versions/Unicode3.0.0/)
specification.


Name                 | Description
---------------------|--------------------------------------------------
alphanumeric         | UNICODE alphanumeric
capitalized          | UNICODE capitalized
control              | UNICODE control
decimaldigit         | UNICODE decimaldigit
decomposable         | UNICODE decomposable
letter               | UNICODE letter
lowercase            | UNICODE lowercase
nonbase              | UNICODE nonbase
nonpercentescape     | UNICODE nonpercentescape
privatecharacter     | UNICODE privatecharacter
punctuation          | UNICODE punctuation
symbol               | UNICODE symbol
uppercase            | UNICODE uppercase


### Custom Unicode Detection

These are based in UNICODE but are extended for usability.

Name                 | Description
---------------------|--------------------------------------------------
noncharacter         | The UNICODE noncharacters plus all surrogates plus the last two codepoints of a bitplane
newline              | 0xa, 0xb, 0xc, 0xd, 0x85, 0x2028, 0x2029
whitespace           | The UNICODE whitespaces plus 0x9
whitespaceornewline  | The UNICODE whitespaces plus 0x9, 0xb, 0xc, 0xd, 0x85


## URL characters Detection

These are characters that are valid in various parts of URLs.

`scheme`://`user`:`password`@`host`/`path`#`fragment`?`query`


Name                 | Description
---------------------|--------------------------------------------------
validurlfragment     | Allowable characters in fragment part of URL
validurlhost         | Allowable characters in host part of URL
validurlpassword     | Allowable characters in password part of URL
validurlpath         | Allowable characters in path part of URL
validurlquery        | Allowable characters in query part of URL
validurlscheme       | Allowable characters in scheme part of URL
validurluser         | Allowable characters in user part of URL


## Conversion

UTF32 character conversion routines are uniformly prefixed with
`mulle_utf32_` and take  a sole `mulle_utf32_t` argument.
The return value is `mulle_utf32_t`.

UTF16 character
conversion routines are uniformly prefixed with `mulle_utf16_` and take
a sole `mulle_utf16_t` argument. The return value is `mulle_utf16_t`.

E.g.

`tolower` is `mulle_utf32_t  mulle_utf32_tolower( mulle_utf32_t c)` and
`mulle_utf16_t  mulle_utf16_tolower( mulle_utf16_t c)`


Name                 | Description
---------------------|--------------------------------------------------
tolower              | Convert to lowercase from uppercase, returns argument, if no conversion is possible.
totitlecase          | Convert to [titlecase](http://unicode.org/faq/casemap_charprop.html#4). returns argument, if no conversion is possible.
toupper              | Convert to uppercase from lowercase, returns argument, if no conversion is possible.

