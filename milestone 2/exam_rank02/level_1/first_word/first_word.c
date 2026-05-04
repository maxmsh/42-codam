#include <unistd.h>

void first_word(char *str)
{
    int i;
    i = 0;

    while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
        i++;

    while ((str[i] != '\0') && (str[i] != 32) && !(str[i] >= 9 && str[i] <= 13))
    {
        write(1, &str[i], 1);
        i++;
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