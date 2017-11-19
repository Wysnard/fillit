#include "fillit.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*list;
	unsigned	short	*map;
	int	fd;
	t_etris	tetris;
	size_t	i;

	list = NULL;
	i = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!(ft_read(fd, &tetris)))
			ft_putstr_fd("Error\n", 2);
		printf("MIN = %d\n", tetris.min);
		if (!(map = (unsigned short *)malloc(sizeof(unsigned short) * tetris.min)))
			return (0);
		ft_initmap(&map, tetris.min);
		while ((ft_solve(&tetris, map, tetris.min, 0) == 0))
		{
			tetris.min++;
			ft_initmap(&map, tetris.min);
		}
		ft_putstr("C'est gagnee!!!\n");
		ft_putstr("la map une fois gagnee\n");
		i = 0;
		while (i < tetris.min)
		{
			ft_printnbits(map[i], 15, 15);
			ft_putchar('\n');
			i += 1;
		}
		free(map);
	}
	return (1);
}
