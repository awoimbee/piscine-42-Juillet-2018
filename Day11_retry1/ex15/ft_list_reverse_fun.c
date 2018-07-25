/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:21:04 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/22 17:21:07 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ftt_list_at(t_list *begin_list, unsigned int nbr)
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

int			ftt_list_size(t_list *begin_list)
{
	int		i;

	if (begin_list == 0)
		return (0);
	i = 1;
	while (begin_list->next)
	{
		begin_list = begin_list->next;
		++i;
	}
	return (i);
}

void		ft_list_reverse_fun(t_list *begin_list)
{
	char			*buffer;
	int				end;
	int				start;
	t_list			*list;

	list = begin_list;
	end = ftt_list_size(begin_list) - 1;
	start = 0;
	while (start < end)
	{
		buffer = ftt_list_at(list, start)->data;
		ftt_list_at(list, start)->data = ftt_list_at(list, end)->data;
		ftt_list_at(list, end)->data = buffer;
		--end;
		++start;
	}
}
