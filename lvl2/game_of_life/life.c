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
	display_map(map);
	if (it > 0)
		life_it(map, it, width, height);
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

int	diagonal(char **map, int i, int j, int width, int height)
{
	int		count = 0;

	if (!map)
		return 0;
	if (j < width - 1 && i > 0)
	{
		if (map[i][j + 1] && map[i - 1][j + 1] == 'O')
			count++;
	}
	if (j > 0 && i > 0)
	{
		if (map[i][j - 1] && map[i - 1][j - 1] == 'O')
			count++;
	}
	if (j < width - 1 && i < height - 1)
	{
		if (map[i][j + 1] && map[i + 1][j + 1] == 'O')
				count++;
	}
	if (j > 0  && i < height - 1)
	{
		if (map[i][j - 1] && map[i + 1][j - 1] == 'O')
			count++;
	}
	return count;
}

int	free_map(char **map)
{
	int		i = 0;

	if (!map)
		return 0;
	while (map[i])
		free(map[i++]);
	// free(map);
	return 1;
}

int	life_it(char **map, int it, int width, int height)
{
	int		i = 0;
	int		j = 0;
	char	**clean_map = fil_map(width, height);
	int		life = 0;
	int		death = 0;
	int		k = 0;

	if (!map)
		return 0;
	while (k < it)
	{
		i = 0;
		while (map[i])
		{
			j = 0;
			while (map[i][j])
			{
				life = 0;
				death = 0;
				if (map[i][j] == ' ')
				{
					if (i > 0 && map[i - 1][j] == 'O')
						death++;
					if (i < height - 1 && map[i + 1][j] == 'O')
						death++;
					if (j > 0 && map[i][j - 1] == 'O')
						death++;
					if (j < width - 1 && map[i][j + 1] == 'O')
						death++;
					death += diagonal(map, i, j, width, height);
				}
				else if (map[i][j] == 'O' && i > 0 && j > 0
					&& i < height - 1 && j < width - 1)
				{
					if (i > 0 && map[i - 1][j] == 'O')
						life++;
					if (i < height && map[i + 1][j] == 'O')
						life++;
					if (j > 0 && map[i][j - 1] == 'O')
						life++;
					if (j < width && map[i][j + 1] == 'O')
						life++;
					life += diagonal(map, i, j, width, height);
				}
				if (map[i][j] == ' ' && death == 3)
					clean_map[i][j] = 'O';
				else if (map[i][j] == 'O' && life != 2 && life != 3)
					clean_map[i][j] = ' ';
				else if (map[i][j] == 'O')
					clean_map[i][j] = 'O';
				j++;
			}
			i++;
		}
		free_map(map);
		map = clean_map;
		free_map(clean_map);
		clean_map = fil_map(width, height);
		k++;
	}
	display_map(map);
	return 1;
}
