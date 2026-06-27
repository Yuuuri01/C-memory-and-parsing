# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>



int main(int ac, char **av)
{
    if(ac == 4)
    {
        int nb1 = atoi(av[1]);
        int nb2 = atoi(av[3]);
        char op = av[2][0];
        int res = 0;
        if(op == '+') res = nb1 + nb2;
        else if(op == '-') res = nb1 - nb2;
        else if(op == '*') res = nb1 * nb2;
        else if(op == '/')
        {
            if(nb2 == 0)
                res = 0;
            else
                res = nb1 / nb2;
        }
        else if(op == '%')
        {
            if(nb2 == 0)
                res = 0;
            else
                res = nb1 % nb2;
        }
        printf("%d\n", res);
    }
    else
        write(1, "wrong number of arguments\n", 26);
}

