/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 13:08:10 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/18 13:08:12 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		list_push_front(t_list **begin_list, void *data)
{
	t_list *new_elem;

	new_elem = ft_create_elem(data);
	new_elem->next = *begin_list;
	*begin_list = new_elem;
}

t_list		*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*list;

	i = -1;
	list = 0;
	while (++i < ac)
	{
		list_push_front(&list, av[i]);
	}
	return (list);
}
