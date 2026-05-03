#include <unistd.h>

void first_word(char *str)
{
    while (*str)
    {
        if (((*str >= 65 && *str <= 90) || (*str >= 97 && *str <= 122)) && ((*(str + 1) == 32) || (*(str + 1) >= 9 && *str + 1 <= 13)))
        {
            write(1, str, 1);
            break;
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
        first_word(argv[1]);
    else
        write(1, "\n", 1);
    
    return (0);
}