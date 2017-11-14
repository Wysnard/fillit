#include "fillit.h"

size_t	ft_readtabbit(char *map, size_t at)
{
	return ((map[at / 8] & (1 << (at & 7))) ? 1 : 0);
}

void	ft_tabprintbit(char *map, size_t max)
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
