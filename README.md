*This project has been created as part of the 42 curriculum by jvan-ges.*

# ft_printf

## Description

`ft_printf` recodes the `printf()` function of the C standard library.
The goal of the project is to learn how variadic functions work in C
(`va_start`, `va_arg`, `va_copy`, `va_end`) and to write a well-structured,
extensible program.

The function is built as a static library, `libftprintf.a`, with the prototype:

```c
int ft_printf(const char *format, ...);
```

It supports the following conversions:

| Conversion | Description                                  |
|------------|----------------------------------------------|
| `%c`       | Single character                             |
| `%s`       | String (`(null)` is printed for `NULL`)      |
| `%p`       | Pointer address in hexadecimal (`0x...`)     |
| `%d` / `%i`| Signed decimal integer                       |
| `%u`       | Unsigned decimal integer                     |
| `%x` / `%X`| Hexadecimal integer (lower/upper case)       |
| `%%`       | A literal percent sign                       |

Like the original `printf()`, `ft_printf()` returns the total number of
characters written to the standard output.

## Algorithm and design choices

The implementation follows three steps:

1. **Parsing loop**: the format string is walked character by character.
   Plain characters are written directly; a `%` followed by a specifier
   is dispatched to the matching conversion function.
2. **Dispatch**: a single `if/else` chain maps each specifier to a small,
   dedicated function. This keeps `ft_printf` readable and makes it easy
   to add new conversions later (the key to a future bonus part).
3. **Number printing**: numbers are converted to digits by a recursive
   routine — divide by the base until only one digit remains, then print
   the remainders while the recursion unwinds. No heap allocation is
   needed at all: everything goes straight to `write(1, ...)`.

Key details:

- Return value is accumulated: every conversion function returns how many
  characters it wrote, so the final `count` matches the real `printf()`.
- `INT_MIN` is handled by storing the value in a `long` before negation
  (`-INT_MIN` overflows an `int`).
- Recursion was chosen over iterative buffers: it is shorter, avoids
  `malloc` entirely, and therefore eliminates any memory-leak risk.
- Function selection via an `if/else` chain was preferred over a lookup
  table of function pointers: with only 9 specifiers it is simpler to
  read and fully Norm-compliant.

## Instructions

```sh
make        # builds libftprintf.a at the root
make clean  # removes object files
make fclean # removes object files and the library
make re     # full rebuild
```

Usage in another program:

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Score: %d, player: %s\n", 42, "john");
	return (0);
}
```

```sh
cc -Wall -Wextra -Werror main.c libftprintf.a -I . && ./a.out
```

## Resources

- `man 3 printf` — reference behavior of the original function
- `man 3 stdarg` — variadic function macros (`va_start`, `va_arg`, ...)
- [cppreference - variadic functions](https://en.cppreference.com/w/c/variadic)
- [cppreference - printf format](https://en.cppreference.com/w/c/io/fprintf)

### AI usage

Claude was used to generate the initial implementation of the mandatory
part (source files, Makefile and this README), then reviewed and tested
line by line by the author. AI was not used to bypass understanding:
the design decisions documented above were studied and can be explained
by the author.
