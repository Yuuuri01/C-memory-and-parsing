# include <stdlib.h>
# include <stdio.h>




int main(int ac, char **av)
{
    if(ac == 2)
    {
        int nb = atoi(av[1]);
        int i = 2;

        while(nb >= 2)
        {
            if(nb % i == 0)
            {
                printf("%d", i);
                nb /= i;
                if(nb != 1)
                    printf("*");
            }
            else
                i++;
        }
        printf("\n");
    }
}