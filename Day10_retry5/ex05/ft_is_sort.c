/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 15:43:52 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/16 15:59:54 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		order;

	if (!tab || !f || length <= 0)
		return (1);
	if (length == 1)
		return (1);
	i = 0;
	while (i < length - 1 && f(tab[i], tab[i + 1]) == 0)
		++i;
	if (i == length)
		return (1);
	order = (f(tab[i], tab[i + 1]) > 0) ? 1 : -1;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0 && order == -1)
			return (0);
		if (f(tab[i], tab[i + 1]) < 0 && order == 1)
			return (0);
		++i;
	}
	return (1);
}
