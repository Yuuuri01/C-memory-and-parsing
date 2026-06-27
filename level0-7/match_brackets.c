# include <unistd.h>
# include <stdio.h>


int is_open(char c)
{
    if(c == '{' || c == '[' || c == '(')
        return 1;
    return 0;
}
int is_close(char c)
{
    if(c == '}' || c == ')' || c == ']')
        return 1;
    return 0;
}
int correct_colse(char c1, char c2)
{
    if(c1 == '{' && c2 == '}') return 1;
    else if(c1 == '(' && c2 == ')') return 1;
    else if(c1 == '[' && c2 == ']') return 1;
    else
        return 0;
}
int is_spaces(char *s)
{
    if(s[0] != 32 && s[0] != 9 && s[0] != '\0')
        return 0;
    while(*s && (*s == 32 || *s == 9))
        s++;
    if(!*s)
        return 1;
    return 0;

}
int brackets(char *s, int *inter)
{
    int j = -1;
    char arr[1024];

    while(*s)
    {
        if(is_open(*s))
        {
            arr[++j] = *s;
        }
        else if(j >= 0 && is_close(*s))
        {
            *inter = 1;
            if(correct_colse(arr[j], *s))
                j--;
            else
                return 0;
        }
        s++;
    }
    return (j == -1);
}
int main(int ac, char **av)
{
    if(ac >= 2)
    {
        int i = 1;
        int inter;
        while(av[i])
        {
            inter = 0;
            if(is_spaces(av[i]) || (brackets(av[i], &inter) && inter))
                write(1, "OK\n", 3);
            else
                write(1, "Error\n", 6);
            i++;
        }
    }
    else
        write(1, "\n", 1);
}