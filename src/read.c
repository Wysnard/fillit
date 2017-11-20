#include "fillit.h"

size_t	ft_read(int fd, t_etris *tetris)
{
	int	ret;
	size_t	min;
	// unsigned short	c;
	char	buf[BUFF_SIZE + 1];

	// c = 0;
	min = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (min > 26 || !(tetris->tetris[min] = ft_standard(ft_registerbits(buf))) || ft_cttetris(buf) != 4 ||
					!(ft_hl(tetris->tetris[min], &tetris->h[min], &tetris->l[min])) ||
					!(tetris->tetriminos[min] = ft_putinchar(tetris->tetris[min])))
			return (0);
		ft_print_bits(tetris->tetris[min], 15);
		ft_putchar('\n');
		min++;
	}
	(tetris->tetriminos)[min] = 0;
	tetris->h[min] = 0;
	tetris->l[min] = 0;
	ft_bzero(tetris->at, 27);
	if (min < 4)
		return (tetris->min = 4);
	return (tetris->min = ft_sqr(min * 4));
}
