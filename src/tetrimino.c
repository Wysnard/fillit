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

void	ft_placetetris(unsigned short *map, unsigned char tetris, size_t at)
{
	unsigned short	tetrimino;
	size_t	i;
	//size_t	code;
	//size_t	rot;

	i = 0;
	tetris <<= 2;
	tetrimino = tetris;
	tetrimino <<= 8;
	(void)at;
	/*if (!(tetris & 0x80))
	{
		if ((tetris <<= 1) & 0x80)
		{
			code = 2;
			tetris <<= 1;
		}
		else
		{
			code = 3;
			tetris <<= 1;
		}
	}*/
	while (i < 4)
	{
		map[at / 16] = (tetrimino & 0xE000) >> (at & 15);
		tetrimino <<= 3;
		i++;
		at += 16;
	}
	//ft_mapmove(map, tetrimino, at);
}
