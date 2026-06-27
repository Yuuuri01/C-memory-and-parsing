#include <unistd.h>

int	main(int argc, char **argv)
{
    if(argc == 2)
    {
        int i = 0;
        int len = 0;
        int sp = 0;
        while(argv[1][i] && (argv[1][i] == 32 || argv[1][i] == 9))
            i++;
        while(argv[1][len])
            len++;

        while(argv[1][i] && i < len)
        {
            if(argv[1][i] != 32 && argv[1][i] != 9)
            {
                if(sp)
                {
                    write(1, " ", 1);
                    sp = 0;
                }
                write(1, &argv[1][i], 1);
            }
            else if(argv[1][i] == 32 || argv[1][i] == 9)
                sp = 1;
            i++;
        }
    }
    write(1, "\n", 1);
}
