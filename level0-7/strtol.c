# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int get_pos(char c, int b)
{
    char base1[] = "0123456789ABCDEF";
    char base2[] = "0123456789abcdef";
    int i = 0;
    while(base1[i] && base2[i])
    {
        if(c == base1[i] || c == base2[i])
        {
            if(i >= b)
                return -1;
            return i;
        }
        i++;
    }
    return -1;
}
long	strtol(const char *str,  char **endptr, int base)
{
    int pos;
    long res;
    int sign;
    int found;
    int i;

    i = 0;
    sign = 1;
    while(str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign = -1;
        i++;
    }
    if(base == 0)
    {
        if(str[i] == '0' && str[i + 1] == 'x')
            base = 16;
        else if(str[i] == '0')
            base = 8;
        else
            base = 10;
    }
    if(base == 16 && (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X')))
        i += 2;

    res = 0;
    found = 0;
    while(str[i])
    {
        pos = get_pos(str[i], base);
        if(pos != -1)
            res = res * base + pos;
        else
            break;
        i++;
        found = 1;
    }
    if(endptr != NULL)
    {
        if(found)
            *endptr = (char *)(str + i);
        else
            *endptr = (char *)str;
    }
    return res * sign;
}
int main()
{
    char *new = NULL;
    long res = strtol("   -17abc", &new, 10);
    printf("%ld\n", res);
    printf("%s\n", new);

}
