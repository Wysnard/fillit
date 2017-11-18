#include "libft.h"

unsigned short ft_bitrotl(unsigned short value, int shift)
{
	if ((shift &= sizeof(value)*8 - 1) == 0)
		return (value);
	return (value << shift) | (value >> (sizeof(value)*8 - shift));
}

unsigned short ft_bitrotr(unsigned short value, int shift)
{
	if ((shift &= sizeof(value) * 8 - 1) == 0)
		return (value);
	return (value >> shift) | (value << (sizeof(value) * 8 - shift));
}
