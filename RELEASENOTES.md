# 0.1

* started versioning

* changed the callback scheme to a uniform `add`. This is nice,
  because by default the utf routines will use host order. If you want
  to have flipped output just change the `add`routine.

* renamed mulle_utf8char_t and friends to mulle_utf8_t 