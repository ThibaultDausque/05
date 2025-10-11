#include "life.h"

int	main(int ac, char **av)
{
	if (ac != 4)
		return 0;
	int		width = atoi(av[1]);
	int		height = atoi(av[2]);
	int		it = atoi(av[3]);

	life(width, height, it);
	return 0;
}
