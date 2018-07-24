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
	t_list	*ptr;
	t_list	*ptr2;

	if ((ptr = *begin_list) == 0 || cmp == 0)
		return ;
	ptr2 = 0;
	while (ptr)
	{
		if (((*cmp)(ptr->data, data_ref)) == 0 && ptr2 == 0)
		{
			ptr2 = ptr;
			ptr = ptr->next;
			free(ptr2);
			*begin_list = ptr;
			continue ;
		}
		if (((*cmp)(ptr->data, data_ref)) == 0)
		{
			ptr2->next = ptr->next;
			ptr = ptr2;
			free(ptr2->next);
		}
		ptr2 = ptr;
		ptr = ptr->next;
	}
}
