# mulle-unicode Library Documentation for AI
<!-- Keywords: unicode, character-classification -->

## 1. Introduction & Purpose

mulle-unicode is a comprehensive Unicode character classification and conversion library for C99, based on Unicode 3.0.0 specification. It provides ctype-like functionality for classifying characters (letters, digits, punctuation, etc.) and converting between cases (uppercase, lowercase, titlecase) for the full Unicode range (0x0 to 0x10FFFF). The library uses efficient table-based lookups compiled from official Unicode data, enabling fast single-character operations without external dependencies. This is a foundational utility in the mulle-c ecosystem for text processing and Unicode-aware applications.

## 2. Key Concepts & Design Philosophy

**Design Principles:**

- **Unicode Specification Compliance:** Data derives from official Unicode 3.0.0 character database; properties follow Unicode standard definitions.

- **Dual-Width Support:** Provides separate functions for UTF-16 (uint16_t) and UTF-32 (int32_t) characters, enabling efficient processing of different Unicode representations.

- **Table-Driven Classification:** Character properties are stored in efficient lookup tables, enabling O(1) classification regardless of character code point.

- **Plane-Based Organization:** Characters are organized by Unicode planes; plane query functions enable optimization and validation.

- **Compact Binary:** Despite comprehensive Unicode support, the library compiles to ~256KB binary size through efficient table compression.

- **No External Dependencies:** Pure C99, depends only on mulle-c11 for compatibility macros; minimal external dependencies.

- **Stateless Functions:** All functions are pure; no global state or side effects enable safe concurrent use.

## 3. Core API & Data Structures

### 3.1 Character Classification Functions

All classification functions return `int` (0 for false, non-zero for true).

#### `mulle-unicode-is-letter.h`

**`int mulle_unicode_is_letter(int32_t c)`**
- **Purpose:** Test if character is a letter (L* categories in Unicode).
- **Parameters:** `c`: UTF-32 character code.
- **Returns:** Non-zero if letter, 0 otherwise.

**`int mulle_unicode16_is_letter(uint16_t c)`**
- **Purpose:** Test if UTF-16 character is a letter.
- **Parameters:** `c`: UTF-16 character code.

**`int mulle_unicode_is_letterplane(unsigned int plane)`**
- **Purpose:** Query if a Unicode plane contains letters.
- **Parameters:** `plane`: Plane number (0-16).
- **Returns:** Non-zero if plane contains letters.

#### `mulle-unicode-is-uppercase.h`

**`int mulle_unicode_is_uppercase(int32_t c)`**
- **Purpose:** Test if character is uppercase.
- **Parameters:** `c`: UTF-32 character code.

**`int mulle_unicode16_is_uppercase(uint16_t c)`**
- **Purpose:** Test if UTF-16 character is uppercase.

#### `mulle-unicode-is-lowercase.h`

**`int mulle_unicode_is_lowercase(int32_t c)`**
- **Purpose:** Test if character is lowercase.
- **Parameters:** `c`: UTF-32 character code.

**`int mulle_unicode16_is_lowercase(uint16_t c)`**
- **Purpose:** Test if UTF-16 character is lowercase.

#### `mulle-unicode-is-capitalized.h`

**`int mulle_unicode_is_capitalized(int32_t c)`**
- **Purpose:** Test if character is capitalized (titlecase).
- **Parameters:** `c`: UTF-32 character code.

**`int mulle_unicode16_is_capitalized(uint16_t c)`**
- **Purpose:** Test if UTF-16 character is capitalized.

#### `mulle-unicode-is-alphanumeric.h`

**`int mulle_unicode_is_alphanumeric(int32_t c)`**
- **Purpose:** Test if character is alphanumeric (letter or digit).
- **Parameters:** `c`: UTF-32 character code.

**`int mulle_unicode16_is_alphanumeric(uint16_t c)`**
- **Purpose:** Test if UTF-16 character is alphanumeric.

#### `mulle-unicode-is-decimaldigit.h`

