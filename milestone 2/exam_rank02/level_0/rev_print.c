#include <unistd.h>
#include <stdio.h>

void rev_print(char *str)
{
    int i;
    i = 0;

    while (str[i] != '\0')
    {
        i++;
    }
    if (str[i] == '\0')
    {
        i--;
    }
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i--;
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