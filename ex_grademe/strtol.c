# include <unistd.h>
int get_pos(char c, int base)
{
    char *bL = "0123456789abcdef";
    char *bU = "0123456789ABCDEF";
    int i = 0;
    while(bL[i] && bU[i])
    {
        if(c == bL[i] || c == bU[i])
        {
            if(i < base)
                return i;
            else
                return -1;
        }
        i++;        
    }
    return -1;
}
long	strtol(const char *str, char **endptr, int base)
{
	long res = 0;
	int signe = 1;
    int val = 0;
    int i = 0;
    int seen = 0;

	while(str[i] && (str[i] == 32 || str[i] == 9))
		i++;
	if(str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
			signe = -1;
		i++;
	}
	if(base == 0)
	{
		if((str[i] == '0') && (str[i + 1] == 'x' || str[i + 1] == 'X'))
			base = 16;
		else if(str[i] == '0')
			base = 8;
		else
			base = 10;
	}
    if((base == 16 && str[i] == '0') && (str[i + 1] == 'x' || str[i + 1] == 'X'))
        i += 2;
    while(str[i])
    {
        val = get_pos(str[i], base);
        if(val != -1)
        {
            res = res * base + val;
            seen = 1;
        }
        else
            break;
        i++;
    }
    
    if(endptr != NULL)
    {
        if(seen)
            *endptr = (char *)(str + i);
        else
            *endptr = (char *)(str);
    }
    return res * signe;
}
# include <stdio.h>
int main()
{
    char *end = NULL;
    char *str = "    +zz";
    long res = strtol(str, &end, 10);
    printf("%ld\n", res);    
    printf("%s\n", end);
}
