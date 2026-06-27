# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

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
int is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}
char *add_to_buff(char *buff, int len, char s)
{
    char *tmp = realloc(buff, len + 1);
    if(!tmp)
    {
        return NULL;
    }
    tmp[len] = s;
    return tmp;
}
void print_mask(char *word, int len1, int len2, int *cmp)
{
    if(!word || !len1)
        return;
    word[len1] = '\0';
    int i = 0;
    if(*cmp)
    {
        while(i < len2)
        {
            write(1, "*", 1);
            i++;
        }
        *cmp = 0;
    }
    else
        write(1, word, len1);
}
int handle_spaces(char *s)
{
    while(*s)
    {
        if(*s != ' ' && *s != '\t')
            return -1;
        s++;
    }
    return 1;
}
int stream_mask(char *av)
{
    int cmp = 0;
    char *word = NULL;
    int len1 = 0;
    int len2 = strlen(av);
    char c;

    if(handle_spaces(av) != -1)
    {
        while(read(0, &c, 1) > 0)
        {
            if(c == ' ' || c == '\t')
                write(1, "*", 1);
            else
                write(1, &c, 1);
        }
        return 0;
    }
    while(read(0, &c, 1) > 0)
    {
        if(!is_space(c))
        {
            word = add_to_buff(word, len1, c);
            if(!word)
            {
                perror("error realloc fail");
                return 1;
            }
            len1++;
            if(len1 == len2)
            {
                word = add_to_buff(word, len1, '\0');
                if(!word)
                {
                    perror("error realloc");
                    return 1;
                }
                else if(ft_strcmp(word, av) == 0)
                {
                    cmp = 1;
                    print_mask(word, len1, len2, &cmp);
                    free(word);
                    word = NULL;
                    len1 = 0;
                }
            }
        }
        else
        {
            if(len1 > 0)
            {
                word = add_to_buff(word, len1, '\0');
                if(!word)
                {
                    perror("error");
                    return 1;
                }
                print_mask(word, len1, len2, &cmp);
                free(word);
                word = NULL;
                len1 = 0;
            }
            write(1, &c, 1);
        }
    }
    if(len1 > 0)
    {
        word = add_to_buff(word, len1, '\0');
        if(!word)
        {
            perror("error");
            return 1;
        }
        print_mask(word, len1, len2, &cmp);
        free(word);
    }
	return 0;
}


int main(int ac, char **av)
{
    if(ac != 2 || strlen(av[1]) == 0)
        return 1;
    return stream_mask(av[1]);
}
