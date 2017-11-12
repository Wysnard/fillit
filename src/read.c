#include "fillit.h"

int	ft_read(int fd, t_list *list)
{
	int	ret;
	unsigned short	c;
	char	buf[BUFF_SIZE + 1];
	t_etris	*tetris;

	list = NULL;
	c = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (!(c = ft_standard(ft_registerbits(buf))))
			return (0);
		tetris = ft_tetrimino(c);
		if (tetris->height + tetris->length != 5 &&
			!(tetris->height == 2 && tetris->length == 2))
			return (0);
		ft_lstpushadd(&list, ft_lstnew(tetris, sizeof(t_etris)));
		ft_print_bits(c, 16);
		ft_putchar('\n');
		ft_printtetris(c);
		ft_putchar('\n');
	}
	return (1);
}
