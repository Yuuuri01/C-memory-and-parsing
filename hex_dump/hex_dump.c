# include <unistd.h>
# include <stdio.h>


# include <unistd.h>



void ft_putchar(char c)
{
    write(1, &c, 1);
}
void *hex_dump(void *addr, unsigned int size)
{
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned char *ptr = (unsigned char *)addr;
    char *base = "0123456789abcdef";
    while(i < size)
    {
        j = 0;
        while(j < 16 && (i + j) < size)
        {
        
            ft_putchar(base[ptr[i + j] / 16]);
            ft_putchar(base[ptr[i + j] % 16]);
            write(1, " ", 1);
            j++;
        }

        while(j < 16)
        {
            write(1, "   ", 3);
            j++;
        }
        write(1, " ", 1);
        j = 0;
        while(j < 16 && (i + j) < size)
        {
            unsigned char c = ptr[i + j];
            if(c >= 32 && c <= 126)
                write(1, &c, 1);
            else
                write(1, ".", 1);
            j++;
        }
        write(1, "\n", 1);
        i += 16;
    }
    return addr;
}
# include <stdio.h>
int main()
{
    char *s = hex_dump("ABCDEFGH", 8);
    char *s2 = hex_dump("merge later test", 16);

    printf("%s %s\n", s, s2);
}
