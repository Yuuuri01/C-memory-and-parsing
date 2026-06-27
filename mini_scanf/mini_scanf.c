# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int isspace(int c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}
int isdigit(int nb)
{
    return (nb >= '0' && nb <= '9');
}
int mini_scanf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int nbs;
    int count = 0;
    int found = 0;

    nbs = fgetc(stdin);
    if(nbs == EOF)
        return -1;
    ungetc(nbs, stdin);
    

    while(*format)
    {
        if(*format == '%' && (*(format + 1) == 's' || *(format + 1) == 'd' || *(format + 1) == 'c'))
        {
            format++;
            if(*format == 'd')
            {
                int *p = va_arg(args, int *);
                int res = 0;
                int sign = 1;

                while(((nbs = fgetc(stdin)) != EOF) && isspace(nbs));
                if(nbs == '-')
                {
                    sign = -1;
                    nbs = fgetc(stdin);
                }
                else if(nbs == '+')
                {
                    sign = 1;
                    nbs = fgetc(stdin);
                }
                while(nbs != EOF && isdigit(nbs))
                {
                    res = res * 10 + (nbs - 48);
                    found = 1;
                    nbs = fgetc(stdin); 
                }
                if(found)
                {
                    count++;
                    *p = res * sign;
                }
                ungetc(nbs, stdin);
            }
            else if(*format == 'c')
            {
                char *ptr = va_arg(args, char *);
                *ptr = (char)fgetc(stdin);
                count++;
            }
            else if(*format == 's')
            {
                char *p = va_arg(args, char *);
                
                while((nbs = fgetc(stdin)) != EOF && isspace(nbs));

                while(nbs != EOF && !isspace(nbs))
                {
                    *p++ = (char)nbs;
                    nbs = fgetc(stdin);
                }
                *p = '\0';
                count++;
                ungetc(nbs, stdin);
            }
        }
        else
        {
            if(isspace(*format))
            {
                while(((nbs = fgetc(stdin) != EOF) && isspace(nbs)));
                if(nbs != EOF)
                    ungetc(nbs, stdin);
            }
            else
            {
                nbs = fgetc(stdin);
                if(nbs != *format)
                    break;
            }
        }
        format++;
    }
    va_end(args);
    return count;
}
int main()
{
    int age;
    char name[20];

    int res = mini_scanf("%s %d", name, &age);

    if (res == 2)
    {
        printf("\n--- Resultat ---\n");
        printf("Nom : %s\n", name);
        printf("Age : %d\n", age);
    }
    else
        printf("ERROR\n");
}
