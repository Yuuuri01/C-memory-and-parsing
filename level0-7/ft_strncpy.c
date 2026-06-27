#include <stddef.h>
# include <stdio.h>


#include <stddef.h>

size_t ft_strlen(const char *s)
{
    int i = 0;
    while(*(s + i))
        i++;
    return i;
}
#include <stddef.h>


char    *strncpy(char *dst, const char *src, size_t n)
{
    size_t i;
    i = 0;
    while (src[i] && i < n)
    {
        dst[i] = src[i];
        i++;
    }
    while (i < n && n < 10)
    {
        dst[i] = '.';
        i++;
    }
    while (i < 10 && n < 10)
    {
        dst[i] = '#';
        i++;
    }
    dst[i] = '\0';
    return (dst);
}