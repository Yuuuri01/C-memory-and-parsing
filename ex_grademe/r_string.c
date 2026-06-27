#include <unistd.h>
# include <stdlib.h>
int	main(int ac, char **av)
{
	if(ac == 2)
	{
		int i = 0;
        int len = 0;
        int print = 0;
        int sp = 0;
        char *s;

        while(av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
            i++;
        s = &av[1][i];

        while(av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t'))
            i++;

        if(av[1][i] != '\0')
            i++;
        
        while(av[1][i])
        {
            if(av[1][i] != ' ' && av[1][i] != '\t')
            {
                if(sp)
                {
                    write(1, " ", 1);
                    sp = 0;
                }
                write(1, &(av[1][i]), 1);
                print = 1;
            }
            else if(av[1][i] == ' ' || av[1][i] == '\t')
                sp = 1;
            i++;
        }
        if(print)
            write(1, " ", 1);
        
        i = 0;
        while(s[i] && (s[i] != ' ' && s[i] != '\t'))
            write(1, &(s[i++]), 1);
        write(1, "\n", 1);
	}
	else
		write(1, "worng number of arguments\n", 26);
}
