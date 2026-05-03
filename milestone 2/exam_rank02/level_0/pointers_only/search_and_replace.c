#include <unistd.h>

void search_and_replace(char *str, char search, char replace)
{
    while (*str)
    {
        if (*str == search)
        {
            search = replace;
            write(1, &replace, 1);
            str++;
        }
        else
            write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc == 4)
        search_and_replace(argv[1], *argv[2], *argv[3]);
    else
        write(1, "\n", 1);

    return (0);
}