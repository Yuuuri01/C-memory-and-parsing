#include <unistd.h>


int check_safe(char c)
{
    if(c == 32 || c == 9 || c == 13 || c == '\0')
        return 1;
    else if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
        return 1;
    else
        return 0;
}
int	main(int argc, char **argv)
{
    if(argc >= 2)
    {
        int i = 1;
        int j;
        while(argv[i])
        {
            j = 0;
            while(argv[i][j])
            {
                if(check_safe(argv[i][j + 1]))
                {
                    if(argv[i][j] >= 'a' && argv[i][j] <= 'z')
                        argv[i][j] -= 32;
                }
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
