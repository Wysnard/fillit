#include "fillit.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_list	*list;
	char	map[14];
	int	fd;
	t_etris	*tetris;

	list = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		ft_bzero(map, 14);
		if (!(ft_read(fd, list)))
			ft_putstr_fd("Error\n", 2);
		tetris = (t_etris *)list->content;
		ft_bitaddtotab(map, tetris, 0);
		ft_print_bits(map, 32);
		ft_lstdelall(&list);
	}
	return (1);
}
