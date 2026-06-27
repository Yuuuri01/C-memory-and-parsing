# include <unistd.h>



char	*strchr(const char *s, int c)
{
    char *str = (char *)s;
    int i = 0;
    while(*str)
    {
        if(*str == c)
            return &(*str);
        str++;
    }
    if(*str == c)
        return &(*str);
    return NULL;
}
# include <stdio.h>
int main(int ac, char **av)
{
    if(ac >= 2)
    {
        char *s = strchr(av[1], av[2][0]);
        if(s)
            printf("%s\n", s);
    }
}