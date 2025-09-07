#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_map
{
    int     line;
    char    obstacle;
    char    empty;
    char    full;
    int     len_x;
    int     len_y;
    char    **tab;
} t_map;

// BSQ
void    ftread_map(char *av);
char*   nb_of_line(char *line, t_map *map);
int     parse_inf(char *line, t_map *map);
void    detect_square(t_map *map);

// UTILS
char*   ft_strcat(char *line, int start, int end);
int     ft_strlen(char *line);
int     ft_atoi(char *line);
char*   ft_strcpy(char *line);


#endif