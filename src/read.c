#include "fillit.h"

size_t	ft_read(int fd, t_list **list)
{
	int	ret;
	size_t	max;
	unsigned short	c;
	char	buf[BUFF_SIZE + 1];
	t_etris	*tetris;

	c = 0;
	max = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (!(c = ft_standard(ft_registerbits(buf))) ||
			!(tetris = ft_tetrimino(c))) /*||
			(((tetris->hl & 15) + (tetris->hl >> 4) != 5 && tetris->hl != 51)))*/
			return (0);
		ft_lstpushadd(list, ft_lstnew(tetris, sizeof(t_etris)));
		max += 1;
		/*ft_print_bits(c, 16);
		ft_putchar('\n');
		ft_printtetris(c);
		ft_putchar('\n');*/
	}
	return (max);
}
