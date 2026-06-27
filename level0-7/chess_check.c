# include <unistd.h>


char **split(char *str)
{
    static char *splited[100]; 
    int i = 0;
    int index = 0;

    if (!str)
        return NULL;

    if (str[i] != '\n' && str[i] != '\0')
    {
        splited[index] = &str[i];
        index++;
    }
    while (str[i])
    {
        if (str[i] == '\n')
        {
            str[i] = '\0';
            
            if (str[i + 1] != '\n' && str[i + 1] != '\0')
            {
                splited[index] = &str[i + 1];
                index++;
            }
        }
        i++;
    }
    splited[index] = NULL;
    return splited;
}
int check_pawn(char **s, int row, int col)
{
    if(row == 0)
        return 0;
    else if(col == 0)
    {
        if(s[row - 1][col + 1] == 'K')
            return 1;
        else
            return 0;
    }
    else if(s[row][col + 1] == '\0')
    {
        if(s[row - 1][col - 1] == 'K')
            return 1;
        else 
            return 0;
    }
    else if(col != 0 && s[row][col + 1])
    {
        if((s[row - 1][col - 1] == 'K') || (s[row - 1][col + 1] == 'K'))
            return 1;
        else
            return 0;
    }
	return 0;
}
int check_bishop(char **s, int row, int col)
{
    int i;
    int j;

    i = row - 1;
    j = col + 1;
    while((i >= 0 && j >= 0) && (s[i] && s[i][j]))
    {
        if(s[i][j] == 'K')
            return 1;
        else if(s[i][j] != '.')
            break;
        i--;
        j++;
    }

    i = row - 1;
    j = col - 1;
    while((i >= 0 && j >= 0) && (s[i] && s[i][j]))
    {
        if(s[i][j] == 'K')
            return 1;
        else if(s[i][j] != '.')
            break;
        i--;
        j--;
    }

    i = row + 1;
    j = col + 1;
    while((i >= 0 && j >= 0) && (s[i] && s[i][j]))
    {
        if(s[i][j] == 'K')
            return 1;
        else if(s[i][j] != '.')
            break;
        i++;
        j++;
    }

    i = row + 1;
    j = col - 1;

    while((i >= 0 && j >= 0) && (s[i] && s[i][j]))
    {
        if(s[i][j] == 'K')
            return 1;
        else if(s[i][j] != '.')
            break;
        i++;
        j--;
    }
    return 0;
}
int check_rock(char **s, int row, int col)
{
    int i;
    int j;

    //up row
    i = row - 1;
    j = col;
    while(i >= 0 && s[i])
    {
        if(s[i][j] == 'K')
            return 1;
        else if(s[i][j] != '.' && s[i][j] != 'R')
            break;
        i--;
    }
    //row down
    i = row + 1;
    j = col;
    while(i >= 0 && s[i])
    {
        if(s[i][j] == 'K')
            return 1;
        else if(s[i][j] != '.' && s[i][j] != 'R')
            break;
        i++;
    }
    //col left to right
    i = row;
    j = col + 1;
    while(j >= 0 && s[i][j])
    {
        if(s[i][j] == 'K')
            return 1;
        else if(s[i][j] != '.' && s[i][j] != 'R')
            break;
        j++;
    }
    //col right to left
    i = row;
    j = col - 1;
    while(j >= 0 && s[i][j])
    {
        if(s[i][j] == 'K')
            return 1;
        else if(s[i][j] != '.' && s[i][j] != 'R')
            break;
        j--;
    }
    return 0;
}
int check_queen(char **s, int row, int col)
{
    if(check_bishop(s, row, col) || check_rock(s, row, col))
        return 1;
    else
        return 0;
}
void chess_check(char *s, int *found)
{
    char **board = split(s);
    int row = 0;
    int col;
    int success = 0;
    while(board[row])
    {
        col = 0;
        while(board[row][col])
        {
            if(board[row][col] == 'P')
            {
                if(check_pawn(board, row, col))
                    success = 1;
            }
            else if(board[row][col] == 'B')
            {
                if(check_bishop(board, row, col))
                    success = 1;
            }
            else if(board[row][col] == 'R')
            {
                if(check_rock(board, row, col))
                    success = 1;
            }
            else if(board[row][col] == 'Q')
            {
                if(check_queen(board, row, col))
                    success = 1;
            }
			else if(board[row][col] == 'K')
				*found = 1;
            col++;
        }
        if(success)
        {
            write(1, "Success\n", 8);
            return;
        }
        row++;
    }
	if(*found == 0)
		return;
	if(!success)
        write(1, "Fail\n", 5);
}
int main(int argc, char **argv)
{
    if(argc == 2)
    {
		int found = 0;
        chess_check(argv[1], &found);
    }
}