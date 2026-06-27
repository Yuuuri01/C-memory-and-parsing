# include <stdio.h>
#include <stddef.h>

size_t ft_strlen(char *str)
{
    size_t i = 0;
    while(str[i])
        i++;
    return i;
}
int	memcmp(const void *s1, const void *s2, size_t n)
{
    if(n == 0)
        return 0;
    char *src1 = (char *)s1;
    char *src2 = (char *)s2;
    size_t len1 = ft_strlen(src1);
    size_t len2 = ft_strlen(src2);
    size_t i = 0;
    while(i < n && i < len1 && i < len2);
    {
        if(src1[i] != src2[i])
            return (src1[i] - src2[i]);
        i++;
    }
    return (src1[i] - src2[i]);
}
int main()
{
    printf("%d\n", memcmp("ab\0cd", "ab\0ce", 5));
    printf("%d\n", memcmp("merge", "rebase", 0));
    printf("%d\n", memcmp("\xff", "\x01", 1));
    printf("%d\n", memcmp("commitX", "commitY", 6));

}
