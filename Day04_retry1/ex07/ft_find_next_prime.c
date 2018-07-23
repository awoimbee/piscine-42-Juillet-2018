/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 15:39:04 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/07 15:39:06 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	test_is_prime(int nb)
{
	long int	sqroot;
	int			i;

	if (nb == 2 || nb == 2147483647)
		return (1);
	if (nb % 2 == 0 || nb < 2)
		return (0);
	sqroot = 1;
	while (sqroot * sqroot <= nb)
	{
		++sqroot;
	}
	i = 3;
	while (i <= sqroot)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (test_is_prime(nb))
		return (nb);
	else if (nb < 2)
		return (2);
	else
	{
		while (!test_is_prime(nb))
		{
			++nb;
		}
	}
	return (nb);
}
