int ft_atoi(const char *str)
{
    int sign;
    sign = 1;
    
    while (*str)
    {
        if ((*str == 32) || (*str >= 9 && *str <= 13))
            str++;

        if ((*str == 45) || (*str == 43))
        {
            sign = -1;
            
        }
    }
}