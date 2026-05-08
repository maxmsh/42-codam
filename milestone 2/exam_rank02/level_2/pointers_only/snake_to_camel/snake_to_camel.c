#include <unistd.h>

void snake_to_camel(char *str)
{
    while (*str)
    {
        if (*str == 95)
        {
            str++;
            *str = *str - 32;
        }
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
        snake_to_camel(argv[1]);
    else
        write(1, "\n", 1);

    return (0);
}