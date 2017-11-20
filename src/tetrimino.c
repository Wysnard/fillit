#include "fillit.h"
#include "libft.h"
#include <stdio.h>

void	ft_placetetris(unsigned short *map, unsigned char tet, unsigned char at)
{
	char	hl[2];
	unsigned short	tet_inline;
	unsigned short	linemask;
	char	i;

	i = 0;
	tet_inline = ft_gettetinline(tet, &hl[0], &hl[1]);
	linemask = ft_getlinemask(hl[1]);
	while (i < hl[0])
	{
		map[at / 16] |= (tet_inline & linemask) >> (at & 15);
		tet_inline <<= hl[1];
		i++;
		at += 16;
	}
}
