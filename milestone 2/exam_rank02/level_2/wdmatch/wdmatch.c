#include <unistd.h>

int ft_strlen(char *str)
{
    int i;
    i = 0;

    while(str[i] != '\0')
    {
        i++;
    }
    return (i);
}

void wdmatch(char *str1, char *str2)
{
    int i;
    int size;
    int len;
    len = ft_strlen(str1);
    size = 0;
    i = 0;

    while (str2[i])
    {
        if (str2[i] == str1[i])
        {
            i++;
            size++;
        }
        i++;
    }
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