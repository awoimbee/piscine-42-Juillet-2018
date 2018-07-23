/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
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

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*list1_ptr;

	list1_ptr = *begin_list1;
	if (begin_list2 == 0)
		return ;
	if ((begin_list1 == 0 || *begin_list1 == 0))
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (list1_ptr->next)
		list1_ptr = list1_ptr->next;
	list1_ptr->next = begin_list2;
	return ;
}

void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort(begin_list1, cmp);
}
