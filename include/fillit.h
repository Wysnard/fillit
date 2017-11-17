#ifndef	FILLIT_H
#	define FILLIT_H
# define BUFF_SIZE 21
# define LENGTHMASK 0x8888
# define HEIGHTMASK 61440
# define FIRSTBIT 32768
# define FLLASTBIT 4096
#	include <sys/types.h>
#	include <sys/stat.h>
#	include <fcntl.h>
#	include "libft.h"

typedef	struct	s_etris
{
	unsigned	char	tetris[27];
	unsigned	char	max;
}							t_etris;

size_t	ft_read(int fd, t_etris *tetris);
unsigned short	ft_registerbits(char *buf);
unsigned	short	ft_standard(unsigned short c);
void	ft_printtetris(unsigned char c);
unsigned	char	ft_heightlength(unsigned short c);
void	ft_bitaddtotab(unsigned short *map, unsigned short int tetrimino, size_t at);
void	ft_placetetris(unsigned short *map, unsigned short tetrimino, size_t at, size_t max);
unsigned char	ft_bitsrotate(unsigned short c);
int		ft_solve(t_list *list, unsigned short *map, size_t max);
unsigned	short	ft_bitsrerotate(unsigned char c);
void	ft_tabprintbit(unsigned short *map, size_t max);
int	ft_fit_in(unsigned short *map, unsigned short tetrimino, size_t at, size_t max);
unsigned	char	ft_putinchar(unsigned short c);
unsigned char	ft_getbitat(unsigned char byte, unsigned char at);
void ft_setbitat(unsigned char *byte, unsigned char at, unsigned char val);

#endif
