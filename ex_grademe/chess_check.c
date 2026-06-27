#include <unistd.h>

char **split(char *str)
{
    static char *buff[100];
    int i = 0;
    int index = 0;
    if(str[i] != '\n' && str[i] != '\0')
        buff[index++] = &str[i];
    while(str[i])
    {
        if(str[i] == '\n')
        {
            str[i] = '\0';
            if(str[i + 1] != '\n' && str[i + 1] != '\0')
                buff[index++] = &str[i + 1];
        }
        i++;
    }
    buff[index] = NULL;
    return buff;
}
int check_pwn(char **board, int row, int col)
{
    if(row == 0)
        return 0;
    if(col == 0 && row != 0)
    {
        if(board[row - 1][col + 1] == 'K')
            return 1;
        else
            return 0;
    }
    else if(board[row][col + 1] == '\0')
    {
        if(board[row - 1][col - 1] == 'K')
            return 1;
        else
            return 0;
    }
    else
        if((board[row - 1][col + 1] == 'K') || (board[row - 1][col - 1] == 'K'))
            return 1;
    return 0;
}
int check_bishop(char **board, int row, int col)
{
    int i;
    int j;

    i = row - 1;
    j = col - 1;
    while((j >= 0 && i >= 0) && (board[i] && board[i][j]))
    {
        if(board[i][j] == 'K')
            return 1;
        else if(board[i][j] != '.')
            break;
        i--;
        j--;
    }

    i = row + 1;
    j = col + 1;
    while((j >= 0 && i >= 0) && (board[i] && board[i][j]))
    {
        if(board[i][j] == 'K')
            return 1;
        else if(board[i][j] != '.')
            break;
        i++;
        j++;
    }

    i = row - 1;
    j = col + 1;

    while((j >= 0 && i >= 0) && (board[i] && board[i][j]))
    {
        if(board[i][j] == 'K')
            return 1;
        else if(board[i][j] != '.')
            break;
        i--;
        j++;
    }

    i = row + 1;
    j = col - 1;
    while((i >= 0 && j >= 0) && (board[i] && board[i][j]))
    {
        if(board[i][j] == 'K')
            return 1;
        else if(board[i][j] != '.')
            break;
        i++;
        j--;
    }
    return 0;
}
int check_rock(char **board, int row, int col)
{
    int i;
    int j;

    i = row + 1;
    while(i >= 0 && board[i])
    {
        if(board[i][col] == 'K')
            return 1;
        else if(board[i][col] != '.' && board[i][col] != 'R')
            break;
        i++;
    }

    i = row - 1;
    while(i >= 0 && board[i])
    {
        if(board[i][col] == 'K')
            return 1;
        else if(board[i][col] != '.' && board[i][col] != 'R')
            break;
        i--;
    }

    j = col + 1;
    while(j >= 0 && board[row][j])
    {
        if(board[row][j] == 'K')
            return 1;
        else if(board[row][j] != '.' && board[row][j] != 'R')
            break;
        j++;
    }

    j = col - 1;
    while(j >= 0 && board[row][j])
    {
        if(board[row][j] == 'K')
            return 1;
        else if(board[row][j] != '.' && board[row][j] != 'R')
            break;
        j--;
    }
    return 0;
}
int check_queen(char **str, int row, int col)
{
    return (check_bishop(str, row, col) || check_rock(str, row, col));
}
int king(char **str)
{
    int i = 0;
    int j;

    while(str[i])
    {
        j = 0;
        while(str[i][j])
        {
            if(str[i][j] == 'K')
                return 1;
            j++;
        }
        i++;
    }
    return 0;
}
int	main(int ac, char **av)
{
    if(ac == 2)
    {
        int success = 0;
        int j;
        int i;
        char **board = split(av[1]);
        
        if(king(board) == 0)
        {
            return 0;
        }

        i = 0;
        while(board[i])
        {
            j = 0;
            while(board[i][j])
            {
                if(board[i][j] == 'P')
                {
                    if(check_pwn(board, i, j))
                        success = 1;
                }
                else if(board[i][j] == 'B')
                {
                    if(check_bishop(board, i, j))
                        success = 1;
                }
                else if(board[i][j] == 'R')
                {
                    if(check_rock(board, i, j))
                        success = 1;
                }
                else if(board[i][j] == 'Q')
                {
                    if(check_queen(board, i, j))
                        success = 1;
                }
                if(success)
                {
                    write(1, "Success\n", 8);
                    return 0;
                }
                j++;
            }
            i++;
        }
        if(!success)
        {
            write(1, "Fail\n", 5);
            return 0;
        }
    }   
}
