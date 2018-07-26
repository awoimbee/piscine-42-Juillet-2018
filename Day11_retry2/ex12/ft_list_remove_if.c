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
	t_list	*tmp;
	t_list	*last;

	if (begin_list == NULL || !(*begin_list))
		return ;
	last = *begin_list;
	while (last->next && last)
	{
		if (cmp(last->next->data, data_ref) == 0)
		{
			tmp = last->next;
			last->next = last->next->next;
			free(tmp);
		}
		else
			last = last->next;
	}
	last = *begin_list;
	if (last != NULL && cmp(last->data, data_ref) == 0)
	{
		*begin_list = last->next;
		free(last);
	}
}
