/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:24:23 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/22 17:24:26 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	void	*buff;
	t_list	*ptr1;
	t_list	*ptr2;

	ptr1 = *begin_list;
	if (!(ptr1) || !(ptr2 = ptr1->next))
		return ;
	while (ptr1->next)
	{
		if ((*cmp)(ptr1->data, ptr2->data) > 0)
		{
			buff = ptr1->data;
			ptr1->data = ptr2->data;
			ptr2->data = buff;
			ptr2 = *begin_list;
		}
		ptr1 = ptr2;
		ptr2 = ptr2->next;
	}
}

void		ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_elem;

	new_elem = ft_create_elem(data);
	new_elem->next = *begin_list;
	*begin_list = new_elem;
}

void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	ft_list_push_front(begin_list, data);
	ft_list_sort(begin_list, cmp);
}
