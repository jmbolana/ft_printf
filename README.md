 *This project has been created as part of the 42 curriculum by jmbolana.*

## Description

The **ft_printf** project consists of recoding the famous `printf` function from the standard C library. The primary goal is to learn how to handle a variable number of arguments using **variadic functions** in C, while strengthening the understanding of format management and output buffers.

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

1. **Clone the project into your project directory by using this command:**
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

4. **Return into your current project directory:**
```bash
cd ../
```
### Compilation
1. **Include this headers in your c files:**
```c
# include "includes/ft_printf.h"
```
2. **Comiple your code using those flags:**
```bash
cc -Wall -Wextra -Werror your_c_file.c -Iincludes -Lincludes -lftprintf -o your_program_name
```
* **-Iinclude:** Tells the preprocessor where to find the `ft_printf.h` file to validate your functions in the source code.

* **-Linclude:** Tells the linker where to look for the `libftprintf.a` file to build the final executable.

* **-lftprintf:** Tells the linker the name of the library to load (it will automatically search for a file starting with `lib` and ending with `.a`).