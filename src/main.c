#include "fillit.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	unsigned	short	*map;
	int	fd;
	size_t	len;
	t_etris	tetris;
	size_t	i;
	char **resulttab;

	i = 0;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) < 0 || !(ft_read(fd, &tetris)))
			ft_putstr_fd("Error\n", 2);
		printf("MIN = %d\n", tetris.min);
		if (!(map = (unsigned short *)malloc(sizeof(unsigned short) * tetris.min)))
			return (0);
		ft_initmap(map, tetris.min);
		while ((ft_solve(&tetris, map, tetris.min, 0) == 0))
		{
			tetris.min++;
			ft_initmap(map, tetris.min);
		}
		ft_putstr("C'est gagnee!!!\n");
		printf("REMIN = %d\n", tetris.min);
		//int y = 0;
		// while (y <= 68)
		// {
		// 	printf("is0next pour %d : %d\n",y,ft_isbegdeadrange(map,y,tetris.min));
		// 	if (y % 16 >= tetris.min - 1)
		// 		y += (16 - tetris.min + 1);
		// 	else
		// 		y++;
		// }
		printf("dcs = %d\n", ft_getdcnum(map, tetris.min));
		printf("mapvalat 50 %d\n",ft_getmapvalat(map, 50));
		//printf("deadrange = %d\n", ft_isdeadrange(1, tetris.min, map));
		ft_print_map(map, tetris.min);
		if (!(resulttab = ft_initresulttab(tetris.min)))
			return (0);
		i = 0;
		len = ft_strlen((const char*)tetris.h);
		while (i < len)
		{
			ft_fillresulttab(resulttab, tetris.at[i], i, &tetris);
			i += 1;
		}
		i = 0;
		while (i < tetris.min)
		{
			ft_putstr(resulttab[i]);
			i++;
		}
		ft_putchar('\n');
		i = 0;
		while (i < len)
		{
			ft_putnbr(tetris.at[i]);
			ft_putchar('\n');
			i++;
		}
		free(map);
	}
	return (0);
}
