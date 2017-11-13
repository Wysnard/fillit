#include "fillit.h"

void	ft_bitaddtotab(char *map, short unsigned bit, size_t at)
{
	if (bit)
		map[at / 8] |= 128 >> (at & 7);
	else
		map[at / 8] &= ~(128 >> (at & 7));
}

void	ft_placetetris(char *map, unsigned short int tetrimino, size_t at)
{
	size_t	i;
	short unsigned bit;

	i = 0;
	while (i < 8)
	{
		if (!tetrimino)
			return ;
		ft_bitaddtotab(map, 1, at);
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
