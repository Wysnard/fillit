#include "fillit.h"

size_t	ft_read(int fd, t_etris *tetris)
{
	int	ret;
	size_t	min;
	unsigned short	c;
	char	buf[BUFF_SIZE + 1];

	c = 0;
	min = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (min > 26 || !(c = ft_standard(ft_registerbits(buf))) || ft_cttetris(buf) != 4 ||
					!(tetris->tetriminos[min] = ft_putinchar(c)))
			return (0);
		// ft_print_bits(tetris->tetriminos[min], 7);
		// ft_putchar('\n');
		min++;
	}
	(tetris->tetriminos)[min] = 0;
	ft_bzero(tetris->at, 27);
	if (min < 4)
		return (tetris->min = 4);
	return (tetris->min = ft_sqr(min * 4));
}
