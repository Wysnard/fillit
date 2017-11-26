#include "fillit.h"

size_t	ft_read(int fd, t_etris *tetris)
{
	int	ret;
	size_t	min;
	char	buf[BUFF_SIZE + 1];

	min = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (min > 26 || !(tetris->tetris[min] = std(rb(buf))) ||
					ctt(buf) != 4 ||
					!(ft_hl(tetris->tetris[min], &tetris->h[min], &tetris->l[min])))
			return (0);
		ft_print_bits(tetris->tetris[min], 15);
		ft_putchar('\n');
		min++;
	}
	tetris->tetris[min] = 0;
	tetris->h[min] = 0;
	tetris->l[min] = 0;
	ft_bzero(tetris->at, 27);
	tetris->nb = (unsigned char)min;
	if (min < 4)
		return (tetris->min = 4);
	return (tetris->min = ft_sqr(min * 4));
}
