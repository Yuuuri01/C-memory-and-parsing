
# include <stdio.h>
# include <unistd.h>

int get_pos(char c, int base)
{
    char *base1 = "0123456789ABCDEF";
    char *base2 = "0123456789abcdef";
    int i = 0;
    while(base1[i] && base2[i])
    {
        if(c == base1[i] || c == base2[i])
        {
            if(i >= base)
                return -1;
            return i;
        }
        i++;
    }
    return -1;
}
int parse_int_base(const char *str, int base)
{
    int i = 0;
    int res = 0;
    int sign = 1;
    int pos;
    while(str[i] == ' ' || str[i] == '\t')
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign = -1;
        i++;
    }
    while(str[i])
    {
        pos = get_pos(str[i], base);
        if(pos != -1)
        {
            res = res * base + pos;
        }
        else
            break;
        i++;
    }
    return res * sign;
}
int main()
{
    printf("%d\n", parse_int_base("-1010stop", 2));
}