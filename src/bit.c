#include "fillit.h"

void	ft_bitaddtotab(char *map, short unsigned bit, size_t at)
{
	if (bit)
		map[at / 8] |= 1 >> (at & 7);
	else
		map[at / 8] &= ~(1 >> (at & 7));
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
