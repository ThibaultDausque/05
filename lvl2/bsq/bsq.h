#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	int		height;
	int		width;
	int		sface;
	char	obst;
	char	empty;
	char	draw;
}	t_map;

/// UTILS
int		ft_atoi(char *line);
char*	ft_substr(char *line, int start, int end);

/// BSQ
int	bsq(void);
int	parse_data(char *line, t_map square);
void	display_map(char **map);
int		find_square(char **map, t_map square);
#endif
