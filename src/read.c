#include "fillit.h"

size_t	ft_read(int fd, t_etris *tetris)
{
	int	ret;
	size_t	max;
	unsigned short	c;
	char	buf[BUFF_SIZE + 1];

	c = 0;
	max = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (max > 26 || !(c = ft_standard(ft_registerbits(buf))) || ft_cttetris(buf) != 4 ||
					!(tetris->tetrimino[max] = ft_putinchar(c)))
			return (0);
		//tetris->tetrimino[max] = ft_putinchar(c);
		ft_print_bits(tetris->tetrimino[max], 7);
		ft_putchar('\n');
		max++;
		//ft_lstpushadd(list, ft_lstnew(tetris, sizeof(t_etris)));
	}
	if (max < 4)
		return (4);
	return (ft_sqr(max * 4));
}
