#include <unistd.h>

void first_word(char *str)
{
    while (*str)
    {
        if (((*str == 32) || (*str >= 9 && *str <= 13)) && 
        ((*str - 1 >= 65 && *str <= 90) || (*str - 1 >= 97 && *str <= 122)))
            break;
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