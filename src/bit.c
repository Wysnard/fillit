#include "fillit.h"

void	ft_bitaddtotab(char *map, unsigned short int tetrimino, size_t at)
{
	if (tetrimino)
		map[at / 8] |= 128 >> (at & 7);
	else
		map[at / 8] &= ~(128 >> (at & 7));
}

void	ft_placetetris(char *map, unsigned short tetrimino, size_t at, size_t max)
{
	//size_t	i;

	//i = 0;
	//tetrimino <<= 8;
	/*while (i < 16)
	{
		if ((tetrimino << i) & FIRSTBIT)
			ft_bitaddtotab(map, 1, at);
		i += 1;
		if (!(i & 3))
			at += max;
		else
			at += 1;
	}*/
	map[at / 8] |= tetrimino & 0x0F00;
	at += max;
	map[at / 8] |= tetrimino & 0x00F0;
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
