/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 13:19:41 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/18 13:19:43 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list **begin_list)
{
	t_list	*to_del;
	t_list	*next_elem;

	to_del = *begin_list;
	while (to_del->next)
	{
		next_elem = to_del->next;
		free(to_del);
	}
	free(to_del);
	*begin_list = 0;
}