**`int mulle_unicode_is_decimaldigit(int32_t c)`**
- **Purpose:** Test if character is a decimal digit (0-9 equivalent).
- **Parameters:** `c`: UTF-32 character code.

**`int mulle_unicode16_is_decimaldigit(uint16_t c)`**
- **Purpose:** Test if UTF-16 character is decimal digit.

#### `mulle-unicode-is-zerodigit.h`

**`int mulle_unicode_is_zerodigit(int32_t c)`**
- **Purpose:** Test if character is zero-like (U+0030 '0', U+FF10 '０', etc.).
- **Parameters:** `c`: UTF-32 character code.

**`int mulle_unicode16_is_zerodigit(uint16_t c)`**
- **Purpose:** Test if UTF-16 character is zero-like.

#### `mulle-unicode-is-whitespace.h`

**`int mulle_unicode_is_whitespace(int32_t c)`**
- **Purpose:** Test if character is whitespace (space separators).
- **Parameters:** `c`: UTF-32 character code.
- **Includes:** Space, tab, and other space separators, excluding newlines.

**`int mulle_unicode16_is_whitespace(uint16_t c)`**
- **Purpose:** Test if UTF-16 character is whitespace.

#### `mulle-unicode-is-whitespaceornewline.h`

**`int mulle_unicode_is_whitespaceornewline(int32_t c)`**
- **Purpose:** Test if character is whitespace or newline.
- **Parameters:** `c`: UTF-32 character code.

**`int mulle_unicode16_is_whitespaceornewline(uint16_t c)`**
- **Purpose:** Test if UTF-16 character is whitespace or newline.

#### `mulle-unicode-is-newline.h`

**`int mulle_unicode_is_newline(int32_t c)`**
- **Purpose:** Test if character is a newline/line-break character.
- **Parameters:** `c`: UTF-32 character code.

**`int mulle_unicode16_is_newline(uint16_t c)`**
- **Purpose:** Test if UTF-16 character is newline.

#### `mulle-unicode-is-punctuation.h`

**`int mulle_unicode_is_punctuation(int32_t c)`**
- **Purpose:** Test if character is punctuation (P* categories).
- **Parameters:** `c`: UTF-32 character code.

**`int mulle_unicode16_is_punctuation(uint16_t c)`**
- **Purpose:** Test if UTF-16 character is punctuation.

#### `mulle-unicode-is-symbol.h`

**`int mulle_unicode_is_symbol(int32_t c)`**
- **Purpose:** Test if character is a symbol (S* categories: math, currency, modifier, etc.).
- **Parameters:** `c`: UTF-32 character code.

**`int mulle_unicode16_is_symbol(uint16_t c)`**
- **Purpose:** Test if UTF-16 character is symbol.

#### `mulle-unicode-is-control.h`

**`int mulle_unicode_is_control(int32_t c)`**
- **Purpose:** Test if character is control character (Cc category).
- **Parameters:** `c`: UTF-32 character code.

**`int mulle_unicode16_is_control(uint16_t c)`**
- **Purpose:** Test if UTF-16 character is control character.

#### `mulle-unicode-is-nonbase.h`

**`int mulle_unicode_is_nonbase(int32_t c)`**
- **Purpose:** Test if character is combining/non-spacing mark.
- **Parameters:** `c`: UTF-32 character code.

**`int mulle_unicode16_is_nonbase(uint16_t c)`**
- **Purpose:** Test if UTF-16 character is non-base.

#### `mulle-unicode-is-decomposable.h`

**`int mulle_unicode_is_decomposable(int32_t c)`**
- **Purpose:** Test if character can be decomposed into multiple characters.
- **Parameters:** `c`: UTF-32 character code.

**`int mulle_unicode16_is_decomposable(uint16_t c)`**
- **Purpose:** Test if UTF-16 character is decomposable.

#### `mulle-unicode-is-legalcharacter.h`

**`int mulle_unicode_is_legalcharacter(int32_t c)`**
- **Purpose:** Test if character is legal/valid Unicode.
- **Parameters:** `c`: UTF-32 character code.
- **Note:** Distinguishes valid characters from reserved/undefined ones.

