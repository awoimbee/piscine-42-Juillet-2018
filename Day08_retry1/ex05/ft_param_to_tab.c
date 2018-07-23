/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:45:03 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/12 12:45:05 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

int					ft_strlen(char *str)
{
	int word_nb;

	word_nb = 0;
	while (*str != '\0')
	{
		++word_nb;
		++str;
	}
	return (word_nb);
}

char				*ft_strdup(char *src)
{
	char *dest;
	char *dest2;

	dest = (char*)malloc((ft_strlen(src) + 1) * sizeof(char));
	dest2 = dest;
	while (*src)
	{
		*dest = *src;
		++dest;
		++src;
	}
	*dest = *src;
	return (dest2);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par *struct_tab;
	t_stock_par *start_struct_tab;
	int			i;

	struct_tab = (t_stock_par*)malloc(sizeof(t_stock_par) * (ac + 1));
	start_struct_tab = struct_tab;
	i = -1;
	while (++i < ac)
	{
		struct_tab->size_param = ft_strlen(av[i]);
		struct_tab->str = av[i];
		struct_tab->copy = ft_strdup(av[i]);
		struct_tab->tab = ft_split_whitespaces(av[i]);
		++struct_tab;
	}
	struct_tab->str = 0;
	return (start_struct_tab);
}
