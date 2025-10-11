#include "life.h"

// w -> up
// a -> left
// s -> bottom
// d -> right
//
// x -> lift/low the pen

int		life(int width, int height, int it)
{
	size_t	bytes = 1;
	char	c;
	int		flag = 0;
	char	**map;
	int		i = 0;
	int		j = 0;
	(void) it;
	
	map = fil_map(width, height);
	if (!map)
		return 0;
	while (read(0, &c, bytes) != 0)
	{
		if (c == 'x' && flag == 0)
		{
			map[i][j] = 'O';
			flag = 1;
		}
		else if (c == 'x' && flag == 1)
			flag = 0;
		if (c == 'w')
		{
				--i;
			if (flag == 1)
				map[i][j] = 'O';
		}
		else if (c == 'a')
		{
				--j;
			if (flag == 1)
				map[i][j] = 'O';
		}
		else if (c == 's')
		{
				++i;
			if (flag == 1)
				map[i][j] = 'O';
		}
		else if (c == 'd')
		{
				++j;
			if (flag == 1)
				map[i][j] = 'O';
		}
	}
	if (it == 0)
		display_map(map);
	else
		life_it(char **map, int it);
	return 0;	
}

void	display_map(char **map)
{
	int		i = 0;
	int		j = 0;

	if (!map)
		return ;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			putchar(map[i][j]);
			j++;
		}
		putchar('\n');
		i++;
	}
}

char**	fil_map(int width, int height)
{
	int		i = 0;
	int		j = 0;
	char**	map;

	map = (char**)malloc((height + 1) * sizeof(char*));
	if (!map)
		return NULL;
	while (i < height)
	{
		map[i] = (char*)malloc((width + 1) * sizeof(char));
		if (!map[i])
			return 0;
		j = 0;
		while (j < width)
		{
			map[i][j] = ' ';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return map;
}

int	life_it(char **map, int it, int widht, int height)
{
	int		i = 0;
	int		j = 0;
	char	**clean_map = fil_map(width, height);

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			
		}
		i++;
	}

}
