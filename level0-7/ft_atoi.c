int ft_atoi(const char *str)
{
    int res = 0;
    int sign = 1;

    while(*str == 32 || *str == 9 || *str == 13)
        str++;
    while(*str == 45 || *str == 43)
    {
        if(*str == 45)
            sign *= -1;
        str++;
    }
    while(*str >= '0' && *str <= '9')
        res = res * 10 + *(str++) - 48;
    return res * sign;
}
# include <stdio.h>
int main()
{
    printf("%d", ft_atoi("    +-----123olik"));
}