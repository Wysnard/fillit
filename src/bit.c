#include "fillit.h"

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

void ft_setbitat(unsigned short *byte, unsigned char at, unsigned char val) {
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

unsigned char	ft_getmapvallc(unsigned short *map, unsigned char lin, unsigned char col)
{
	return (ft_getbitat(map[lin], col));
}

unsigned char ft_getmapvalat(unsigned short *map, unsigned char where)
{
	return (ft_getmapvallc(map, where / 16, where % 16));
}
// 
// unsigned char ft_isnotsurrounded(unsigned short *map, unsigned char where)
// {
// 	if (where % 16 > 0 && )
// }
