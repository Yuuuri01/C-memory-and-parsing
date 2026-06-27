#include <stddef.h>
# include <stdio.h>


void	*memmove(void *dst, const void *src, size_t n)
{
    char *d = (char *)dst;
    char *s = (char *)src;
    size_t i;
    if(!s || !d)
        return dst;
    
    if(d <= s)
    {
        i = 0;
        while(i < n)
        {
            d[i] = s[i];
            i++;
        }
    }
    else if(d > s)
    {
        while(n)
        {
            n--;
            d[n] = s[n];
        }
    }
    return dst;
}
int main()
{
    char *src = "get rebase";
    char buff[100];
    printf("%s\n", memmove(buff, src, 11));
}
