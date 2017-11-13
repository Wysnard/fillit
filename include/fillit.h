#ifndef	FILLIT_H
#	define FILLIT_H
# define BUFF_SIZE 21
# define LENGTHMASK 34952
# define HEIGHTMASK 61440
# define FIRSTBIT 32768
# define FLLASTBIT 4096
#	include <sys/types.h>
#	include <sys/stat.h>
#	include <fcntl.h>
#	include "libft.h"

typedef	struct	s_etris
{
	unsigned char		tetrimino;
	unsigned char					hl;
}							t_etris;

size_t	ft_read(int fd, t_list **list);
unsigned short	ft_registerbits(char *buf);
t_etris	*ft_tetrimino(unsigned short int c);
unsigned	short	ft_standard(unsigned short c);
void		ft_printtetris(unsigned short c);
void	ft_heightlength(unsigned short c, unsigned char *hl);
void	ft_bitaddtotab(char *map, short unsigned bit, size_t at);
void	ft_placetetris(char *map, unsigned short int tetrimino, size_t at);
void		ft_lstprtbits(t_list *list);
unsigned char	ft_bitsrotate(unsigned short c);
int		ft_solve(t_list *list, char *map, size_t max);
void		ft_tabprintbit(char *map, size_t base);

#endif
