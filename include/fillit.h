#ifndef	FILLIT_H
#	define FILLIT_H
# define BUFF_SIZE 21
#	include <sys/types.h>
#	include <sys/stat.h>
#	include <fcntl.h>
#	include "libft.h"

typedef	struct	s_etris
{
	unsigned short	tetrimino;
	char	height;
	char	length;
}							t_etris;

int	ft_read(int fd, t_list *list);
unsigned short	ft_registerbits(char *buf);
t_etris	*ft_tetrimino(unsigned short int c);
unsigned	short	ft_standard(unsigned short c);
void	ft_printtetris(unsigned short c);
void	ft_heightlength(unsigned short c, char *height, char *length);
void	ft_bitaddtotab(char *map, t_etris *tetris);

#endif
