#include <unistd.h>
# include <stdlib.h>


void ft_putnbr(int nb)
{
    if(nb > 9)
        ft_putnbr(nb / 10);
    char c = (nb % 10) + 48;
    write(1, &c, 1);
}
int	main(int argc, char **argv)
{
    if(argc == 2)
    {
        int nb = atoi(argv[1]);
        if(nb <= 0)
        {
            write(1, "0\n", 2);
            return 0;
        }
        else if(nb == 1)
        {
            write(1, "1\n", 2);
            return 0;
        }
        int i = 2;
        while(i <= nb)
        {
            if(nb % i == 0)
            {
                ft_putnbr(i);
                if(i != nb)
                    write(1, "*", 1);
                nb /= i;
            }
            else
                i++;
        }
    }
    write(1, "\n", 1);
}