#include <unistd.h>

void first_word(char *str)
{
    int i;
    i = 0;

    while (str[i] != '\0')
    {
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
        {
            write(1, &str[i], 1);
            i++;
        }
        else if ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
            break;
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