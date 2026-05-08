#include <unistd.h>

void camel_to_snake(char *str)
{
    while (*str)
    {
        if (*str >= 65 && *str <= 90)
        {
            write(1, "_", 1);
            *str = *str + 32;
        }
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
        camel_to_snake(argv[1]);
    else
        write(1, "\n", 1);

    return (0);
}