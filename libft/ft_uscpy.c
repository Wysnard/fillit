#include "libft.h"

unsigned short	*ft_uscpy(unsigned short *dest, unsigned short *src, size_t len)
{
	unsigned short	*tmp;

	tmp = dest;
	while ((*tmp++ = *src++) && len)
		len--;
	return (dest);
}
