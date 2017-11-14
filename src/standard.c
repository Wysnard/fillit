#include "fillit.h"

unsigned char	ft_bitsrotate(unsigned short c)
{
	unsigned char	rotate;

	rotate = 0;
	if (c == 0b1000100010001000)
		rotate = 0b11110001;
	else if (c == 0b100110001000000)
		rotate = 0b11101001;
	else if (c == 0b100010011000000)
		rotate = 0b11100011;
	else if (c == 0b1000110010000000)
		rotate = 0b1001111;
	else if (c == 0b1000110001000000)
		rotate = 0b1101101;
	else if (c == 0b100110010000000)
		rotate = 0b11000111;
	else
		rotate = (c >> 8);
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
