#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_map
{
	int		lines;
	char	obstacle;
	char	ground;
	char	square;
	char**	map;
	int		x1;
	int		x2;
}	t_map;

/// BSQ
int	bsq(void);
int	parse_data(char *line, t_map *a, t_map *b);
int	map(t_map *a);
int	draw_map(char** map);

/// UTILS
int	ft_atoi(char *line);
char*	ft_substr(int start, int end, char *line);

#endif
