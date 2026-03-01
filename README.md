 *This project has been created as part of the 42 curriculum by jmbolana.*

## Description

The **ft_printf** project consists of reimplementing the famous `printf` function from the standard C library. The primary goal is to learn how to handle a variable number of arguments using **variadic functions** in C, while strengthening the understanding of format management and output buffers.

### Objectives
* **Recreating formatting logic**: Analyzing a character string to identify specifiers (e.g., `%s`, `%d`, `%p`).
* **Handling variable arguments**: Using the `<stdarg.h>` library (`va_start`, `va_arg`, `va_copy`, `va_end`).
* **Code optimization**: Producing a robust and efficient `libftprintf.a` library capable of handling base conversions in an extensible manner.

### Feature Overview
My version of `ft_printf` handles the following conversions:

| Specifier | Description |
| :--- | :--- |
| `%c` | Prints a single character. |
| `%s` | Prints a string of characters. |
| `%p` | Prints a pointer in hexadecimal format. |
| `%d` / `%i` | Prints a signed decimal integer. |
| `%u` | Prints an unsigned decimal integer. |
| `%x` / `%X` | Prints a number in hexadecimal (lowercase/uppercase). |
| `%%` | Prints a percent sign. |

## Instructions

### Installation
To use `ft_printf` in your own C projects, follow these steps:

1. **Clone the Git repo into your project directory by using this command:**
```bash
git clone git@github.com:jmbolana/ft_printf.git includes
```

2. **Enter the cloned repository:**
```bash
cd ft_printf
```

### Compilation
The project is managed by a **Makefile** that includes the standard rules: `all`, `clean`, `fclean`, and `re`. To compile the library, navigate to the project's root and run:

```bash
make
```
This will create the static library `libftprintf.a` in the current directory.

4. **Return to your current project directory:**
```bash
cd ../
```
### Execution
1. **Include these headers in your C files where you use the `ft_printf` function:**
```c
#include "includes/ft_printf.h"
```
2. **Compile your code using the following flags:**
```bash
cc -Wall -Wextra -Werror your_c_file.c -Iincludes -Lincludes -lftprintf -o your_program_name
```
* **-Iinclude:** Tells the preprocessor where to find the `ft_printf.h` file to validate your functions in the source code.

* **-Linclude:** Tells the linker where to look for the `libftprintf.a` file to build the final executable.

* **-lftprintf:** Tells the linker the name of the library to load (it will automatically search for a file starting with `lib` and ending with `.a`).

## Resources

To deepen your understanding of the `ft_printf` project and C programming in general, here are some essential references:

### Documentation & Articles
* **The 42 Subject:** The primary source of truth for project requirements and constraints.

* The official documentation for the standard printf function and its specifiers. (click this <a href="https://fr.manpages.org/printf">link</a> to view the documentation)


* A classic deep-dive article into how printf works under the hood.

## Explanation and justification of the chosen algorithm and data structure
The implementation of `ft_printf` relies on a combination of Variadic Functions and a Linear Scanning and Dispatch approach.

1. **The Core Algorithm: Linear Scanning and Dispatch**

The engine of the function is a single-pass loop that iterates through the format string. The logic follows these steps:
* **Sequential Reading:** The function reads each character of the string one by one.
* **Literal Output:** If the character is not a `%`, it is written directly to the standard output.
* **Specifier Detection:** When a `%` is encountered, the algorithm "traps" the next character to identify the required conversion (e.g., `s`, `d`, `x`).
* **Function Dispatch:** Based on the specifier, the program calls a specific sub-function (e.g., `ft_putstr`, `ft_putnbr_hex`) to handle that data type.

2. **Data Structure: Variadic Arguments (`va_list`)**

Since `printf` must handle an unknown number of arguments of varying types, the project utilizes the `va_list` structure from the `<stdarg.h>` library.

* **Justification:** This is the only standard way in C to handle a variable number of arguments. It provides a pointer-like mechanism to navigate the stack where the arguments are stored during the function call.
* **Efficiency:** Using `va_arg` allows us to access each argument in $O(1)$ time complexity as we move through the format string.

3. **Sub-Algorithms: Recursion for Number Conversion**

For specifiers like `%d`, `%u`, and `%x`, a recursive algorithm is used for base conversion and printing.

* **The Logic:** The number is divided by its base (10 for decimal, 16 for hex) until the quotient is 0. As the recursion unwinds, the remainders are converted to characters and printed in the correct order (Most Significant Digit to Least Significant Digit).

* **Memory Impact:** While recursion uses the stack, the depth is limited to the maximum number of digits in a 64-bit integer (approximately 20 for decimal), making it safe and memory-efficient for this scale.

## Summary Table of all the files that have been used in this poroject
| File Name        | Principal Function | External Functions Used                                                   | Function Description                                      | Used In                         | Return Value |
|------------------|-------------------|---------------------------------------------------------------------------|-----------------------------------------------------------|----------------------------------|-------------|
| ft_printf.c      | `ft_printf`       | `va_start`, `va_arg`, `va_end`, `ft_putchar`, `ft_isvalid`, `ft_format`  | Main entry point parsing the format string.               | User calls                      | Total number of characters printed (or -1 if format is NULL). |
| ft_format.c      | `ft_format`       | `ft_putchar`, `ft_putstr`, `ft_putnbr`, `ft_putunsigned`, `ft_putptr`, `ft_puthex`, `va_arg` | Dispatches the correct function based on the specifier.  | `ft_printf`                     | Number of characters printed for the specific conversion. |
| ft_isvalid.c     | `ft_isvalid`      | None                                                                      | Checks if a character is a valid conversion specifier.    | `ft_printf`                     | `1` if valid, `0` if not. |
| ft_putchar.c     | `ft_putchar`      | `write`                                                                   | Writes a single character to STDOUT.                      | Multiple                        | Always `1`. |
| ft_putstr.c      | `ft_putstr`       | `write`                                                                   | Writes a string to STDOUT; handles NULL.                  | `ft_format`, `ft_putnbr`, `ft_putptr` | Number of characters in the string (or `6` for `"(null)"`). |
| ft_putnbr.c      | `ft_putnbr`       | `ft_putchar`, `ft_putstr`                                                  | Prints a signed integer; handles `INT_MIN`.               | `ft_format`                     | Total count of digits and minus sign printed. |
| ft_putunsigned.c | `ft_putunsigned`  | `write`                                                                    | Recursively prints an unsigned integer.                   | `ft_format`                     | Total count of digits printed. |
| ft_puthex.c      | `ft_puthex`       | `write`                                                                    | Recursively prints an unsigned int in hex.                | `ft_format`                     | Total count of hex digits printed. |
| ft_putptr.c      | `ft_putptr`       | `ft_putstr`, `ft_putchar`, `ft_putnbrbase`                                 | Prints pointer address with `"0x"` prefix.                | `ft_format`                     | Total count of characters printed (including `"0x"`). |
| ft_printf.h      | N/A               | None                                                                      | Header file with prototypes and macros.                   | All `.c` files                  | N/A |
| Makefile         | `all`, `clean`, `fclean`, `re` | `cc`, `rm`, `ar`                                                | Compiles source files and creates the `libftprintf.a` library. | Developer                       | N/A |