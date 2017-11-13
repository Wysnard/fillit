#include "fillit.h"
#include <stdio.h>

void	ft_printtetris(unsigned char c)
{
	int	i;

	i = 7;
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

void	ft_lstprtbits(t_list *list)
{
	t_etris	*tetris;

	tetris = (t_etris *)list->content;
	//ft_print_bits((tetris->hl << 4) >> 4, 4);
	//ft_print_bits(tetris->hl >> 4, 4);
	printf("height = %d\n", tetris->hl >> 4);
	printf("length = %d\n", tetris->hl & 15);
	ft_print_bits(tetris->tetrimino, 8);
	ft_putchar('\n');
	ft_printtetris(tetris->tetrimino);
	ft_putchar('\n');
}

t_etris	*ft_tetrimino(unsigned short int c)
{
	t_etris	*tetris;

	if (!(tetris = malloc(sizeof(*tetris))) || !c)
		return (NULL);
	ft_heightlength(c, &tetris->hl);
	tetris->tetrimino = ft_bitsrotate(c);
	return (tetris);
}
