# Conversion

mulle-utf enables you to convert back and forth between UTF8, UTF16 and UTF32.


## Functions

The conversion functions are all uniform. Only `mulle_utf8_convert_to_utf16`
is explained in more detail:


```
mulle_utf16_t  *mulle_utf8_convert_to_utf16( mulle_utf8_t *src,
                                             size_t len,
                                             struct mulle_allocator *allocator);
mulle_utf32_t  *mulle_utf8_convert_to_utf32( mulle_utf8_t *src,
                                             size_t len,
mulle_utf8_t  *mulle_utf16_convert_to_utf8( mulle_utf16_t *src,
                                            size_t len,
                                            struct mulle_allocator *allocator);
mulle_utf32_t  *mulle_utf16_convert_to_utf32( mulle_utf16_t *src,
                                              size_t len,
                                              struct mulle_allocator *allocator);

mulle_utf8_t  *mulle_utf32_convert_to_utf8( mulle_utf32_t *src,
                                            size_t len,
                                            struct mulle_allocator *allocator);
mulle_utf16_t  *mulle_utf32_convert_to_utf16( mulle_utf32_t *src,
                                             size_t len,
                                             struct mulle_allocator *allocator);
                                             struct mulle_allocator *allocator);
```

### `mulle_utf8_convert_to_utf16`

```
mulle_utf16_t  *mulle_utf8_convert_to_utf16( mulle_utf8_t *src,
                                             size_t len,
                                             struct mulle_allocator *allocator);
```

Convert up to `len` bytes of UTF8 string `src` to UTF16 in host byte order.
The returned string of `mulle_utf16_t` characters is allocated using `allocator`
and will be zero terminated for convenience. If `src` contains `\0` conversion
will stop there.

The return value will be NULL and `errno` set to `EINVAL` if `src` is not
a proper UTF8 string.

