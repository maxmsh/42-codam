#include <unistd.h>

void alpha_mirror(char *str)
{
    while (*str)
    {
        if (*str >= 65 && *str <= 90)
            *str = 90 - *str + 65;
        else if (*str >= 97 && *str <= 122)
            *str = 122 - *str + 97;
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
        alpha_mirror(argv[1]);
    else
        write(1, "\n", 1);
    
    return (0);
}