#include <unistd.h>

void rev_print(char *str)
{
    while (*str != '\0')
        str++;
    if (*str == '\0')
        str--;
    while (*str != '\0')
    {
        write(1, str, 1);
        str--;
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
        rev_print(argv[1]);
    else
        write(1, "\n", 1);

    return (0);
}