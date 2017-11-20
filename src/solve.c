#include "fillit.h"
#include <stdio.h>

int	ft_compare(unsigned short *map, size_t at, t_etris tetris, unsigned char tetnum)
{
	unsigned char	i;
	unsigned short	linemask;
	unsigned short	tetline;

	i = 0;
	linemask = ft_getlinemask(tetris.l[tetnum]);
	while (i < tetris.h[tetnum])
	{
		tetline = (0xF000 & (tetris.tetris[tetnum] << (4 * i))) >> (at & 15);
		if ((map[at / 16] ^ tetline) != (map[at / 16] | tetline))
			return (0);
		i++;
		at += 16;
	}
	return (1);
}

int	ft_fit_in(unsigned short *map, size_t at, t_etris tetris, unsigned char tetnum)
{
	if (!ft_compare(map, at, tetris, tetnum))
		return (0);
	ft_placetetris(map, at, tetris, tetnum);
	return(1);
}

int	ft_solve(t_etris *tetris, unsigned short *map, size_t min, unsigned char tetnum)
{
	size_t	i;
	unsigned	short	save[16];
	size_t	j;
	unsigned	short	mask;

	if (tetris->tetris[tetnum] == 0)
		return (1);
	i = 0;
	j = 1;
	ft_uscpy(save, map, min);
	mask = ft_createmask(min);
	while (((i / 16) + tetris->h[tetnum] - 1) < min)
	{
		if (((i + tetris->l[tetnum] - 1) % 16) >= min || !(mask ^ map[i / 16]))
			i = 16 * j++;
		if (ft_fit_in(map, i, *tetris, tetnum))
		{
			if (ft_solve(tetris, map, min, tetnum + 1))
			{
				tetris->at[tetnum] = i;
				return (1);
			}
			else
				ft_uscpy(map, save, min);
		}
		if ((i - min) % 16 != 0)
			i += 1;
	}
	return (0);
}
