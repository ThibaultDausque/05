#include "bsq.h"

void    ftread_map(char *av)
{
    int         nread;
    size_t      len = 0;
    FILE        *stream;
    char        *line = NULL;
    int         i;
    int         j;
    t_map       *map;
    
    map = (t_map *)malloc(sizeof(t_map));
    if (!map)
        return ;
    i = 0;
    j = 0;
    stream = fopen(av, "r");
    if (stream == NULL)
        return ;
    while ((nread = getline(&line, &len, stream)) != -1)
    {
        if (i == 0)
        {
            if (!nb_of_line(line, map))
                return ;
            printf("nb of lines: %s\n", nb_of_line(line, map));
            if (!parse_inf(line, map))
                return ;
            map->tab = (char **)malloc((map->line + 1) * sizeof(char *));
            if (!map->tab)
            {
                printf("tab** malloc error\n");
                return ;
            }
        }
        else
        {
            if (j < map->line)
                map->tab[j] = ft_strcpy(line);
            j++;
        }
        i++;
    }
    map->tab[j] = NULL;
    detect_square(map);
    fclose(stream);
    return ;
}

char*    nb_of_line(char *line, t_map *map)
{
    int     i;

    i = 0;
    while (line[i])
    {
        if (line[i] >= '0' && line[i] <= '9')
        {
            int     len = i;
            char    *result;
            while (line[len] && line[len] >= '0' && line[len] <= '9')
                len++;
            if (line[i] == '\0')
                return NULL;
            result = ft_strcat(line, i, len);
            map->line = ft_atoi(result);
            return result;
        }
        i++;
    }
    printf("Error: nb of lines");
    return NULL;
}

int    parse_inf(char *line, t_map *map)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (line[i] && line[i] >= '0' && line[i] <= '9')
        i++;
    if (line[i] == '\0')
    {
        printf("Error: info line error");
        return 0;
    }
    else if (line[i] == ' ')
    {
        i++;
        while (line[i])
        {
            if (line[i] >= 33 && line[i] <= 126)
            {
                if (j == 0)
                {
                    map->empty = line[i];
                    j++;
                }
                else if (j == 1)
                {
                    map->obstacle = line[i];
                    j++;
                }
                else if (j == 2)
                    map->full = line[i];
            }
            i++;
        }
        if (!map->empty || !map->full|| !map->obstacle)
        {
            printf("Error: first line parameters");
            return 0;
        }
    }
    return 1;
}

void    detect_square(t_map *map)
{
    int     x1 = 0;
    int     x2 = 0;
    int     length;
    int     y1 = 0;
    int     y2 = 0;
    int     height;
    int     i;
    int     j;

    i = 0;
    while (map->tab[i])
    {
        while (map->tab[i][j])
        {
            // trouver le plus grand carre possible
        }
    }

    return;
}