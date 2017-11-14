#include "fillit.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*list;
	char	map[14];
	int	fd;
	t_etris	*tetris;
	size_t	max;

	list = NULL;
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
		ft_placetetris(map, tetris->tetrimino, 0, max);
		//ft_bitaddtotab(map, 1, 20);
		//ft_bitaddtotab(map, 1, 2);
		//ft_bitaddtotab(map, 1, 10);
		ft_print_bits(map[0], 8);
		ft_putchar('\n');
		ft_print_bits(map[1], 8);
		ft_putchar('\n');
		ft_print_bits(map[2], 8);
		//ft_tabprintbit(map, max);
		//ft_lstdelall(&list);
	}
	return (1);
}
