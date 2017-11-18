#include "fillit.h"
#include "libft.h"
#include <stdio.h>

void	ft_bitaddtotab(unsigned short *map, unsigned short int tetrimino, size_t at)
{
	if (tetrimino)
		map[at / 16] |= FIRSTBIT >> (at & 15);
	else
		map[at / 16] &= ~(FIRSTBIT >> (at & 15));
}

int	ft_mapmove(unsigned short *map, unsigned short tetrimino, size_t at)
{
	size_t	i;
	size_t	rot;

	i = 0;
	rot = 0;
	(void)at;
	while (i < 4)
	{
		if (at % 2 < 8)
		{
			map[at / 16] = ft_bitrotr(map[at / 16], at & 15);
			rot = 1;
		}
		else
		{
			map[at / 16] = ft_bitrotl(map[at / 16], at & 15);
			rot = 0;
		}
		map[i] |= tetrimino & 0xE000;
		tetrimino <<= 3;
		i++;
		at += 16;
	}
	return (rot);
}

void	ft_mapremove(unsigned short *map, size_t at, int rot)
{
	size_t	i;

	i = 0;
	if (rot)
	{
		map[at / 16] = ft_bitrotl(map[at / 16], at & 15);
		rot = 1;
	}
	else
	{
		map[at / 16] = ft_bitrotr(map[at / 16], at & 15);
		rot = 0;
	}
}

void	ft_placetetris(unsigned short *map, unsigned char tet, char at)
{
	unsigned short	tet_inline;
	unsigned short	linemask;
	char	tet_h;
	char	tet_l;
	char	i;

	i = 0;
	tet_inline = (unsigned short)tet;
	if (ft_issqrtet(tet) && ft_hlassign(&tet_h, &tet_l, 2, 2))
		tet_inline = TETSQR;
	else if (ft_isdwbtet(tet) && ft_hlassign(&tet_h, &tet_l, 1, 4))
		tet_inline = TETDWB;
	else if (ft_isupbtet(tet) && ft_hlassign(&tet_h, &tet_l, 4, 1))
		tet_inline = TETUPB;
	else if (ft_isdwrtet(tet) && ft_hlassign(&tet_h, &tet_l, 2, 3))
		tet_inline <<= 10;
	else if (ft_isuprtet(tet) && ft_hlassign(&tet_h, &tet_l, 3, 2))
		tet_inline <<= 10;
	linemask = ft_getlinemask(tet_l);
	while (i < tet_h)
	{
		map[at / 16] |= (tet_inline & linemask) >> (at & 15);
		tet_inline <<= tet_l;
		i++;
		at += 16;
	}
	//ft_mapmove(map, tetrimino, at);
}
