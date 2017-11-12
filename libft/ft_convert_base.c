/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:50:07 by vlay              #+#    #+#             */
/*   Updated: 2017/11/10 16:01:44 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		nbr_to_int(char *nbr, char *base_from)
{
	int	len;
	int	i;
	int	nb;
	int	sign;

	nb = 0;
	sign = (*nbr == '-') ? -1 : 1;
	len = (sign == 1) ? ft_strlen(nbr) - 1 : ft_strlen(nbr) - 2;
	nbr += (*nbr == '-' || *nbr == '+') ? 1 : 0;
	while (*nbr)
	{
		i = 0;
		while (base_from[i])
		{
			if (*nbr == base_from[i])
			{
				nb = nb + (i * ft_power(ft_strlen(base_from), len));
				len--;
				break ;
			}
			i++;
		}
		nbr++;
	}
	return (sign * nb);
}

static	char	*int_to_base(int nbr, char *base_to)
{
	char	*base;
	int		ct;
	int		i;
	int		len;
	int		sign;

	sign = (nbr < 0) ? -1 : 1;
	if (sign == -1)
		nbr = nbr * -1;
	if (nbr == 0)
		return (base = ft_strndup(base_to, 1));
	len = ft_strlen(base_to);
	ct = (sign == 1) ? ft_intlen(nbr, len) : ft_intlen(nbr, len) + 1;
	base = ft_memalloc(sizeof(char) * (len + 1));
	i = 1;
	while (nbr)
	{
		base[ct - i] = base_to[nbr % len];
		nbr /= len;
		i++;
	}
	if (sign == -1)
		base[0] = '-';
	base[ct] = '\0';
	return (base);
}

static	int		ft_repeat(char *base)
{
	while (*base)
	{
		if (*base == '-' || *base == '+')
			return (1);
		if (ft_strchr(base + 1, *base))
			return (1);
		base++;
	}
	return (0);
}

static	int		ft_valide(char *nbr, char *base_from, char *base_to)
{
	if (ft_repeat(base_from) || ft_repeat(base_to))
		return (1);
	while (*nbr)
	{
		if (!(ft_strchr(base_from, *nbr) || *nbr == '-' || *nbr == '+'))
			return (1);
		nbr++;
	}
	return (0);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*convert;
	int		nb;

	if (ft_valide(nbr, base_from, base_to))
		return (NULL);
	nb = nbr_to_int(nbr, base_from);
	convert = int_to_base(nb, base_to);
	return (convert);
}
