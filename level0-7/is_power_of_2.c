int is_power_of_2(unsigned int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
	unsigned int res = 2;
	unsigned int i = 2;
    while(res <= n)
	{
		if(res == n)
			return 1;
		res *= i;
	}
	return 0;
}
# include <stdio.h>
int main()
{
    printf("%d\n", is_power_of_2(6));
}