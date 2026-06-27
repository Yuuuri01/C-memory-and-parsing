# include <stdlib.h>

char	*strrchr(const char *s, int c)
{
    int i = 0;
    char *str = (char *)s;
    while(str[i])
        i++;

    if(str[i] == c)
        return &str[i];
    i--; 
    while(str[i] && i >= 0)
    {
        if(str[i] == c)
            return &str[i];
        i--;
    }
    return NULL;
}
# include <stdio.h>
int main()
{
    char *new = strrchr("zsh", 'z');
    if(!*new)
        printf("empty\n");
    if(new == NULL)
        printf("NULL\n");
    else
        printf("%s\n", new);
}