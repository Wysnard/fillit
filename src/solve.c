#include "fillit.h"
#include <stdio.h>

int	ft_fit_in(unsigned short *map, unsigned char tet, size_t at, size_t min)
{
	unsigned char	i;
	unsigned short	linemask;
	unsigned short	tetline;
	char	tet_h;
	char	tet_l;
	unsigned char keep_at;
	unsigned short tet_inline;

	i = 0;
	keep_at = at;
	tet_inline = ft_gettetinline(tet, &tet_h, &tet_l);
	if (((at + tet_l - 1) % 16) >= min || ((at / 16) + tet_h - 1) >= min)
		return (0);
	linemask = ft_getlinemask(tet_l);
	while (i < tet_h)
	{
		tetline = (tet_inline & linemask) >> (at & 15);
		if ((map[at / 16] ^ tetline) != (map[at / 16] | tetline))
			return (0);
		tet_inline <<= tet_l;
		i++;
		at += 16;
	}
	ft_placetetris(map, tet, keep_at);
	return(1);
}

int	ft_solve(t_etris *tetris, unsigned short *map, size_t min, unsigned char tetnum)
{
	size_t	i;
	unsigned	short	save[16];
	size_t	minimum;
	size_t	j;

	if (tetris->tetriminos[tetnum] == 0)
		return (1);
	i = 0;
	j = 1;
	minimum = min * 16;
	ft_uscpy(save, map, min);
	while (i < minimum)
	{
		if (ft_fit_in(map, tetris->tetriminos[tetnum], i, min))
		{
			if (ft_solve(tetris, map, min, tetnum + 1))
			{
				tetris->at[tetnum] = i;
				return (1);
			}
			else
				ft_uscpy(map, save, min);
		}
		if (i % 16 == min)
		{
			i = 16 * j;
			j++;
		}
		else if ((i - min) % 16 != 0 && i < minimum)
			i += 1;
	}
	return (0);
}
