#include "game_of_life.h"

int main(int ac, char **av)
{
    int     width;
    int     height;
    int     it;

    if (ac != 4)
        return 0;
    width = atoi(av[1]);
    height = atoi(av[2]);
    it = atoi(av[3]);
    game_of_life(width, height);
    return 0;
}