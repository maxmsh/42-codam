#include <unistd.h>

void repeat_alpha(char *str)
{
    int len;

    while (*str)
    {
        if (*str >= 65 && *str <= 90)
        {
            len = *str - 64;
            while (len > 0)
            {
                write(1, str, 1);
                len--;
            }
        }
        else if (*str >= 97 && *str <= 122)
        {
            len = *str - 96;
            while (len > 0)
            {
                write(1, str, 1);
                len--;
            }
        }
        else
            write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
        repeat_alpha(argv[1]);
    else
        write(1, "\n", 1);
    
    return (0);
}