#include "fillit.h"
#include <stdio.h>

int	ft_fit_in(unsigned short *map, unsigned char tet, size_t at, size_t min)
{
	unsigned char	i;
	unsigned short	linemask;
	unsigned short	tetline;
	char	tet_h;
	char	tet_l;
	unsigned char keep_at;
	unsigned short tet_inline;

	i = 0;
	keep_at = at;
	// ft_putstr("\n************JE SUIS FIT IN*************\n \n");
	tet_inline = ft_gettetinline(tet, &tet_h, &tet_l);
	if (((at + tet_l) % 16) > min || ((at / 16) + tet_h) > min)
	{
		// ft_putstr("\n************JE SUIS VIRE*************\n \n");
		return (0);
	}
	linemask = ft_getlinemask(tet_l);
	// ft_putstr("tet en bits: ");
	// ft_print_bits(tet, 7);
	// ft_putstr("\n \n");
	// ft_putstr("tet_inline en bits: ");
	// ft_print_bits(tet_inline, 15);
	// ft_putstr("\n \n");
	while (i < tet_h)
	{
		// ft_putstr("at:");
		// ft_putnbr(at);
		// ft_putstr("\n \n");
		// ft_putstr("at & 15 :");
		// ft_putnbr(at & 15);
		// ft_putstr("\n \n");
		tetline = (tet_inline & linemask) >> (at & 15);
		// ft_putstr("tetline en bits: ");
		// ft_print_bits(tetline, 15);
		// ft_putstr("\n \n");
		// ft_putstr("mapat 16 en bits: ");
		// ft_print_bits(map[at / 16], 15);
		// ft_putstr("\n \n");
		if ((map[at / 16] ^ tetline) != (map[at / 16] | tetline))
		{
			// ft_putstr("le xor or est  pas bon on se casse !\n");
			// ft_putstr("\n \n");
			return (0);
		}
		else
		{
			// ft_putstr("le xor or est bon !\n");
			// ft_putstr("\n \n");
		}
		tet_inline <<= tet_l;
		i++;
		at += 16;
	}
	ft_placetetris(map, tet, keep_at);
	// i = 0;
	// while (i < min)
	// {
	// 	ft_printnbits(map[i], 15, 15);
	// 	ft_putchar('\n');
	// 	i += 1;
	// }
	// ft_putstr("\n*************************\n \n");
	return(1);
}

int	ft_solve(t_etris *tetris, unsigned short *map, size_t min, unsigned char tetnum)
{
	size_t	i;
	unsigned	short	save[16];
	size_t	minimum;

	if (tetris->tetriminos[tetnum] == 0)
		return (1);
	i = 0;
	minimum = min * 16;
	ft_uscpy(save, map, min);
	while (i < minimum)
	{
		// ft_putstr("fit_in pour le tetrimino ");
		// ft_putnbr(tetnum);
		// ft_putstr("\net pour le i : ");
		// ft_putnbr(i);
		// ft_putstr("\n*************************\n \n");
		if (ft_fit_in(map, tetris->tetriminos[tetnum], i, min))
		{
			if (ft_solve(tetris, map, min, tetnum + 1))
				return (1);
			else
				ft_uscpy(map, save, min);
		}
		if (i % 16 == min)
			i += (16 - min);
		else
			i += 1;
	}
	return (0);
}
