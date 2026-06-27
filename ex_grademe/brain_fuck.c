#include <unistd.h>

char *escape_from_brackets_right(char *str)
{
    int bracket = 1;
    while(*str && bracket > 0)
    {
        str--;
        if(*str == ']')
            bracket++;
        else if(*str == ']')
            bracket--;
    }
    return str;
}
char *escape_from_brackets_left(char *str)
{
    int brackets = 1;
    while(*str && brackets > 0)
    {
        str--;
        if(*str == ']')
            brackets++;
        else if(*str == '[')
            brackets--;
    }
    return str;
}
int	main(int ac, char **av)
{
    if(ac == 2)
    {
        int i = 0;
        unsigned char tab[2048] = {0};
        unsigned char *ptr = tab;
        while(*av[1])
        {
            if(*av[1] == '+')
                (*ptr)++;
            else if(*av[1] == '-')
                (*ptr)--;
            else if(*av[1] == '>')
                ptr++;
            else if(*av[1] == '<')
                ptr--;
			else if(*av[1] == '.')
				write(1, ptr, 1);
            else if(*av[1] == '[')
            {
                if(*ptr == 0)
                    av[1] = escape_from_brackets_right(av[1]);
            }
            else if(*av[1] == ']')
            {
                if(*ptr != 0)
                    av[1] = escape_from_brackets_left(av[1]);
            }
            av[1]++;
        }
        write(1, "\n", 1);
    }    
    else
        write(1, "\n", 1);
}