#include "bsq.h"

int	main(void)
{
	char	*line;
	size_t	len = 0;
	

	while (getline(&line, &len, stdin) != -1)
		fprintf(stdout, "%s", line);
	return 0;
}
