#include <unistd.h>

void rotone(char *str)
{
    while (*str)
    {
        if ((*str >= 65 && *str <= 89) || (*str >= 97 && *str <= 121))
            *str = *str + 1;
        else if ((*str == 90) || (*str == 122))
            *str = *str - 25;
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
        rotone(argv[1]);
    else
        write(1, "\n", 1);

    return (0);
}