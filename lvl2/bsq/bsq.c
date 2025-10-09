#include "bsq.h"

int	bsq(void)
{
	char	*data_map = NULL;
	size_t	len = 0;
	int		lines;
	t_map	*square;
	char	**map;


	square = (t_map*)malloc(sizeof(t_map));
	if (!square)
		return 0;
	getline(&data_map, &len, stdin);
	fprintf(stdout, "%s", data_map);
	int		i = 0;
	while (data_map[i] && data_map[i] != '\n')
		i++;
	data_map[i] = '\0';
	lines = parse_data(data_map, *square);
	square->height = lines;
	map = (char**)malloc((lines + 1) * sizeof(char*));
	if (!map)
		return 0;
	i = 0;
	int		j = 0;
	while (getline(&data_map, &len, stdin) != -1)
	{
		j = 0;
		while (data_map[j] && data_map[j] != '\n')
			j++;
		data_map = (char *)malloc((j + 1) * sizeof(char));
		if (!data_map)
			return 0;
		data_map[j] = '\0';
		map[i] = data_map;
		i++;
	}
	square->width = j;
	map[i] = NULL;
	display_map(map);
	find_square(map, *square);
	return 0;
}

int	find_square(char **map, t_map square)
{
	int		i = 0;
	int		j = 0;
	int		posx = 0;
	int		posy = 0;

	fprintf(stdout, "map width = %d\n", square.width);
	fprintf(stdout, "map height = %d\n", square.height);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			j++;
		}
		i++;
	}
	return 0;
}

void	display_map(char **map)
{
	int		i = 0;

	if (!map)
		return ;
	while (map[i])
		fprintf(stdout, "%s", map[i++]);
}

int	parse_data(char *line, t_map square)
{
	int		i;
	int		lines;
	int		flag;
	int		old;
	
	i = 0;
	flag = 0;
	while (line[i])
	{
		if (line[i] < '0' && line[i] > '9' && i == 0)
		{
			fprintf(stdout, "Error: data map format.");
			return 0;
		}
		while (line[i] && line[i] >= '0' && line[i] <= '9')
		{
			if (line[i] == ' ')
			{
				old = i;
				if (old != i)
				{
					fprintf(stdout, "Error: Bad map.\n");
					return 0;
				}
			}
			if (i == 0)
				flag = 1;
			i++;
		}
		if (flag == 1)
		{
			char*	nb = ft_substr(line, 0, i - 1);
			printf("char* lines: %s\n", nb);
			lines = ft_atoi(nb);
			if (line[i] != ' ')
			{
				fprintf(stdout, "Error: missings spaces.\n");
				return 0;
			}
			flag = 0;
		}
		if (line[i] != ' ')
		{
			if (line[i + 1] != c)
			{
				fprintf(stdout, "Error: bad map data.\n");
				return 0;
			}
		}
		if (line[i] == '\0')
			break ;
		i++;
	}
	if (i != 7)
	{
		fprintf(stdout, "Error: not good length.");
		return 0;
	}
	return lines;
}

