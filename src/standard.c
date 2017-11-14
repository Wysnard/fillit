#include "fillit.h"

unsigned char	ft_bitsrotate(unsigned short c)
{
	unsigned char	rotate;

	rotate = 0;
	if (c == 34952)
		rotate = 241;
	else if (c == 19520)
		rotate = 233;
	else if (c == 17600)
		rotate = 227;
	else if (c == 35968)
		rotate = 79;
	else if (c == 35904)
		rotate = 109;
	else if (c == 19584)
		rotate = 199;
	else if (c == 51264)
		rotate = 143;
	else
		rotate = (c >> 8);
	return (rotate);
}

unsigned	short	ft_bitsrerotate(unsigned char c)
{
	unsigned	short	rotate;

	rotate = c;
	if (c == 241)
		rotate = 34952;
	else if (c == 233)
		rotate = 19520;
	else if (c == 227)
		rotate = 17600;
	else if (c == 79)
		rotate = 35968;
	else if (c == 109)
		rotate = 35904;
	else if (c == 199)
		rotate = 19584;
	else if (c == 143)
		rotate = 51264;
	else
		rotate <<= 8;
	return (rotate);
}

void	ft_heightlength(unsigned short c, unsigned char *hl)
{
	size_t	i;

	i = 0;
	while (i < 16)
	{
		if (HEIGHTMASK & (c << i))
			(*hl) += 1;
		i += 4;
	}
	*hl = (*hl) << 4;
	i = 0;
	while (i < 4)
	{
		if (LENGTHMASK & (c << i))
			(*hl) += 1;
		i += 1;
	}
}

unsigned	short	ft_standard(unsigned short c)
{
	if (c == 0)
		return (0);
	while (!(HEIGHTMASK & c))
		c = c << 4;
	while (!(LENGTHMASK & c))
		c = c << 1;
	return (c);
}
