/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverserotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:17:35 by vlay              #+#    #+#             */
/*   Updated: 2017/11/10 16:17:49 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstreverserotate(t_list **alst)
{
	t_list	*tmp;

	tmp = *alst;
	if (!tmp || !tmp->next)
		return (0);
	if (!tmp->next->next)
	{
		ft_swap(&tmp->content, &tmp->next->content);
		return (1);
	}
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *alst;
	*alst = tmp->next;
	tmp->next = NULL;
	return (1);
}
