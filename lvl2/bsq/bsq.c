#include "bsq.h"

void    ftread_map(char *av)
{
    int         nread;
    size_t      len = 0;
    FILE        *stream;
    char        *line = NULL;
    int         i;
    t_map       map;
    
    (void) map;
    i = 0;
    stream = fopen(av, "r");
    if (stream == NULL)
    {
        return ;
    }
    while ((nread = getline(&line, &len, stream)) != -1)
    {
        printf("--> %s", line);
        if (i == 0)
        {
            printf("nb of lines: %s\n", nb_of_line(line));
        }
        // else
        //     detect_square(line);
        i++;
    }
    
    fclose(stream);
    return ;
}

char*    nb_of_line(char *line)
{
    int     i;

    i = 0;
    while (line[i])
    {
        if (line[i] >= '0' && line[i] <= '9')
        {
            int     len = 0;
            char    *tmp = line;
            char    *result;
            while (tmp[i] && tmp[i] >= '0' && tmp[i] <= '9')
            {
                len++;
                i++;
            }
            if (tmp[i] == '\0')
                return NULL;
            result = ft_strcat(line, i, len);
            return result;
        }
    }
    return NULL;
}

// void    detect_square(char *line)
// {
//     int     i;
//     int     lenght = 0;
//     int     height = 0;

//     i = 0;
//     while (line[i] && line[i] != '\n')
//     {
//         if (line[i] == '')
//     }
// }