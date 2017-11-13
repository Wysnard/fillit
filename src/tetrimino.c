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

void	ft_lstprtbits(t_list *list)
{
	t_etris	*tetris;

	tetris = (t_etris *)list->content;
	//ft_print_bits((tetris->hl << 4) >> 4, 4);
	//ft_print_bits(tetris->hl >> 4, 4);
	printf("height = %d\n", tetris->hl >> 4);
	printf("length = %d\n", tetris->hl & 15);
	ft_print_bits(tetris->tetrimino, 16);
	ft_putchar('\n');
	ft_printtetris(tetris->tetrimino);
	ft_putchar('\n');
}

t_etris	*ft_tetrimino(unsigned short int c)
{
	t_etris	*tetris;

	if (!(tetris = malloc(sizeof(*tetris))) || !c)
		return (NULL);
	tetris->tetrimino = (c >> 4);
	ft_heightlength(c, &tetris->hl);
	return (tetris);
}
