/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 12:28:41 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/18 12:28:43 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *last_elem;

	if (*begin_list == 0)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	last_elem = *begin_list;
	while (last_elem->next)
		last_elem = last_elem->next;
	last_elem->next = ft_create_elem(data);
}
