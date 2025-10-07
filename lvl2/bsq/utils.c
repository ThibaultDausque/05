#include "bsq.h"

int	ft_atoi(char *line)
{
	int		i;
	int		result;
	
	i = 0;
	result = 0;
	while (line[i])
	{
		result *= 10;
		result += line[i] - '0';
		i++;
	}
	return result;
}

char*	ft_substr(char *line, int start, int end)
{
	int		i;
	int		len;
	char	*result;

	len = end - start;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return 0;
	i = 0;
	while (start < end)
		result[i++] = line[start++];
	result[i] = '\0';
	return result;
}
