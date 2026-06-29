# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>


int ft_strlen(char *str) {int i = 0; while(str[i]) i++; return i;}
int is_op(char c) {return (c == '+' || c == '*');}

void do_op(int *nums, int *index, char op) {int nb2 = nums[*index]; int nb1 = nums[*index - 1]; int res = 0; if(op == '+') res = nb1 + nb2; else if(op == '*') res = nb1 * nb2; nums[*index - 1] = res;(*index)--;}

int handle_with_paren(char *av, char *op, int *nums)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int nb_i = -1;
    int op_i = -1;
    int found = 0;
    int paren = 0;
    while(av[i])
    {
        if(av[i] == '(')
        {
            paren = 1;
            j = i + 1;
            k = j;
            while(paren > 0 && av[j])
            {
                if(av[j] == '(')
                    paren++;
                else if(av[j] == ')')
                    paren--;
                if(paren > 0)
                    j++;
            }

            char tmp_buff[100] = {0};
            int l = 0;
            while(l < j - k)
            {
                tmp_buff[l] = av[k + l];
                l++;
            }

            char tmp_op[100] = {0};
            int tmp_nums[100] = {0};
            int res = handle_with_paren(tmp_buff, tmp_op, tmp_nums);

            nums[++nb_i] = res;

            if(found)
            {
                do_op(nums, &nb_i, op[op_i]);
                op_i--;
                found = 0;
            }
            i = j;
        }
        else
        {
            if(av[i] != ')' && !is_op(av[i]))
            {
                nums[++nb_i] = av[i] - '0';
                if(found)
                {
                    do_op(nums, &nb_i, op[op_i]);
                    op_i--;
                    found = 0;
                }
            }
            else if(is_op(av[i]))
            {
                op[++op_i] = av[i];
                if(av[i] == '*')// mul applay here
                    found = 1;
            }
        }
        i++;
    }

    i = 0;
    while(op_i >= 0)
    {
        do_op(nums, &nb_i, op[op_i]);
        op_i--;
    }
    return nums[0];
}
int handle_without_paren(char *av, char *op, int *nums)
{
    int i = 0;
    int op_i = -1;
    int nb_i = -1;
    int found = 0;

    //handle only *
    while(av[i])
    {
        if(!is_op(av[i]))
        {
            nums[++nb_i] = av[i] - 48;
        }
        if(found)
        {
            do_op(nums, &nb_i, op[op_i]);
            op_i--;
            found = 0;
        }
        if(is_op(av[i]))
        {
            if(av[i] == '*')            
                found = 1;

            op[++op_i] = av[i];
        }
        i++;
    }

    while(nb_i > 0)
    {
        do_op(nums, &nb_i, op[op_i--]);
    }
    return nums[0];
}
int main(int ac, char **av)
{
    if(ac != 2)
        return 1;

    int len = ft_strlen(av[1]);
    int i = 0;
    int j = 0;
    int k = 0;
    int tokens = 0;
    int paren = 0;
    int *nums;
    char *op;

    if(len == 0)
    {
        printf("Unexpected end\n");
		return 1;
    }

    while(av[1][i])
    {
        if(av[1][i] == '(')
            tokens++;
        else if(av[1][i] == ')')
        {
            if(tokens == 0)
            {
                printf("Invalid token ')'\n");
				return 1;
            }
            paren = 1;
            tokens--;
        }
        else if(av[1][i] >= '0' && av[1][i] <= '9')
            j++;
        else if(is_op(av[1][i]))
            k++;
        else if(av[1][i] != '(' && av[1][i] != ')')
        {
            printf("Invalid token '%c'\n", av[1][i]);
			return 1;
        }
        i++;
    }
    if(tokens != 0 || is_op(av[1][i - 1]))
    {
        printf("Unexpected end\n");
		return 1;
    }
    nums = calloc(j, sizeof(int));
    op  = malloc((k * sizeof(char)));
    if(!nums || !op)
        return 1;
    
    if(paren)
    {
        printf("%d\n",  handle_with_paren(av[1], op, nums));
    }
    else
    {
        printf("%d\n", handle_without_paren(av[1], op, nums));
    }

}
