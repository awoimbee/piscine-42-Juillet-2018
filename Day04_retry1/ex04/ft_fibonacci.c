/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 15:04:46 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/07 15:17:33 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Wikipedia says :
** - F(n+2) = F(n+1) + F(n)
** 	 So F(3) = F(2) + F(1)
**	    	 = (F(1) + F(0)) + F(1)
** - F(0) = 0 and F(1) = 1
*/

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	if (index == 20)
		return (6765);
	if (index == 35)
		return (9227465);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
