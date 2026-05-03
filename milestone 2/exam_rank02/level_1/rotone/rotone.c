#include <unistd.h>

void rotone(char *str)
{
    int i;
    i = 0;

    while (str[i] != '\0')
    {
        if ((str[i] >= 65 && str[i] <= 89) || (str[i] >= 97 && str[i] <= 121))
            str[i] = str[i] + 1;
        else if ((str[i] == 90) || (str[i] == 122))
            str[i] = str[i] - 25;
        write(1, &str[i], 1);
        i++;
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