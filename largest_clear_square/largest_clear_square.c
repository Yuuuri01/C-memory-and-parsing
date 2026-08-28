#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct lcs
{
    int max;
    int max_col;
    int max_row;
    int row;
    char obstacle;
    char fill;
    int col;
    char empty;
    char **griid;
    int **dp;
} lcs_map;

char *read_map(int fd)
{
    char c;
    char *buff;
    int bytes;
    int max = 1024;
    int i;

    buff = malloc(1024 * sizeof(char));
    if (!buff)
        return NULL;
    i = 0;
    while ((bytes = read(fd, &c, 1)) > 0)
    {
        buff[i++] = c;
        if (i >= max - 1)
        {
            max *= 2;
            char *new_buff = realloc(buff, max);
            if (!new_buff)
            {
                free(buff);
                return NULL;
            }
            buff = new_buff;
        }
    }
    buff[i] = '\0';
    return buff;
}
int grid_to_map(char *grid, lcs_map *info)
{
    info->griid = malloc(info->row * sizeof(char *));
    if (!info->griid)
        return 0;
    int i = -1;
    int k = 0;
    int j;
    while (++i < info->row)
    {
        info->griid[i] = malloc((info->col + 1) * sizeof(char));
        if (!info->griid[i])
            return 0;
        j = -1;
        while (++j < info->col && grid[k] && grid[k] != '\n')
        {
            if (grid[k] != info->empty && grid[k] != info->obstacle)
                return 0;
            info->griid[i][j] = grid[k++];
        }
        if (j != info->col || grid[k] != '\n')
            return 0;
        info->griid[i][j] = '\0';
        k++;
    }
    if (grid[k] != '\0')
        return 0;
    return 1;
}

int get_min(int **dp, int i, int j)
{
    int min = dp[i][j - 1];
    if (min > dp[i - 1][j])
        min = dp[i - 1][j];
    if (min > dp[i - 1][j - 1])
        min = dp[i - 1][j - 1];
    return min;
}
int get_dp(char **grid, lcs_map *info)
{
    info->dp = malloc(info->row * sizeof(int *));
    if (!info->dp)
        return 0;

    int col = info->col;
    int i = -1;
    int j;
    info->max = 0;
    info->max_col = 0;
    info->max_row = 0;

    while (++i < info->row)
    {
        info->dp[i] = malloc(col * sizeof(int));
        if (!info->dp[i])
            return 0;
        j = -1;
        while (++j < col)
        {
            if (grid[i][j] == info->obstacle)
                info->dp[i][j] = 0;
            else if (i == 0 || j == 0)
                info->dp[i][j] = 1;
            else
                info->dp[i][j] = get_min(info->dp, i, j) + 1;

            if (info->dp[i][j] > info->max)
            {
                info->max = info->dp[i][j];
                info->max_row = i;
                info->max_col = j;
            }
        }
    }
    return 1;
}
void print_map(lcs_map *info)
{
    int i = -1;
    while (++i < info->row)
    {
        write(1, info->griid[i], info->col);
        write(1, "\n", 1);
    }
}
void solve_map(lcs_map *info)
{
    int start_row = info->max_row - info->max + 1;
    int start_col = info->max_col - info->max + 1;
    int i = start_row;
    int j;
    while (i <= info->max_row)
    {
        j = start_col;
        while (j <= info->max_col)
            info->griid[i][j++] = info->fill;
        i++;
    }
}

int get_info(char *buff, lcs_map *map, int *new_start)
{
    int i = 0;
    map->row = 0;

    while (buff[i] >= '0' && buff[i] <= '9')
    {
        map->row = map->row * 10 + (buff[i] - '0');
        i++;
    }
    if (map->row <= 0)
        return (0);

    if (buff[i++] != ' ')
        return (0);
    map->empty = buff[i++];
    if (buff[i++] != ' ')
        return (0);
    map->obstacle = buff[i++];
    if (buff[i++] != ' ')
        return (0);

    map->fill = buff[i++];
    if (buff[i++] != '\n')
        return (0);
    if (map->empty < 32 || map->empty > 126)
        return 0;
    if (map->fill < 32 || map->fill > 126)
        return 0;
    if (map->obstacle < 32 || map->obstacle > 126)
        return 0;
    if (map->empty == map->fill || map->empty == map->obstacle || map->fill == map->obstacle)
        return 0;
    *new_start = i;
    return 1;
}

void free_all(char *grid, lcs_map *info)
{
    int j;
    if (info->dp)
    {
        j = 0;
        while (j < info->row)
        {
            if (info->dp[j])
                free(info->dp[j]);
            j++;
        }
        free(info->dp);
    }
    if (info->griid)
    {
        j = 0;
        while (j < info->row)
        {
            if (info->griid[j])
                free(info->griid[j]);
            j++;
        }
        free(info->griid);
    }
    if (grid)
        free(grid);
}
int main(int ac, char **av)
{
    (void)av;
    if (ac > 1)
        return 1;

    char *grid = read_map(0);
    if (!grid || grid[0] == '\0')
    {
        write(1, "map error\n", 10);
        free(grid);
        return 1;
    }
    lcs_map info;
    int new_start = 0;
    if (!get_info(grid, &info, &new_start))
    {
        write(1, "map error\n", 10);
        free(grid);
        return 1;
    }
    char *new_grid = grid + new_start;
    int i = 0;
    while (new_grid[i] && new_grid[i] != '\n')
        i++;
    info.col = i;
    if (!grid_to_map(new_grid, &info))
    {
        free(grid);
        write(1, "map error\n", 10);
        return 1;
    }
    if (!get_dp(info.griid, &info))
    {
        write(1, "map error\n", 10);
        free(grid);
        return 1;
    }
    solve_map(&info);
    print_map(&info);
    free_all(grid, &info);
    return 0;
}