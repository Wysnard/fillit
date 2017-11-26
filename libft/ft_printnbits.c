/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:20:55 by dsaadia           #+#    #+#             */
/*   Updated: 2017/11/26 17:21:16 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printnbits(unsigned long long int octet, size_t size, size_t len)
{
	size_t					i;
	unsigned long long int	oct;

	if (size == 0)
		return ;
	i = 1;
	while (size)
	{
		i <<= 1;
		size -= 1;
	}
	oct = octet;
	while (i && len--)
	{
		ft_putchar((oct & i) ? '1' : '0');
		i >>= 1;
	}
}
