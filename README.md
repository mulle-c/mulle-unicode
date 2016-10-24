# mulle-utf

a C (C99) library to analyze and convert unicode strings. It also contains some
limited <string.h> functionality for UTF16 and UTF32. It also contains some
fairly extensive <ctype.h> functionality for UTF16 and UTF32 based on the
Unicode 3.0.0 specification.


## Encoding strings as integers

* **mulle_char5** is a compression scheme, that uses a set of 31 characters
to encode strings into integers of varying sizes. This can be useful for small
strings with typical "identifier" names.
* **mulle_char7** is a compression scheme placing 7 bit ASCII characters into
ints of varying sizes.


> Naming: UTF is a transfer encoding for Unicode. So everything
eventually maps to (32 bit) unicode characters. That operations are done on
UTF directly is kinda questionable, but I believe common.


>> TODO (maybe): split this up into mulle_unicode, mulle_unitype, mulle_utf


## `mulle_utf_information`


### Lenient

If len is zero, then the character pointer may be NULL

### Allowed Characters

`mulle_utf` always preempts on zero chars. "ha\0ha" will have a string length
of 2 in any encoding.

`mulle_utf` does not like UTF16 surrogate pair character codes in UTF8 or
UTF32. These kind of strings are considered invalid.


### Always skips the BOM

If you use `mulle_utf32_information` and friends to figure out the lengths of
strings in various decodings, take note that the length is computed with the
BOM skipped.

Common error:

```
   ...
   mulle_utf32_information( s, len, &info);
   ...
   mulle_utf32_convert_to_utf16_bytebuffer( &buffer,
                                            (void *) mulle_buffer_add_bytes,
                                            s,
                                            len);
```

It must be coded as:

```
   mulle_utf32_convert_to_utf16_bytebuffer( &buffer,
                                            (void *) mulle_buffer_add_bytes,
                                            info.start,
                                            info.utf32len);
```

Only now is the possible BOM of the UTF32 string skipped properly and the
number of converted characters (info.utf16len) will match.


## conversion routines

* do not look for BOMs

## Author

[Nat!](//www.mulle-kybernetik.com/weblog) for
[Mulle kybernetiK](//www.mulle-kybernetik.com) and
[Codeon GmbH](//www.codeon.de)


