#include "fillit.h"

void	ft_bitaddtotab(unsigned short *map, unsigned short int tetrimino, size_t at)
{
	if (tetrimino)
		map[at / 16] |= FIRSTBIT >> (at & 15);
	else
		map[at / 16] &= ~(FIRSTBIT >> (at & 15));
}

void	ft_placetetris(unsigned short *map, unsigned short tetrimino, size_t at, size_t max)
{
	size_t	i;

	i = 0;
	//tetrimino <<= 8;
	(void)max;
	while (i < 16)
	{
		if ((tetrimino << i) & FIRSTBIT)
			ft_bitaddtotab(map, 1, at);
		i += 1;
		if (!(i & 3))
			at += 13;
		else
			at += 1;
	}
	//map[at / 8] |= tetrimino & 0xF000;
	//at += max;
	//map[at / 8] |= tetrimino & 0x0F00;
}

unsigned short	ft_registerbits(char *buf)
{
	unsigned short	c;
	char		i;

	c = 0;
	i = 15;
	while (i >= 0)
	{
		if (*buf != '.' && *buf != '#' && *buf != '\n')
			return (0);
		if (*buf == '#')
			c = c | (1 << i);
		if (*buf != '\n')
			i -= 1;
		buf += 1;
	}
	return (c);
}

void ft_setbitat(unsigned char *byte, unsigned char at, unsigned char val) {
	if (val == 0 && ft_getbitat(*byte, at) == 1)
			*byte = *byte - ft_power(2,at);
	else if(val == 1 && ft_getbitat(*byte, at) == 0)
				*byte = *byte + ft_power(2,at);
}

unsigned char	ft_getbitatchar(unsigned char byte, unsigned char at)
{
	char	ret;
	ret = ((byte >> at) & 1);
	return (ret);
}

unsigned char	ft_getbitat(unsigned short byte, unsigned short at)
{
	char	ret;
	ret = ((byte >> at) & 1);
	return (ret);
}
