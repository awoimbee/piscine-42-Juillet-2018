/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:35:48 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/18 19:35:52 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
** Compare elements 2 by 2
** if they aren't in order we swap them and go back to checking the first 2
*/

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
