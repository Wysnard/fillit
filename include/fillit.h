#ifndef	FILLIT_H
#	define FILLIT_H
# define BUFF_SIZE 21
# define LENGTHMASK 0x8888
# define HEIGHTMASK 61440
# define FIRSTBIT 32768
# define FLLASTBIT 4096
# define TETSQR 0xF000
# define TETDWB 0xF000
# define TETUPB 0xF000
# define HB(byte) (byte >> 4)
# define LB(byte) (byte & 15)
#	include <sys/types.h>
#	include <sys/stat.h>
#	include <fcntl.h>
#	include "libft.h"

typedef	struct	s_etris
{
	unsigned	char	tetriminos[27];
	unsigned	char	min;
	unsigned	char	at[27];
	unsigned	char 	hl[27];
}							t_etris;

size_t	ft_read(int fd, t_etris *tetris);
unsigned short	ft_registerbits(char *buf);
unsigned	short	ft_standard(unsigned short c);
unsigned	char	ft_formrect(unsigned char hl, unsigned short tetris);
void	ft_printtetris(unsigned char c);
unsigned	char	ft_heightlength(unsigned short c);
void	ft_bitaddtotab(unsigned short *map, unsigned short int tetrimino, size_t at);
unsigned char	ft_bitsrotate(unsigned short c);
int		ft_solve(t_etris *tetris, unsigned short *map, size_t min, unsigned char tetnum);
unsigned	short	ft_bitsrerotate(unsigned char c);
void	ft_tabprintbit(unsigned short *map, size_t max);
int	ft_fit_in(unsigned short *map, unsigned char tet, size_t at, size_t min);
unsigned	char	ft_putinchar(unsigned short c, unsigned char *hl);
unsigned char	ft_getbitatchar(unsigned char byte, unsigned char at);
void ft_setbitat(unsigned short *byte, unsigned char at, unsigned char val);
unsigned char	ft_getbitat(unsigned short byte, unsigned short at);
int	ft_cttetris(char *buf);
void	ft_placetetris(unsigned short *map, unsigned char tet, unsigned char at);
int	ft_isdwrtet(unsigned char tet);
int	ft_isuprtet(unsigned char tet);
int	ft_issqrtet(unsigned char tet);
int ft_isdwbtet(unsigned char tet);
int ft_isupbtet(unsigned char tet);
int	ft_hlassign(char *h, char *l, char val_h, char val_l);
unsigned short ft_getlinemask(char l);
void	ft_initmap(unsigned short **map, size_t max);
unsigned short	ft_gettetinline(unsigned char tet, char *h, char *l);
void	ft_fillresulttab(char **tab, unsigned char tet, unsigned char at, unsigned char tetnum);
char	**ft_initresulttab(unsigned char min);
void	ft_print_map(unsigned short *map, unsigned char min);

#endif
