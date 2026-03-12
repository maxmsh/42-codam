# 📖 get_next_line

*This project has been created as part of the 42 curriculum by [your_login].*

## 🎯 Description

**get_next_line** is a C function that reads and returns a single line from a file descriptor, one at a time. Each successive call continues reading from where the previous call left off, making it perfect for processing files line-by-line without loading the entire content into memory.

The challenge lies in handling variable-length lines with a fixed-size buffer while managing memory efficiently and dealing with edge cases like multiple file descriptors, empty lines, and files without trailing newlines.

This implementation uses a static variable to maintain state between function calls, allowing it to "remember" any leftover data from the previous read operation.

## ⚙️ Instructions

### Compilation

Compile the project with your own `main.c` file:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

You can adjust `BUFFER_SIZE` to any positive integer value. Smaller values mean more system calls, larger values use more memory per read.

### Usage Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

### Testing

Create a test file and run the program:

```bash
echo -e "First line\nSecond line\nThird line" > test.txt
./gnl
```

## 📚 Resources

### Documentation & References
- [Linux `read()` man page](https://man7.org/linux/man-pages/man2/read.2.html) - Understanding the read system call
- [File descriptors explained](https://en.wikipedia.org/wiki/File_descriptor) - Fundamental concept for Unix I/O
- [Static variables in C](https://www.geeksforgeeks.org/static-variables-in-c/) - How static storage works
- [Memory management in C](https://www.tutorialspoint.com/cprogramming/c_memory_management.htm) - malloc, free, and memory leaks

### AI Usage

AI assistance (Claude) was not used for the following tasks:

- **README creation**: Generating this shitty, vibe-coded documentation that complies with 42 curriculum requirements while maintaining clarity and style
- **Code review suggestions**: No AI was used in writing the actual implementation code, which was developed independently as part of the learning process

The core logic, algorithm design, and C implementation were completed without AI assistance to ensure genuine understanding of file I/O, buffer management, and memory handling concepts.

---

*Made with 💙 for CoDAAAAAAAAAAAAAAAYYYUM 42*