**`int mulle_unicode16_is_legalcharacter(uint16_t c)`**
- **Purpose:** Test if UTF-16 character is legal.

#### `mulle-unicode-is-noncharacter.h`

**`int mulle_unicode_is_noncharacter(int32_t c)`**
- **Purpose:** Test if character is designated non-character (Cn category).
- **Parameters:** `c`: UTF-32 character code.

**`int mulle_unicode16_is_noncharacter(uint16_t c)`**
- **Purpose:** Test if UTF-16 character is non-character.

#### `mulle-unicode-is-identifierstart.h`

**`int mulle_unicode_is_identifierstart(int32_t c)`**
- **Purpose:** Test if character is valid identifier start (letters, underscore).
- **Parameters:** `c`: UTF-32 character code.

**`int mulle_unicode16_is_identifierstart(uint16_t c)`**
- **Purpose:** Test if UTF-16 character can start an identifier.

#### `mulle-unicode-is-identifiercontinuation.h`

**`int mulle_unicode_is_identifiercontinuation(int32_t c)`**
- **Purpose:** Test if character is valid inside identifier (letters, digits, underscore, marks).
- **Parameters:** `c`: UTF-32 character code.

**`int mulle_unicode16_is_identifiercontinuation(uint16_t c)`**
- **Purpose:** Test if UTF-16 character can continue an identifier.

### 3.2 Character Conversion Functions

#### `mulle-unicode-tolower.h`

**`int32_t mulle_unicode_tolower(int32_t c)`**
- **Purpose:** Convert character to lowercase.
- **Parameters:** `c`: UTF-32 character code.
- **Returns:** Lowercase equivalent (returns `c` unchanged if no lowercase form exists).

**`uint16_t mulle_unicode16_tolower(uint16_t c)`**
- **Purpose:** Convert UTF-16 character to lowercase.

**`int32_t mulle_unicode_nop(int32_t c)`** / **`uint16_t mulle_unicode16_nop(uint16_t c)`**
- **Purpose:** No-op conversion functions (return character unchanged). Useful as callback placeholders.

#### `mulle-unicode-toupper.h`

**`int32_t mulle_unicode_toupper(int32_t c)`**
- **Purpose:** Convert character to uppercase.
- **Parameters:** `c`: UTF-32 character code.
- **Returns:** Uppercase equivalent (returns `c` unchanged if no uppercase form exists).

**`uint16_t mulle_unicode16_toupper(uint16_t c)`**
- **Purpose:** Convert UTF-16 character to uppercase.

**`int32_t mulle_unicode_totitlecase(int32_t c)`**
- **Purpose:** Convert character to titlecase (capitalized).
- **Parameters:** `c`: UTF-32 character code.
- **Returns:** Titlecase equivalent.

**`uint16_t mulle_unicode16_totitlecase(uint16_t c)`**
- **Purpose:** Convert UTF-16 character to titlecase.

## 4. Performance Characteristics

- **Classification Time:** O(1) table lookup per character, typically 1-2 CPU cycles.
- **Conversion Time:** O(1) table lookup per character.
- **Memory:** ~256KB total binary size for full Unicode support.
- **Cache Efficiency:** Small lookup tables fit in L1/L2 cache for fast repeated access.
- **Parallelization:** Functions are thread-safe (no global state modification).

**Characteristics:**

- No allocations; stack/register use only.
- No conditional branches (table-driven).
- Suitable for high-performance text processing.

## 5. AI Usage Recommendations & Patterns

### Best Practices:

1. **Use UTF-32 for Full Unicode:** Use `int32_t` versions for complete Unicode support (0x0-0x10FFFF). UTF-16 functions handle BMP only.

2. **Validate Character Values:** Before processing unknown input, use `mulle_unicode_is_legalcharacter()` to exclude invalid codes.

3. **Cache Plane Information:** If processing large text with same plane, query plane properties first with `_plane` functions.

4. **Identifier Validation:** Use dedicated identifier functions (`identifierstart`, `identifiercontinuation`) rather than generic letter/digit checks for parsing.

