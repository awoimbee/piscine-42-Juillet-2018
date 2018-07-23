/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:35:48 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/18 19:35:52 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*list_ptr;
	t_list	*old_list_ptr;

	if ((list_ptr = *begin_list) == 0)
		return ;
	old_list_ptr = 0;
	if (((*cmp)(list_ptr->data, data_ref)) == 0)
	{
		*begin_list = list_ptr->next;
		free(list_ptr);
		list_ptr = *begin_list;
	}
	while (list_ptr->next)
	{
		if (((*cmp)(list_ptr->data, data_ref)) == 0)
		{
			old_list_ptr->next = list_ptr->next;
			free(list_ptr);
			list_ptr = old_list_ptr;
		}
		old_list_ptr = list_ptr;
		list_ptr = list_ptr->next;
	}
}
