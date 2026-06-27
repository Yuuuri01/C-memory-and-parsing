#include <unistd.h>

int is_op(char c)
{
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
        return 1;
    return 0;
}
void ft_putnbr(int nb)
{
    if(nb < 0)
    {
        write(1, "-", 1);
        nb = -nb;
    }
    if(nb > 9)
        ft_putnbr(nb / 10);
    char c = (nb % 10) + 48;
    write(1, &c, 1);
}
char **split(char *str)
{
    static char *buff[100];
    int index = 0;
    int i = 0;

    if(str[i] != ' ')
        buff[index++] = &str[i];

    while(str[i])
    {
        if(str[i] == ' ')
        {
            str[i] = '\0';

            if(str[i + 1] != ' ' && str[i + 1] != '\0')
                buff[index++] = &str[i + 1];
        }
        i++;
    }
    buff[index] = NULL;
    return buff;
}
int ft_atoi(char *str)
{
	int i = 0;
	int res = 0;
	int sign = 1;

	while(str[i] == ' ' || str[i] == '\t')
		i++;
	if(str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
			sign = -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return res * sign;
}
void do_op(int *tab, char op, int *index, int *error)
{
	if(!tab)
	{
		*error = -1;
		return;
	}
	int nb2 = tab[*index];
	int nb1 = tab[*index - 1];
	int res = 0;
	if(op == '+')
		res = nb1 + nb2;
	else if(op == '-')
		res = nb1 - nb2;
	else if(op == '*')
		res = nb1 * nb2;
	else if(op == '/')
	{
		if(nb2 == 0)
		{
			*error = -1;
			return;
		}
		res = nb1 / nb2;
	}
	else if(op == '%')
	{
		if(nb2 == 0)
		{
			*error = -1;
			return;
		}
		res = nb1 % nb2;
	}
	tab[*index - 1] = res;
	(*index)--;
}

# include <stdio.h>
int	main(int argc, char **argv)
{
	if(argc == 2)
	{
		int i = 0;
		int index = -1;
		int err = 0;
		int arr[500];
        char **av = split(argv[1]);
		while(av[i])
		{
			if(!is_op(av[i][0]))
				arr[++index] = ft_atoi(av[i]);
			else if(is_op(av[i][0]))
			{
				do_op(arr, av[i][0], &index, &err);
				if(err == -1)
				{
					write(1, "Error\n", 6);
					return 0;
				}
			}
			i++;
		}
        if(index != 0)
            write(1, "Error", 5);
        else
            ft_putnbr(arr[0]);
        write(1, "\n", 1);
    }
	else
		write(1, "Error\n", 6);
}
