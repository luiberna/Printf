# ft_printf (42 Project)

A lightweight reimplementation of C's `printf` as required by the **42 ft_printf** project.

This project builds a static library, **`libftprintf.a`**, providing:

```c
int ft_printf(const char *format, ...);
```

`ft_printf` writes to **stdout** (file descriptor `1`) and returns the **number of characters written**.

---

## Supported conversions

| Specifier | Meaning | Notes |
|---|---|---|
| `%c` | character | `int` argument |
| `%s` | string | prints `(null)` if the pointer is `NULL` |
| `%p` | pointer address | prints `(nil)` if the pointer is `NULL`, otherwise `0x` + lowercase hex |
| `%d` / `%i` | signed decimal integer | `int` argument |
| `%u` | unsigned decimal integer | `unsigned int` argument |
| `%x` | unsigned hexadecimal (lowercase) | `unsigned int` argument |
| `%X` | unsigned hexadecimal (uppercase) | `unsigned int` argument |
| `%%` | literal `%` | no argument |

> Bonus flags/width/precision are not implemented in this version.

---

## Project layout

- `ft_printf.c` – core formatter loop + dispatcher
- `ft_printf.h` – public header
- Output helpers:
  - `ft_putchar.c`
  - `ft_putstr.c`
  - `ft_putnbr.c`
  - `ft_putunsigned.c`
  - `ft_puthexnbr.c`
  - `ft_putptr.c`
- `Makefile` – builds `libftprintf.a`

---

## Build

From the project folder:

```bash
make
```

This produces:

- `libftprintf.a`

Cleaning targets:

```bash
make clean   # removes .o files
make fclean  # removes .o files + libftprintf.a
make re      # rebuilds everything
```

---

## How to use

### 1) Link the library

Compile your program and link against `libftprintf.a`:

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf
```

> The `-L.` tells the compiler to search the current directory for libraries.
> `-lftprintf` links `libftprintf.a`.

### 2) Include the header

```c
#include "ft_printf.h"
```

### 3) Example

```c
#include "ft_printf.h"

int main(void)
{
    int n = 42;

    ft_printf("Hello %s! n=%d, hex=%x, ptr=%p, percent=%%\n",
              "42", n, n, &n);

    return 0;
}
```

---

## The most important part of the code

### 1) The dispatcher: `ft_translate`

The heart of this implementation is the **specifier dispatcher** in `ft_printf.c`:

- It receives a conversion character (the letter after `%`).
- It pulls the next argument using `va_arg` with the correct type.
- It forwards printing to a small helper (`ft_putchar`, `ft_putstr`, etc.).
- It returns the number of characters written for that conversion.

Conceptually:

```c
// Pseudocode (simplified)
if (c == 's') return ft_putstr(va_arg(args, char *));
if (c == 'd') return ft_putnbr(va_arg(args, int));
...
```

That return value is what lets `ft_printf` accurately sum up the total number of printed characters.

### 2) The core loop: parsing the format string

`ft_printf` iterates through the format string:

- normal characters → printed directly with `ft_putchar`
- `%` → calls the dispatcher with the next character

It keeps a running total (`res`) and returns it at the end.

### 3) Recursive number printing (small + reliable)

Conversions for numbers (`ft_putnbr`, `ft_putunsigned`, `ft_puthexnbr`) are implemented recursively:

- print higher digits first by calling the same function on `n / base`
- then print the last digit
- each call returns how many characters it wrote

This design keeps the code compact and naturally builds the output left-to-right without temporary buffers.

---

## Notes / behaviors

- **`%s` with NULL** prints `(null)`.
- **`%p` with NULL** prints `(nil)`.
- Output is done with `write(1, ...)` for compatibility with 42 constraints.
