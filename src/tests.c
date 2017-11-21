/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:33:00 by schmurz           #+#    #+#             */
/*   Updated: 2017/11/21 12:01:47 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

unsigned	char	ft_putinchar(unsigned short c, unsigned char *hl)
{
	unsigned	char	bits;

	bits = 0;
	*hl = ft_heightlength(c);
	if ((*hl >> 4) == 4)
		bits = (5 << 5) + 0b1111;
	else if ((*hl & 15) == 4)
		bits = (1 << 7) + 0b1111;
	else if ((*hl >> 4) == 3 || (*hl & 15) == 3)
	{
		if (!(bits = ft_formrect(*hl, c)))
			return (0);
	}
	else if ((*hl >> 4) == 2 && (*hl & 15) == 2)
		bits = (3 << 6) + 0b111100;
	return (bits);
}

int main()
{
  unsigned char t;
  t = ft_putinchar(0b1100010001000100);
  ft_print_bits(t,7);
  ft_putchar('\n');
  return 0;
}
