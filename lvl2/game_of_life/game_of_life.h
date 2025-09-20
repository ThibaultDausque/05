#ifndef GAME_OF_LIFE_H
# define GAME_OF_LIFE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int     game_of_life(int wt, int ht);
void    put_map(char **map);
int     write_map(char **map, int ht, int wt);

#endif