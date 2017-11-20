#include "fillit.h"
#include "libft.h"
#include <stdio.h>

void	ft_placetetris(unsigned short *map, unsigned char at, t_etris tetris, unsigned char tetnum)
{
	unsigned	short	tet;
	unsigned	short	tetline;

	tet = tetris.tetris[tetnum];
	while (tetris.h[tetnum])
	{
		tetline = (tet & 0xF000) >> (at % 16);
		map[at / 16] |= tetline;
		tet = tet << 4;
		tetris.h[tetnum] -= 1;
		at += 16;
	}
}
