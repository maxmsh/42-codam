#include <unistd.h>

void search_and_replace(char *str, char search, char replace)
{
    int i;
    i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == search)
        {
            str[i] = replace;
            write(1, &replace, 1);
            i++;
        }
        else
        {
            write(1, &str[i], 1);
            i++;
        }
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