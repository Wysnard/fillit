#include "fillit.h"

size_t	ft_readtabbit(unsigned short *map, size_t at)
{
	return ((map[at / 16] & (1 << (at & 15))) ? 1 : 0);
}

void	ft_tabprintbit(unsigned short *map, size_t max)
{
	size_t	at;

	at = 0;
	(void)max;
	while (at < 104)
	{
		ft_putnbr(ft_readtabbit(map, at));
		at += 1;
	}
}
