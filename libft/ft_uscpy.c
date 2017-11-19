#include "libft.h"

unsigned short	*ft_uscpy(unsigned short *dest, unsigned short *src, size_t len)
{
	size_t	i;

	i = 0;
	while (len)
	{
		dest[i] = src[i];
		i++;
		len--;
	}
	return (dest);
}
