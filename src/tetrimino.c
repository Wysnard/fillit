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

void	ft_placetetris(unsigned short *map, unsigned char tet, unsigned char at, unsigned char hl)
{
	unsigned short	tet_inline;
	unsigned short	linemask;
	char	i;

	i = 0;
	tet_inline = ft_gettetinline(tet);
	linemask = ft_getlinemask(LB(hl));
	while (i < HB(hl))
	{
		map[at / 16] |= (tet_inline & linemask) >> (at & 15);
		tet_inline <<= LB(hl);
		i++;
		at += 16;
	}
}
