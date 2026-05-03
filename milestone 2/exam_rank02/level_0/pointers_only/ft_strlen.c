// #include <stdio.h>

int ft_strlen(char *str)
{
    int count;
    count = 0;

    while (*str)
    {
        str++;
        count++;
    }
    return (count);
}

// int main(void)
// {
//     char *string = "The amount of characters in this string is: ";
//     printf("%d\n", ft_strlen(string));
//     printf("%d\n", strlen(string));

//     return (0);
// }