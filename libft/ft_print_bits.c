/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:05:05 by vlay              #+#    #+#             */
/*   Updated: 2017/11/10 16:05:23 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bits(unsigned int octet, int size)
{
	int		i;
	char	bits[size + 1];

	i = 0;
	while (i < size)
	{
		bits[i] = ((octet >> i) & 1) ? '1' : '0';
		i++;
	}
	bits[size] = '\0';
	ft_strrev(bits);
	ft_putstr(bits);
}
