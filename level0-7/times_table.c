#include <unistd.h>



void ft_putnbr(int nb)
{
    if(nb > 9)
        ft_putnbr(nb / 10);
    char c = (nb % 10) + 48;
    write(1, &c, 1);
}
int ft_atoi(char *s)
{
    int res = 0;
    while(*s && (*s == 32 || *s == 9))
        s++;
    if(*s == 45)
        return -1;
    while(*s >= '0' && *s <= '9')
    {
        res = res * 10 + *(s++) - 48;
    }
    return res;
}
# include <stdio.h>
int	main(int argc, char **argv)
{
    if(argc == 2)
    {
        int i;
        int nb = ft_atoi(argv[1]);
        if(nb < 0)
        {
            write(1, "\n", 1);
            return 0;
        }
        i = 1;
        while(i <= 9)
        {
            ft_putnbr(i);
            write(1, " x ", 3);
            ft_putnbr(nb);
            write(1, " = ", 3);
            ft_putnbr(nb * i);
            write(1, "\n", 1);
            i++;
        }        
    }
    else
        write(1, "\n", 1);
}
