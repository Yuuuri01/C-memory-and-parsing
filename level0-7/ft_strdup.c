# include <unistd.h>
# include <stdlib.h>


char *strdup(const char *src)
{
    char *new;
    char *send;
    int len = 0;
    while(src[len])
        len++;

    if(!(new = malloc((len + 1) * sizeof(char))))
        return NULL;

    send = (char *)src;
    len = 0;
    while(send[len])
    {
        new[len] = send[len];
        len++;
    }
    new[len] = '\0';
    return new;
}
