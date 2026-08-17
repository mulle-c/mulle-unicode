# Fuzzing mulle-unicode

## Prerequisites

- clang with libFuzzer support (usually `clang` >= 6.0)
- The project must be crafted first (`mulle-sde craft`)

## Quick start

```bash
cd /path/to/mulle-unicode
fuzz/mulle-unicode-fuzz build
fuzz/mulle-unicode-fuzz run -t 300
```

## Targets

| Target | What it tests |
|--------|---------------|
| `fuzz-ctype` | All `is_*` predicates: no crashes on arbitrary code points, newline ⊂ whitespaceornewline, idstart ⊂ idcont, 16/32-bit agreement for BMP |
| `fuzz-conversion` | `tolower`, `toupper`, `totitlecase`: no crashes, idempotence (`tolower(tolower(c)) == tolower(c)`), `tolower(toupper(c)) == tolower(c)`, 16/32-bit agreement for BMP |

## Commands

```
fuzz/mulle-unicode-fuzz build [target...]     Build fuzzer binaries
fuzz/mulle-unicode-fuzz run [target...]       Run fuzzers (default 60s each)
fuzz/mulle-unicode-fuzz run -t 600            Run each target for 600 seconds
fuzz/mulle-unicode-fuzz --max-total-time 120  Split time budget across targets
fuzz/mulle-unicode-fuzz replay <target> <in>  Replay a crash input
fuzz/mulle-unicode-fuzz clean                 Remove build artifacts
fuzz/mulle-unicode-fuzz list                  List available targets
```

## Crash triage

Crash inputs are saved under `fuzz/crashes/<target>/`. To reproduce:

```bash
fuzz/mulle-unicode-fuzz replay fuzz-ctype fuzz/crashes/fuzz-ctype/crash-...
```
