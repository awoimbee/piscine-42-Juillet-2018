/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 13:24:33 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/18 13:24:34 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	if (begin_list == 0)
		return (0);
	i = 0;
	while (begin_list->next || i == nbr)
	{
		if (i == nbr)
			return (begin_list);
		begin_list = begin_list->next;
		++i;
	}
	return (0);
}
