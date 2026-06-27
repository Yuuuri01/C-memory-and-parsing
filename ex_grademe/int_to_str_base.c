# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>


int nb_length(int nb, int base)
{
    int size = 0;
    int tmp = nb;
    if(nb == 0)
        return 1;
    if(nb < 0)
    {
        size++;
        tmp *= -1;
    }
    while(tmp)
    {
        size++;
        tmp /= base;
    }
    return size;
}
char *int_to_str_base(int value, int base)
{
	unsigned int res;
    int i;
    int len;
    char *str;
    char *base1 = "0123456789abcdef";

    if(base < 2 || base > 16)
        return NULL;
    len = nb_length(value, base);
    str = malloc((len + 1) * sizeof(char));
    if(!str)
        return NULL;

    if(value == 0)
    {
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    if(base == 10 && value < 0)
    {
        str[0] = '-';
        res = -value;
    }
    else
        res = value;
    
    str[len] = '\0';
    i = len - 1;
    while(res)
    {
        str[i] = base1[res % base];
        i--;
        res /= base;
    }
    return str;
}
int main()
{
    printf("%s\n", int_to_str_base(255, 16));
    printf("%s\n", int_to_str_base(42, 10));
    printf("%s\n", int_to_str_base(10, 2));
    printf("%s\n", int_to_str_base(-13, 2));
    printf("%s\n", int_to_str_base(-2552121, 10));

}