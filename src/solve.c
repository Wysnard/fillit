#include "fillit.h"

int	ft_fit_in(unsigned short *map, unsigned short tetrimino, size_t at, size_t max)
{
	size_t	i;
	size_t	pos;

	i = 0;
	pos = at;
	while (i < 16)
	{
		if ((tetrimino << i) & FIRSTBIT && map[pos / 8] & 128)
			return (0);
		i += 1;
		if (!(i & 3))
			pos += max;
		else
			pos += 1;
	}
	ft_placetetris(map, tetrimino, at, max);
	return(1);
}

/*int	ft_solve(t_list *list, unsigned short *map, size_t max)
{
	size_t	i;
	t_etris	*tetris;
	char	save[14];
	size_t	maximum;

	if (!list)
		return (1);
	i = 0;
	maximum = max * 4;
	ft_strcpy(save, map);
	tetris = (t_etris *)list->content;
	while (i < maximum)
	{
		if (ft_fit_in(map, tetris->tetrimino, i, max))
		{
			if (ft_solve(list->next, map, max))
				return (1);
			else
			{
				ft_strcpy(map, save);
			}
		}
		i += 1;
	}
	return (0);
}*/
