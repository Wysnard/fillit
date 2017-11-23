#include "fillit.h"

int	ft_deadcell(unsigned short *map, size_t at, unsigned char min)
{
	if (((at % 16) > 0) && map[at / 16] ^ (1 << ((at - 1) % 16)))
		return (0);
	if ((at / 16) > 0 && map[(at / 16) - 1] ^ (1 << (at & 15)))
		return (0);
	if ((at / 16) < min && map[(at / 16) + 1] ^ (1 << (at & 15)))
		return (0);
	if ((at % 16) < min && map[at / 16] ^ (1 << ((at & 15) + 1)))
		return (0);
	return (1);
}
