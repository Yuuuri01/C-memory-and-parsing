

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int get_min(int **dp, int col, int row)
{
    int left = dp[row][col - 1];
    int up_left = dp[row - 1][col - 1];
    int up = dp[row - 1][col];

    int min = up_left;
    if (left < min)
        min = left;
    if (up < min)
        min = up;
    return min;
}
int **get_dp(char **map, int col, int row, char obs, int *max_col, int *max_row, int *max)
{
    int **dp = malloc(4 * sizeof(int *));
    col = row;
    int i = 0;
    int j;
    while (i < row)
    {
        dp[i] = malloc(col * sizeof(int));
        if (!dp[i])
            return NULL;
        j = 0;
        while (j < col)
        {
            if (map[i][j] == obs)
                dp[i][j] = 0;

            else if (i == 0 || j == 0)
                dp[i][j] = 1;
            else
            {
                int min = get_min(dp, j, i) + 1;
                dp[i][j] = min;
                *max_col = j;
                *max_row = i;
                *max = min;
            }
            j++;
        }
        i++;
    }
    return dp;
}

void print_map(char **map, int max, int max_col, int max_row)
{
    int start_col;
    int start_row;
    int i;
    int j;

    start_col = max_col - max + 1;
    start_row = max_row - max + 1;
    i = start_row;
    while (i <= max_row)
    {
        j = start_col;
        while (j <= max_col)
            map[i][j++] = 'x';
        i++;
    }
}

int main()
{
    char **str = malloc(4 * sizeof(char *));

    str[0] = strdup("....");
    str[1] = strdup("....");
    str[2] = strdup("....");
    str[3] = strdup("....");

    int max_col = 0;
    int max_row = 0;
    int max = 0;
    int **dp;
    if (!(dp = get_dp(str, 4, 3, '#', &max_col, &max_row, &max)))
    {
        write(1, "map error\n", 10);
        return 0;
    }
    print_map(str, max, max_col, max_row);
    int i = 0;
    while (i < 3)
    {
        write(1, str[i], 4);
        write(1, "\n", 1);
        free(str[i]);
        free(dp[i]);
        i++;
    }
    free(str);
    free(dp);
}