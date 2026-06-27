#include <unistd.h>

int	main(int argc, char **argv)
{
    if(argc >= 2)
    {
        int i = 1;
        int j = 0;
        while(argv[i])
        {
            j = 0;
            while(argv[i][j])
            {
                if(j == 0 || (argv[i][j - 1] == 32 || argv[i][j - 1] == 9))
                {
                    if(argv[i][j] >= 'a' && argv[i][j] <= 'z')
                        argv[i][j] -= 32;
                }
                else if(argv[i][j] >= 'A' && argv[i][j] <= 'Z')
                    argv[i][j] += 32;
                write(1, &(argv[i][j]), 1);
                j++;
            }
            write(1, "\n", 1);
            i++;
        }
    }
    else
        write(1, "\n", 1);
}