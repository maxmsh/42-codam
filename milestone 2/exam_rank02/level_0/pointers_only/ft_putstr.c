#include <unistd.h>

void ft_putstr(char *str)
{
    while (*str)
    {
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
}

// int main(void)
// {
//     char *string = "Outputted string.";
//     ft_putstr(string);
// }