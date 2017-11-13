#include "fillit.h"

void	ft_tabprintbit(char *map, size_t base)
{
	size_t	i;

	i = 0;
	while (*map)
	{
		while (i < 8 && i < base)
		{
			ft_putchar((((*map) >> (base - i)) & 1) ? '1' : '0');
			i += 1;
		}
		if (i == base)
		{
			i = 0;
			ft_putchar('\n');
		}
		map += 1;
	}
}
