#include "fillit.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*list;
	unsigned	short	map[11];
	int	fd;
	t_etris	*tetris;
	size_t	max;
	size_t	i;
	unsigned	short	ex[] = {3, 4, 5};
	unsigned	short	st[4];

	ft_uscpy(st, ex, 3);
	ft_putstr("TEST = \n");
	ft_putnbr(st[0]);
	ft_putchar('\n');
	ft_putnbr(st[1]);
	ft_putchar('\n');
	list = NULL;
	i = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		ft_bzero(map, 14);
		if (!(max = ft_read(fd, &list)))
			ft_putstr_fd("Error\n", 2);
		if (!list)
			return (0);
		printf("MAX = %lu\n", max);
		ft_lstiter(list, &ft_lstprtbits);
		//ft_solve(list, map, max);
		tetris = (t_etris *)list->content;
		//ft_print_bits(198, 8);
		//ft_placetetris(map, ft_bitsrerotate(tetris->tetrimino), 0, max);
		//tetris = (t_etris *)list->next->content;
		//ft_fit_in(map, ft_bitsrerotate(tetris->tetrimino), 2, max);
		//ft_bitaddtotab(map, 1, 16);
		//ft_bitaddtotab(map, 1, 17);
		//ft_bitaddtotab(map, 1, 10);
		//ft_print_bits(ft_bitsrerotate(tetris->tetrimino), 15);
		//ft_solve(list, map, max);
		while (i < max)
		{
			ft_printnbits(map[i], 15, max);
			ft_putchar('\n');
			i += 1;
		}
		ft_putchar('\n');
		ft_tabprintbit(map, max);
		/*ft_print_bits(map[0], 8);
		ft_putchar('\n');
		ft_print_bits(map[1], 8);
		ft_putchar('\n');
		ft_print_bits(map[2], 8);*/
		//ft_tabprintbit(map, max);
		//ft_lstdelall(&list);
	}
	return (1);
}
