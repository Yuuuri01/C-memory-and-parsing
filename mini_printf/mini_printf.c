#include <stdarg.h>
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
int options(char c)
{
    if(c == 's' || c == 'd' || c == 'x' || c == 'c')
        return 1;
    return 0;
}
int ft_putnbr(long nb)
{
    int count = 0;
    if(nb < 0)
    {
        write(1, "-", 1);
        count++;
        nb = -nb;
    }
    if(nb > 9)
        count += ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + 48);
    count++;
    return count;
}
int print_hex(unsigned int nb)
{
    char base[] = "0123456789abcdef";
    int count = 0;
    if(nb >= 16)
        count += print_hex(nb / 16);
    ft_putchar(base[nb % 16]);
    return count + 1;
}
int	mini_printf(const char *format, ...)
{
	va_list args;
    int count = 0;

    va_start(args, format);
    while(*format)
    {
        if(*format == '%' && options(*(format + 1)))
        {
            format++;
            if(*format == 's')
            {
                char *str = va_arg(args, char *);
                if(!str)
                    str = "(null)";
                while(*str)
                {
                    write(1, str, 1);
                    str++;
                    count++;
                }
            }
            else if(*format == 'd')//"balance %d, count %d\n"
            {
                int val = va_arg(args, int);
                count += ft_putnbr(val);
            }
            else if(*format == 'c')
            {
                char c = va_arg(args, int);
                ft_putchar(c);
                count++;
            }
            else if(*format == 'x')
            {
                unsigned int hex = va_arg(args, unsigned int);
                count += print_hex(hex);
            }
        }
        else
        {
            if(*format == '%' && *(format + 1) == '%')
            {
                ft_putchar(*format);
                count++;
                format++;
            }
            else
            {
                ft_putchar(*format);
                count++;
            }
        }
        format++;
    }
    va_end(args);
    return count;
}
# include <stdio.h>
int main()
{
    int count = mini_printf("100%% sure, %q stays\n");
    // int count = mini_printf("hi %s, %d+%d=%d %c %x%%\n", "dev", 2, 3, 5, '!', 255);
    // int count = mini_printf("min int is %d\n", -2147483648);
    printf("%d\n", count);
}

// //printf("hi %s, %d+%d=%d %c %x%%\n", "dev", 2, 3, 5, '!', 255)

// // hi dev, 2+3=5 ! ff%

