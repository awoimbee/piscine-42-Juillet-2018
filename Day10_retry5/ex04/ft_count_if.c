/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 15:33:52 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/16 15:33:54 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int (*f)(char*))
{
	int	counter;

	counter = 0;
	if (!tab)
		return (0);
	while (*tab)
	{
		if ((*f)(*tab) == 1)
			++counter;
		++tab;
	}
	return (counter);
}
