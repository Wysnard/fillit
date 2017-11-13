#include "fillit.h"

void	ft_bitaddtotab(char *map, t_etris *tetris, size_t at)
{
	size_t	i;

	i = 0;
	while (i < 8)
	{
		map[at / 8] |= ((tetris->tetrimino << i) & 1) << (at & 7);
		i += 1;
		at += 1;
	}
}

unsigned short	ft_registerbits(char *buf)
{
	unsigned short	c;
	char		i;

	c = 0;
	i = 15;
	while (i >= 0)
	{
		if (*buf != '.' && *buf != '#' && *buf != '\n')
			return (0);
		if (*buf == '#')
			c = c | (1 << i);
		if (*buf != '\n')
			i -= 1;
		buf += 1;
	}
	return (c);
}
