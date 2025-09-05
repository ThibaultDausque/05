#include "bsq.h"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        printf("Faut un fichier mon reuf\n");
        return 0;
    }
    ftread_map(av[1]);
    return 0;
}