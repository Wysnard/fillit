#include "fillit.h"
#include <stdio.h>

int	ft_fit_in(unsigned short *map, unsigned char tet, unsigned char hl, size_t at)
{
	unsigned char	i;
	unsigned short	linemask;
	unsigned short	tetline;
	unsigned char keep_at;
	unsigned short tet_inline;

	i = 0;
	keep_at = at;
	tet_inline = ft_gettetinline(tet);
	linemask = ft_getlinemask(LB(hl));
	while (i < HB(hl))
	{
		tetline = (tet_inline & linemask) >> (at & 15);
		if ((map[at / 16] ^ tetline) != (map[at / 16] | tetline))
			return (0);
		tet_inline <<= LB(hl);
		i++;
		at += 16;
	}
	ft_placetetris(map, tet, keep_at, hl);
	return(1);
}

int	ft_solve(t_etris *tetris, unsigned short *map, size_t min, unsigned char tetnum)
{
	size_t	i;
	unsigned	short	save[16];
	size_t	j;

	if (tetris->tetriminos[tetnum] == 0)
		return (1);
	i = 0;
	j = 1;
	ft_uscpy(save, map, min);
	while (((i / 16) + HB(tetris->hl[tetnum]) - 1) < min)
	{
		if (((i + LB(tetris->hl[tetnum]) - 1) % 16) >= min)
			i = 16 * (j++);
		if (ft_fit_in(map, tetris->tetriminos[tetnum], tetris->hl[tetnum], i))
		{
			tetris->at[tetnum] = i;
			if (ft_solve(tetris, map, min, tetnum + 1))
				return (1);
			else
				ft_uscpy(map, save, min);
		}
		if ((i - min) % 16 != 0)
			i += 1;
	}
	return (0);
}
