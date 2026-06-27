# include <stdio.h>

int ft_strlen(char *str)
{
    int index = 0;
    while(*(str + index))
        index++;
    return index;
}
char *rev_str(char *str)
{
    int len = ft_strlen(str) - 1;
    int i = 0;
    char c;
    while(str[i] && i <= len)
    {
        c = str[i];
        str[i] = str[len];
        str[len] = c;
        len--;
        i++;
    }
    return str;
}
int main()
{
    char str[] = "hello";
    printf("%s\n", rev_str(str));
}
