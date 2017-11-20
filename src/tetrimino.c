#include "fillit.h"
#include "libft.h"
#include <stdio.h>

void	ft_placetetris(unsigned short *map, unsigned char at, t_etris tetris, unsigned char tetnum)
{
	unsigned	short	tet;

	tet = tetris.tetris[tetnum];
	while (tetris.h[tetnum])
	{
		map[at / 16] |= (tet & 0xF000) >> (at % 16);
		tet = tet << 4;
		tetris.h[tetnum] -= 1;
		at += 16;
	}
}