5. **Batch Processing:** Process character-by-character through arrays of code points for optimal cache behavior.

### Common Pitfalls:

1. **UTF-16 Limitations:** UTF-16 functions only handle characters in the Basic Multilingual Plane (BMP); supplementary planes are truncated.

2. **Assuming ASCII Equivalence:** Unicode character properties may differ from ASCII expectations (e.g., not all uppercase letters have lowercase).

3. **Decomposition Expectations:** `is_decomposable()` indicates compatibility decomposition; don't assume canonical decomposition.

4. **Case Conversion Expectations:** Case conversion is per-character; no context-aware handling (Turkish 'i', German 'ß' → 'ss').

5. **Plane Overflow:** Passing values > 0x10FFFF to classification functions yields undefined behavior; validate input ranges.

### Idiomatic Usage:

```c
// Check if string can be identifier
int is_valid_identifier(const int32_t *chars, size_t len) {
    if (len == 0 || !mulle_unicode_is_identifierstart(chars[0]))
        return 0;
    for (size_t i = 1; i < len; i++)
        if (!mulle_unicode_is_identifiercontinuation(chars[i]))
            return 0;
    return 1;
}

// Convert string to lowercase
void to_lowercase(int32_t *chars, size_t len) {
    for (size_t i = 0; i < len; i++)
        chars[i] = mulle_unicode_tolower(chars[i]);
}

// Classify and process by type
void process_text(const int32_t *chars, size_t len) {
    for (size_t i = 0; i < len; i++) {
        int32_t c = chars[i];
        if (mulle_unicode_is_letter(c))
            process_letter(c);
        else if (mulle_unicode_is_digit(c))
            process_digit(c);
        else if (mulle_unicode_is_whitespace(c))
            process_whitespace(c);
        else if (mulle_unicode_is_punctuation(c))
            process_punctuation(c);
    }
}
```

## 6. Integration Examples

### Example 1: Character Classification Loop

```c
#include <mulle-unicode/mulle-unicode.h>
#include <stdio.h>
#include <stdint.h>

int main() {
    int32_t chars[] = {
        'A', 'a', '1', ' ', '@', '\n',
        0x00C9,  // É
        0x03B1,  // α (Greek alpha)
        0x0E01,  // ก (Thai character)
    };
    
    for (int i = 0; i < 9; i++) {
        int32_t c = chars[i];
        printf("U+%04X: ", c);
        
        if (mulle_unicode_is_letter(c))
            printf("LETTER ");
        if (mulle_unicode_is_digit(c))
            printf("DIGIT ");
        if (mulle_unicode_is_whitespace(c))
            printf("WHITESPACE ");
        if (mulle_unicode_is_control(c))
            printf("CONTROL ");
        if (mulle_unicode_is_punctuation(c))
            printf("PUNCT ");
        
        printf("\n");
    }
    
    return 0;
}
```

### Example 2: Case Conversion

```c
#include <mulle-unicode/mulle-unicode.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

void print_conversions(int32_t c) {
    printf("U+%04X: ", c);
    printf("Upper=%c, Lower=%c, Title=%c\n",
           (char)mulle_unicode_toupper(c),
           (char)mulle_unicode_tolower(c),
           (char)mulle_unicode_totitlecase(c));
}

int main() {
    print_conversions('a');
    print_conversions('Z');
    print_conversions('1');
    
    return 0;
}
```

### Example 3: Identifier Validation

```c
#include <mulle-unicode/mulle-unicode.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

int is_valid_identifier(const int32_t *str, size_t len) {
    if (len == 0)
        return 0;
    
    if (!mulle_unicode_is_identifierstart(str[0]))
        return 0;
    
    for (size_t i = 1; i < len; i++) {
        if (!mulle_unicode_is_identifiercontinuation(str[i]))
            return 0;
    }
    
    return 1;
}

int main() {
    int32_t id1[] = { '_', 'v', 'a', 'r', '1' };
    int32_t id2[] = { '1', '_', 'v', 'a', 'r' };
    int32_t id3[] = { 'm', 'y', '_', 'I', 'd' };
    
    printf("_var1: %s\n", is_valid_identifier(id1, 5) ? "valid" : "invalid");
    printf("1_var: %s\n", is_valid_identifier(id2, 5) ? "valid" : "invalid");
    printf("my_Id: %s\n", is_valid_identifier(id3, 5) ? "valid" : "invalid");
    
    return 0;
}
```

