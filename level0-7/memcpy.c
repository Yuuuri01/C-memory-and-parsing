#include <stddef.h>

void	*memcpy(void *dst, const void *src, size_t n)
{
    size_t i = 0;
    char *src1 = (char *)src;
    char *dest = (char *)dst;

    while(*src1 && i < n)
    {
        dest[i] = *src1++;
        i++;
    }
    dest[i] = '\0';
    return dst;
}
# include <stdio.h>
int main()
{
    char dest[100];
    memcpy(dest, "rebase --hard", 4);
    printf("%s\n", dest);
}
