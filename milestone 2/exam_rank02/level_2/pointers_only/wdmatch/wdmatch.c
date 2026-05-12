#include <unistd.h>

int ft_strlen(char *str)
{
    char* end = str;

    while (*end)
        end++;

    return end - str;
}

void wdmatch(char *str1, char *str2)
{
    char* start = str1;
    int size = 0, len = ft_strlen(str1);
    while (*str2)
    {
        if (*str2 == *str1)
        {
            size++;
            str1++;
        }
        str2++;
    }

    if (len == size)
        while(*start)
            write(1, start++, 1);

    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc == 3)
        wdmatch(argv[1], argv[2]);
    else
        write(1, "\n", 1);

    return (0);
}

