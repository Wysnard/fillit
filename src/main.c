#include "fillit.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*list;
	unsigned	short	*map;
	int	fd;
	size_t	len;
	t_etris	tetris;
	size_t	i;
	char **resulttab;

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
		printf("REMIN = %d\n", tetris.min);
		i = 0;
		while (i < tetris.min)
		{
			ft_printnbits(map[i], 15, 15);
			ft_putchar('\n');
			i += 1;
		}
		if (!(resulttab = ft_initresulttab(tetris.min)))
			return (0);
		i = 0;
		len = ft_strlen((const char*)tetris.tetriminos);
		while (i < len)
		{
			ft_fillresulttab(resulttab, tetris.tetriminos[i], tetris.at[i], i);
			i += 1;
		}
		i = 0;
		while (i < tetris.min)
		{
			ft_putstr(resulttab[i]);
			i++;
		}
		free(map);
	}
	return (1);
}
