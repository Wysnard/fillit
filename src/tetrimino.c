#include "fillit.h"
#include <stdio.h>

void	ft_printtetris(unsigned char c)
{
	int	i;

	i = 8;
	while (i > 0)
	{
		if (c & (1 << i))
			ft_putchar('#');
		else
			ft_putchar('.');
		if (i % 4 == 0)
			ft_putchar('\n');
		i -= 1;
	}
}
