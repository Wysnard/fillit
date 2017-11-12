#include "fillit.h"
#include <stdio.h>

void	ft_printtetris(unsigned short c)
{
	int	i;

	i = 15;
	while (i >= 0)
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

t_etris	*ft_tetrimino(unsigned short int c)
{
	t_etris	*tetris;

	if (!(tetris = malloc(sizeof(*tetris))))
		return (NULL);
	tetris->tetrimino = c;
	ft_heightlength(c, &tetris->height, &tetris->length);
	printf("height = %d\n", tetris->height);
	printf("length = %d\n", tetris->length);
	return (tetris);
}
