# include <stdio.h>


char	*strcat(char *dst, const char *src)
{
    int i = 0;
    while(dst[i])
        i++;
    while(*src)
    {
        dst[i++] = *src++;
    }
    dst[i] = '\0';
    return dst;
}
int main()
{
    char s[] = "rebase done";
    char dst[] = "";
    strcat(dst, s);
    printf("%s\n", dst);
}