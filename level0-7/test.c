# include <stdio.h>
# include <stdlib.h>

int get_len(long res)
{
    int size = 0;
    if(res == 0)
        return 1;
    long tmp = res;
    while(tmp)
    {
        size++;
        tmp /= 10;
    }
    return size;
}
int get_pos(char c, int b)
{
    char base[] = "0123456789ABCDEF";

    int i = 0;
    while(base[i])
    {
        if(c == base[i])
        {
            if(i > b)
                return -1;
            return i;
        }
        i++;
    }
    return -1;
}
long	tol(const char *str, char **endptr, int base)
{
    char *s = (char *)str;
    int pos;
    int len;
    long res;
    int sign;
    long send;
    int i;
    if(base == 0)
    {
        if(s[0] == '0' && s[1] == 'x')
            base = 16;
        else
            base = 8;
    }
    i = 0;
    res = 0;
    sign = 1;
    if(s[i] && (s[i] == 45 || s[i] == 43))
    {
        if(s[i] == 45)
            sign *= -1;
        i++;
    }
    while(s[i] && (s[i] == 32 || s[i] == 9))
        i++;
    if(base == 16 && s[0] == '0' && s[1] == 'x')
        i += 2;
    while(s[i])
    {
        pos = get_pos(s[i], base);
        if(pos != -1)
            res = res * base + pos;
        i++;
    }

    send = res;
    len = get_len(res);
    *endptr[len + 1];
    *endptr[len] = '\0';
    if(sign < 0)
        *endptr[0] = '-';
    if(res == 0)
        *endptr[0] = '0';
    i = len - 1;
    while(i)
    {
        *endptr[i] = (res % 10) + 48;
        printf("%c\n", *endptr[i]);
        res /= 10;
        i--;
    }
    return send * sign;
}
int main()
{
    char *new = NULL;
    long res = strtol("0x1A", &new, 0);
    printf("%ld\n", res);
    printf("%s\n", new);

}