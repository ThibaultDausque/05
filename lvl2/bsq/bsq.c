#include "bsq.h"

int	bsq(void)
{
	char	*data_map = NULL;
	size_t	len = 0;

	getline(&data_map, &len, stdin);
	fprintf(stdout, "%s", data_map);
	data_map[7] = '\0';
	parse_data(data_map);
	return 0;
}

int	parse_data(char *line)
{
	int		i;
	int		lines;

	i = 0;
	while (line[i])
	{
		if (line[i] < '0' && line[i] > '9' && i == 0)
		{
			fprintf(stdout, "Error: data map format.");
			return 0;
		}
		while (line[i] && line[i] >= '0' && line[i] <= '9')
			i++;
		line = ft_atoi(ft_substr(line, 0, i));
		if (line[i] == '\0')
			break ;
		if (line[i] != ' ' && i > 0 && i % 2 != 0)
		{
			printf("%d", i);
			fprintf(stdout, "Error: space missing.");
			return 0;
		}
		i++;
	}
	if (i != 7)
	{
		fprintf(stdout, "Error: not good length.");
		return 0;
	}
	fprintf(stdout, "OK");
	return lines;
}

int	map(int lines)
{
	
}
