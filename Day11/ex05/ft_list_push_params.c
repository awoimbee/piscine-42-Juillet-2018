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

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*tmp_old;
	t_list	*tmp_new;

	i = 0;
	tmp_old = 0;
	while (++i <= ac)
	{
		tmp_new = ft_create_elem(&av[ac - i]);
		tmp_new->next = tmp_old;
		tmp_old = tmp_new;
	}
	return (tmp_new);
}
