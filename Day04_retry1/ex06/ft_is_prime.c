/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 15:21:46 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/07 15:30:31 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** To test if N if prime :
**  test if it's divisible by 2 and uneven integers in the range [2 ; sqrt(N)]
**  If it cannot, then it is a prime number else it's composed
*/

int		ft_is_prime(int nb)
{
	int			i;
	long int	sqroot;

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
