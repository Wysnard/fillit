#include "fillit.h"
#include "libft.h"
#include <stdio.h>

void	ft_placetetris(unsigned short *map, unsigned char tet, unsigned char at)
{
	unsigned short	tet_inline;
	unsigned short	linemask;
	char	tet_h;
	char	tet_l;
	char	i;

	i = 0;
	tet_inline = ft_gettetinline(tet, &tet_h, &tet_l);
	linemask = ft_getlinemask(tet_l);
	while (i < tet_h)
	{
		map[at / 16] |= (tet_inline & linemask) >> (at & 15);
		tet_inline <<= tet_l;
		i++;
		at += 16;
	}
}
