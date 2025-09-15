#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_map
{
    int     line;
    char    o;
    char    point;
    char    x;
} t_map;

// BSQ
void    ftread_map(char *av);
char*    nb_of_lines(char *line);

// UTILS
char*   ft_strcat(char *line, int start, int end);
int     ft_strlen(char *line);


#endif