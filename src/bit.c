#include "fillit.h"

void	ft_bitaddtotab(char *map, unsigned short int tetrimino, size_t at)
{
	if (bit)
		map[at / 8] |= 128 >> (at & 7);
	else
		map[at / 8] &= ~(128 >> (at & 7));
}

void	ft_placetetris(char *map, unsigned char tetrimino, size_t at, size_t max)
{
	size_t	i;
	unsigned short	tmp;

	i = 0;
	tmp = tetrimino;
	while (i < 16)
	{
		ft_bitaddtotab(map, ((((tmp << i) & (1 << 7))) << 7) & FIRSTBIT , at);
		i += 1;
		if (!(i % 4))
			at += 4;
		else
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
