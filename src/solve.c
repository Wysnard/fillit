#include "fillit.h"
#include <stdio.h>

int	ft_compare(unsigned short *map, unsigned char tet, size_t at)
{
	char	hl[2];
	unsigned short tet_inline;
	unsigned short	linemask;
	unsigned short	tetline;
	unsigned char	i;

	i = 0;
	tet_inline = ft_gettetinline(tet, &hl[0], &hl[1]);
	linemask = ft_getlinemask(hl[1]);
	while (i < hl[0])
	{
		tetline = (tet_inline & linemask) >> (at & 15);
		if ((map[at / 16] ^ tetline) != (map[at / 16] | tetline))
			return (0);
		tet_inline <<= hl[1];
		i++;
		at += 16;
	}
	return (1);
}

int	ft_fit_in(unsigned short *map, unsigned char tet, size_t at)
{
	if (!(ft_compare(map, tet, at)))
		return (0);
	ft_placetetris(map, tet, at);
	return(1);
}

int	ft_solve(t_etris *tetris, unsigned short *map, size_t min, unsigned char tetnum)
{
	size_t	i;
	unsigned	short	save[16];
	size_t	j;
	unsigned	short	mask;

	if (tetris->tetriminos[tetnum] == 0)
		return (1);
	i = 0;
	j = 1;
	ft_uscpy(save, map, min);
	mask = ft_createmask(min);
	while (((i / 16) + tetris->h[tetnum] - 1) < min)
	{
		if (((i + tetris->l[tetnum] - 1) % 16) >= min || !(mask ^ map[i / 16]))
			i = 16 * j++;
		if (ft_fit_in(map, tetris->tetriminos[tetnum], i))
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
