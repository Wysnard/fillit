#include "libft.h"

unsigned short	*ft_uscpy(unsigned short *dest, unsigned short *src, size_t len)
{
	while (len)
	{
		*dest++ = *src++;
		len -= 1;
	}
	return (dest);
}
