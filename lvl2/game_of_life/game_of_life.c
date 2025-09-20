#include "game_of_life.h"

int game_of_life(int wt, int ht)
{
    char    *line;
    char    **map;
    int     i = 0;
    int     k = 0;

    map = (char**)malloc((ht + 1) * sizeof(char*));
    if (!map)
    {
        printf("Malloc error (char **)");
        return 0;
    }
    while (i < ht)
    {
        line = (char*)malloc((wt + 1) * sizeof(char));
        if (!line)
        {
            printf("malloc error (char *)");
            return 0;
        }
        int j = 0;
        while (j < wt)
        {
            line[j] = '*';
            j++;
        }
        line[j] = '\0';
        map[k++] = line;
        i++;
    }
    map[k] = NULL;
    i = 0;
    while (i < ht)
        printf("%s\n", map[i++]);
    printf("\n");
    write_map(map, ht, wt);
    return 0;
}

// w == pen up, a == left, s == bottom, d == right
// x == lift or lower the pen
int write_map(char **map, int ht, int wt)
{
    int     i = 0;
    int     j = 0;
    int     x = 0;
    int     x_read = 0;
    char    buf;

    while (read(0, &buf, 1) > 0)
    {
        if (buf == 'x' && x_read == 0)
        {
            map[i][j] = '0';
            x = 1;
            x_read = 1;
        }
        else if (buf == 'x' && x_read == 1)
        {
            map[i][j] = '0';
            x = 0;
            x_read = 0;
        }
        if (buf == 'w')
        {
            if (x == 1)
                map[i][j] = '0';
            if (i > 0)
                i--;
            if (x == 1)
                map[i][j] = '0';
        }
        if (buf == 'a')
        {
            if (x == 1)
                map[i][j] = '0';
            if (j > 0)
                j--;
            if (x == 1)
                map[i][j] = '0';
        }
        if (buf == 's')
        {
            if (x == 1)
                map[i][j] = '0';
            if (i < ht)
                i++;
            if (x == 1)
                map[i][j] = '0';
        }
        if (buf == 'd')
        {
            if (x == 1)
                map[i][j] = '0';
            if (j < wt)
                j++;
            if (x == 1)
                map[i][j] = '0';
        }
    }
    put_map(map);
    return 0;
}

void    put_map(char **map)
{
    int     i = 0;

    while (map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }
    i = 0;
    while (map[i])
        free(map[i++]);
    free(map);
}
