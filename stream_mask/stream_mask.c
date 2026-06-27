# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>


int is_blank(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}
int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return i;
}
int ft_strcmp(char *s1, char *s2)
{
    while(*s1 && *s2)
    {
        if(*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}
char *add_to_buff(char *buff, int len, char c)
{
    char *tmp = realloc(buff, len + 1);
    if(!tmp)
    {
        free(buff);
        return NULL;
    }
    tmp[len] = c;
    return tmp;
}
void print_it(char *word, int len, char *av)
{
    if(!word || len == 0) return;
    
    word[len] = '\0';
    int len2 = 0;
    int i = 0;

    if(ft_strcmp(word, av) == 0)
    {
        len2 = ft_strlen(av);
        while(i < len2)
        {
            write(1, "*", 1);
            i++;
        }
    }
    else
        write(1, word, len);
}
int stream_mask(char *av)
{
    char *word = NULL;
    int len = 0;
    char c;
    int len2 = ft_strlen(av);

    if(len2 == 0) return 1;

    while(read(0, &c, 1) > 0)
    {
        if(!is_blank(c))
        {
            word = add_to_buff(word, len, c);
            if(!word)
            {
                perror("Error\n");
                return 1;
            }
            len++;
            if(len == len2)
            {
                word = add_to_buff(word, len, '\0');
                if(!word)
                {
                    perror("realloc faild\n");
                    return 1;
                }
                if(ft_strcmp(word, av) == 0)
                {
                    print_it(word, len, av);
                    free(word);
                    word = NULL;
                    len = 0;
                }
            }
        }
        else
        {
            if(len > 0)
            {
                word = add_to_buff(word, len, '\0');
                write(1, word, len);
                free(word);
                word = NULL;
                len = 0;
            }
            write(1, &c, 1);
        }
    }
    if(len > 0)
    {
        word = add_to_buff(word, len, '\0');
        print_it(word, len, av);
        free(word);
    }
    return 0;
}
int space_handle(char *av)
{
    char c;
    char *word = NULL;
    int len = 0;
    
    while(*av)
    {
        if(!is_blank(*av))
            return -1;
        av++;
    }
    while(read(0, &c, 1) > 0)
    {
        word = add_to_buff(word, len, c);
        if(!word)
        {
            perror("ERROR\n");
            return 1;
        }
        len++;
        if(c == ' ' || c == '\t')
        {
            write(1, "*", 1);
            len = 0;
        }
        else
            write(1, &c, 1);
    }
    free(word);
    return 0;
}
int main(int ac, char **av)
{
    if(ac != 2 || ft_strlen(av[1]) == 0)
        return 1;
    if(space_handle(av[1]) == -1)
    {
        return stream_mask(av[1]);
    }
    else
        return 0;
}