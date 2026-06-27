# include <unistd.h>
# include <stdlib.h>


void ft_putnbr(int nb)
{
    if(nb > 9)
        ft_putnbr(nb / 10);
    char c = (nb % 10) + 48;
    write(1, &c, 1);
}
int isSafe(int *borad, int row, int col)
{
    int i = 0;
    while(i < row)
    {
        if(borad[i] == col)
            return 0;
        else if(borad[i] + i == col + row)
            return 0;
        else if(borad[i] - i == col - row)
            return 0;
        i++;
    }
    return 1;
}
void print_solution(int *board, int n)
{
    int i = 0;
    while(i < n)
    {
        ft_putnbr(board[i++]);
        if(i != n)
            write(1, " ", 1);
    }
    write(1, "\n", 1);    
}
void queen_board(int *board, int row, int n)
{
    if(row == n)
    {
        print_solution(board, n);
        return;
    }
    int col = 0;
    while(col < n)
    {
        if(isSafe(board, row, col))
        {
            board[row] = col;
            queen_board(board, row + 1, n);
        }
        col++;
    }
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        int n = atoi(av[1]);
        int board[n];

		if(n == 1)
			write(1, "0\n", 2);
        else if(n != 2 && n != 3)
            queen_board(board, 0, n);
    }
    else
        return 1;
}