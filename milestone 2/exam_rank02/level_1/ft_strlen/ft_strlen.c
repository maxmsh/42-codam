// #include <stdio.h>

int ft_strlen(char *str)
{
    int i;
    i = 0;

    while (str[i] != '\0')
        i++;
    
    return (i);
}

// int main(void)
// {
//     char *string = "Length";
//     printf("The length of the inputstring is: %d\n", ft_strlen(string));
//     return (0);
// }