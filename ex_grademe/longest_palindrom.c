#include <unistd.h>
# include <stdio.h>
int get_length(char *str, int from, int to)
{
    while(from >= 0 && str[to] && str[from] == str[to])
    {
        from--;
        to++;
    }
    return to - from - 1;
}
int	main(int ac, char **av)
{
    if(ac == 2)
    {
        int i = 0;
        int len = 0;
        int len1 = 0;
        int start = 0;
        int len2 = 0;
        int max = 0;
        while(av[1][i])
        {
            len1 = get_length(av[1], i, i);
            len2 = get_length(av[1], i, i + 1);
            len = (len1 > len2) ? len1 : len2;
            if(len > max)
            {
                max = len;
                start = i - (len - 1) / 2;
            }
            i++;
        }
        write(1, (av[1] + start), max);
        write(1, "\n", 1);
    }
    else
        write(1, "worng number of arguments\n", 26);
}
