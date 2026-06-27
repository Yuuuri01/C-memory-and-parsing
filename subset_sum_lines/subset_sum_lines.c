//using DFS algorithm
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>


void print_res(int *buff, int n)
{
    int i;
    i = 0;
    while(i < n)
    {
        printf("%d", buff[i++]);
        if(i != n)
            printf(" ");
    }
    printf("\n");
}
void solv_depth_first_search(int *tab, int *buff, int target, int index, int size, int n)
{
    if(index == size)
    {
        if(target == 0)
        {
            print_res(buff, n);
        }
        return;
    }
    buff[n] = tab[index];
    solv_depth_first_search(tab, buff, target - tab[index], index + 1, size, n + 1);
    solv_depth_first_search(tab, buff, target, index + 1, size, n);
}
int main(int ac, char **av)
{
    if(ac <= 2)
        return 1;

    int *buff;
    int *tab;
    int target = atoi(av[1]);
	if(target == 0)
	{
		write(1, "\n", 1);
		return 0;
	}
    int count = ac - 2;
    int i = ac - count;
    int j;
    buff = malloc((count + 1) * sizeof(int ));
    tab = malloc((count + 1) * sizeof(int ));
    if(!tab || !buff)
        return 1;
    j = 0;
    while(j < count)
	{
        tab[j] = atoi(av[j + i]);
		j++;
	}
    
    solv_depth_first_search(tab, buff, target, 0, count, 0);
    free(buff);
    free(tab);
}
//./a.out 6 1 4 5
