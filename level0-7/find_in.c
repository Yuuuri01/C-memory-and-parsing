#include <unistd.h>

int get_char(char c, char *av, int *index)
{
    while(av[*index])
    {
        if(c == av[*index])
            return 1;
        (*index)++;
    }
    return -1;
}
int	main(int argc, char **argv)
{
    if(argc == 3)
    {
        int i = 0;
        int index = 0;
        while(argv[1][i])
        {
            if(get_char(argv[1][i], argv[2], &index) == -1)
            {
                write(1, "no\n", 3);
                    return 0;
            }
            i++;
        }
        write(1, "yes\n", 4);
    }
    else
        write(1, "\n", 1);
}
