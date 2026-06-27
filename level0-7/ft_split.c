# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>


int check_charset(char *charset, char c)
{
    int i = 0;
    while(charset[i])
    {
        if(c == charset[i])
            return 1;
        i++;
    }
    return 0;
}
int count_words(char *s, char *charset)
{
    int i = 0;
    int count = 0;

    while(s[i])
    {
        if(!check_charset(charset, s[i]))
        {
            if(i == 0 || check_charset(charset, s[i - 1]))
                count++;
        }
        i++;
    }
    return count;
}
int get_len(char *s, char *charset)
{
    int len = 0;
    while(s[len] && (!check_charset(charset, s[len])))
        len++;
    return len;
}
char *copy(char *s, int len)
{
    char *new;
    int i;

    new = malloc((len + 1) * sizeof(char));
    if(!new)
        return NULL;
    i = 0;
    while(i < len)
    {
        new[i] = s[i];
        i++;
    }
    new[i] = '\0';
    return new;
}
char **split(char *str, char *charset)
{
    char **splited;
    int len_word;
    int index;
    int i;
    int j;

    splited = malloc((count_words(str, charset) + 1) * sizeof(char *));
    if(!splited)
        return NULL;

    i = 0;
    index = 0;
    while(str[i])
    {
        if(!check_charset(charset, str[i]))
        {
            len_word = get_len(&str[i], charset);
            splited[index] = copy(&str[i], len_word);
            if(!splited[index])
            {
                j = 0;
                while(j < index)
                    free(splited[j++]);
                free(splited);
                return NULL;
            }
            index++;
            i += len_word;
        }
        else
            i++;
    }
    splited[index] = NULL;
    return splited;
}
int main()
{
    char **new = split("cargo build --release", " -");

    int i = 0;
    while(new[i])
    {
        printf("%s\n", new[i++]);
    }
}