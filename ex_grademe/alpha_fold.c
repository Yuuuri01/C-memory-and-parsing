# include <unistd.h>



int main(int ac, char **av)
{
    if(ac == 2)
    {
        char c;
        while(*av[1])
        {
            c = *av[1];
            if(c >= 'a' && c <= 'z')
                c = 122 - (c - 97);
            else if(c >= 'A' && c <= 'Z')
                c = 90 - (c - 65);
            write(1, &c, 1);
            av[1]++;
        }
        write(1, "\n", 1);
    }
    else
        write(1, "wrong number of arguments\n", 26);
}