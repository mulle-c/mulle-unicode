# 0.3

* add routines to iterate over utf8/utf16/utf32 forwards and (!) backwards
* fixed some bugs with respect to surrogate asserts in utf32

# 0.2

* removed BOM check from most routines. It is now expected that you strip
  the BOM away yourself
* added mulle_char5 encoding 
* surrogate pairs are considered non-characters in utf32 encoding 


# 0.1

* started versioning

* changed the callback scheme to a uniform `add`. This is nice,
  because by default the utf routines will use host order. If you want
  to have flipped output just change the `add`routine.

* renamed mulle_utf8char_t and friends to mulle_utf8_t 