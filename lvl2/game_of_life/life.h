#ifndef LIFE_H
# define LIFE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int		life(int width, int height, int it);
char**	fil_map(int width, int height);
void	display_map(char **map);
int		life_it(char **map, int it);

#endif
