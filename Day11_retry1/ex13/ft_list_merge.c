/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:35:48 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/18 19:35:52 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*list1_ptr;

	if (begin_list2 == 0 || begin_list1 == 0)
		return ;
	if (*begin_list1 == 0)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	list1_ptr = *begin_list1;
	while (list1_ptr->next)
		list1_ptr = list1_ptr->next;
	list1_ptr->next = begin_list2;
	return ;
}
