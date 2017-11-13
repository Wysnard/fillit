#include "fillit.h"

/*static int	ft_fit_in(char *map, t_etris *tetris, size_t i, size_t max)
{
	size_t	j;
	size_t	sqt;

	j = 0;
	sqt = max * max;
	while (i < sqt)
	{
		if ((tetris->tetrimino << j) & FIRSTBIT)
			if ((map[i / max] << (i % max)) & FIRSTBIT)
				return (0);
		i += 1;
		j += 1;
	}
	ft_placetetris(map, tetris->tetrimino, i, max);
	return (1);
}

int	ft_solve(t_list *list, char *map, size_t max)
{
	size_t	i;
	t_etris	*tetris;
	char	save[14];
	size_t	maximum;

	if (!list)
		return (1);
	maximum = max * max;
	i = 0;
	ft_strcpy(save, map);
	tetris = (t_etris *)list->content;
	while (i < maximum)
	{
		if (ft_fit_in(map, tetris, i, maximum))
		{
			if (ft_solve(list->next, map, maximum))
				return (1);
			else
				ft_strcpy(save, map);
		}
		i += 1;
	}
	return (0);
}*/