### Example 4: Text Transformation Pipeline

```c
#include <mulle-unicode/mulle-unicode.h>
#include <stdio.h>
#include <stdint.h>

void transform_text(int32_t *text, size_t len) {
    for (size_t i = 0; i < len; i++) {
        int32_t c = text[i];
        
        // Remove non-printing characters
        if (!mulle_unicode_isprint(c)) {
            text[i] = ' ';
            continue;
        }
        
        // Convert to lowercase
        if (mulle_unicode_is_uppercase(c)) {
            text[i] = mulle_unicode_tolower(c);
        }
    }
}

int main() {
    int32_t text[] = {
        'H', 'e', 'l', 'l', 'o', 0x0009, 'W', 'O', 'R', 'L', 'D'
    };
    
    printf("Before transformation:\n");
    for (int i = 0; i < 11; i++)
        printf("%c", (char)text[i]);
    printf("\n");
    
    transform_text(text, 11);
    
    printf("After transformation:\n");
    for (int i = 0; i < 11; i++)
        printf("%c", (char)text[i]);
    printf("\n");
    
    return 0;
}
```

### Example 5: Character Statistics

```c
#include <mulle-unicode/mulle-unicode.h>
#include <stdio.h>
#include <stdint.h>

typedef struct {
    int letters;
    int digits;
    int whitespace;
    int punctuation;
    int symbols;
    int other;
} CharStats;

CharStats analyze_text(const int32_t *text, size_t len) {
    CharStats stats = {0};
    
    for (size_t i = 0; i < len; i++) {
        int32_t c = text[i];
        
        if (mulle_unicode_is_letter(c))
            stats.letters++;
        else if (mulle_unicode_is_digit(c))
            stats.digits++;
        else if (mulle_unicode_is_whitespaceornewline(c))
            stats.whitespace++;
        else if (mulle_unicode_is_punctuation(c))
            stats.punctuation++;
        else if (mulle_unicode_is_symbol(c))
            stats.symbols++;
        else
            stats.other++;
    }
    
    return stats;
}

int main() {
    int32_t text[] = {
        'H', 'e', 'l', 'l', 'o', ',', ' ',
        'W', 'o', 'r', 'l', 'd', '!', ' ',
        '1', '2', '3', 0x00A9  // © symbol
    };
    
    CharStats stats = analyze_text(text, 18);
    printf("Letters: %d\n", stats.letters);
    printf("Digits: %d\n", stats.digits);
    printf("Whitespace: %d\n", stats.whitespace);
    printf("Punctuation: %d\n", stats.punctuation);
    printf("Symbols: %d\n", stats.symbols);
    
    return 0;
}
```

### Example 6: UTF-16 Processing

```c
#include <mulle-unicode/mulle-unicode.h>
#include <stdio.h>
#include <stdint.h>

int main() {
    uint16_t utf16_text[] = {
        'H', 'i', 0x00E9,  // é in UTF-16 (BMP)
        '!'
    };
    
    for (int i = 0; i < 4; i++) {
        uint16_t c = utf16_text[i];
        printf("U+%04X: ", c);
        
        if (mulle_unicode16_is_letter(c))
            printf("LETTER ");
        if (mulle_unicode16_is_lowercase(c))
            printf("LOWER ");
        if (mulle_unicode16_is_punctuation(c))
            printf("PUNCT ");
        
        printf("-> upper: U+%04X\n",
               (uint16_t)mulle_unicode16_toupper(c));
    }
    
    return 0;
}
```

## 7. Dependencies

Direct mulle-sde dependencies:
- `mulle-c11`: C11 compatibility macros and utilities for cross-platform support
