#include "bsq.h"

int	bsq(void)
{
	char	*data_map = NULL;
	size_t	len = 0;
	t_map	map1;
	t_map	map2;

	getline(&data_map, &len, stdin);
	fprintf(stdout, "%s", data_map);
	printf("nb of bytes: %zu\n", len);
	parse_data(data_map, &map1, &map2);
	map(&map1);
	int		i = 0;
	int		j = 0;
	int		line1;
	int		line2;
	int		start;
	int		end;
	int		final;

	while (a->map[i])
	{
		int		flag = 0;
 		j = 0;
		while (a->map[i][j])
		{
			if (flag == 0 && a->map[i][j] == 'o')
			{
				start = i;
				flag = 1;
			}
			else if (flag == 1 && map[i][j] == 'o')
			{
				end = i;
				flag = 0;
			}
			if (start < end)
				line1 = end - start;
			else
				line1 = start - end;
			j++;
		}
		k = 0;
		if (map[i + 1] == NULL)
			return 0;
		while (a->map[i + 1][k])
		{
			if (flag == 0 && a->map[i][j] == 'o')
			{
				start = i;
				flag = 1;
			}
			else if (flag == 1 && map[i][j] == 'o')
			{
				end = i;
				flag = 0;
			}
			if (start < end)
				line2 = end - start;
			else
				line2 = start - end;
			k++;
		}
		if (i == 0)
		{
			if (line2 > line1)
				final = line2;
			else
				final = line1;
		}
		else if (line2 > line1 && line2 > final)
			final = line2;
		else if (line1 > final)
			final = line1;
		i++;
	}
	return 0;
}

int	draw_square(char **map, int start, int end)
{

	while (map[i][j])
}

int	parse_data(char *line, t_map *a, t_map	*b)
{
	int		i;
	int		end;
	(void) b;

	i = 0;
	if (line[0] < '0' || line[0] > '9')
		return 0;
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		i++;
	end = i;
	if (line[i] != ' ')
	{
		printf("coucou");
		return 0;
	}
	a->lines = ft_atoi(ft_substr(0, end, line));
	printf("nb of lines: %d\n", a->lines);	
	a->ground = line[++i];
	printf("ground char: %c\n", a->ground);
	if (line[++i] != ' ')
		return 0;
	a->obstacle = line[++i];
	printf("obstacle char: %c\n", a->obstacle);
	if (line[++i] != ' ')
		return 0;
	a->square = line[++i];
	printf("square char: %c\n", a->square);
	return 1;
}

int	map(t_map *a)
{
	char	*line = NULL;
	size_t	len = 0;
	int		i = 0;
	int		j = 0;
	a->map = NULL;
	a->map = (char**)malloc((a->lines + 1) * sizeof(char*));
	if (!a->map)
		return 0;
	while (getline(&line, &len, stdin) > 0)
	{
		int		k = 0;
		int		size = 0;
		while (line[k])
		{
			if (line[k] != a->obstacle && line[k] != a->square
				&& line[k] != a->ground && line[k] != '\n' && line[k] != '\0')
			{
				printf("tata\n");
				printf("error: %c\n", line[k]);
				return 0;
			}
			k++;
			size = k;
		}
		if (size != k)
		{
			printf("yoyo\n");
			return 0;
		}
		a->map[i++] = ft_substr(0, k, line);
		j++;
	}
	a->map[i] = NULL;
	if (j != a->lines)
	{
		printf("tutu\n");
		return 0;
	}
	return 1;
}
