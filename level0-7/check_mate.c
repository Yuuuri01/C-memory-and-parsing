# include <unistd.h>
# include <stdio.h>

int count_words(char *str)
{
    int count = 0;
    int  i = 0;
    while(str[i])
    {
        if(str[i] != '\n')
        {
            if(i == 0 || str[i - 1] == '\n')
                count++;
        }
        i++;
    }
    return count;
}
char **split(char *str)
{
    int len = count_words(str) + 1;
    static char *spli[100];

    int i = 0;
    int index = 0;
    if(str[i] != '\n' && str[i])
    {
        spli[index++] = &str[i];
        i++;
    }
    while(str[i])
    {
        if(str[i] == '\n')
        {
            str[i] = '\0';
            if(str[i + 1] && str[i + 1] != '\n')
                spli[index++] = &str[i + 1];
        }
        i++;
    }
    spli[index] = NULL;
    return spli;
}
int main(int ac, char **av)
{
    if(ac >= 2)
    {
        char **new = split(av[1]);
        int i = 0;
        while(new[i])
        {
            printf("%s\n", new[i++]);
        }
    }
}