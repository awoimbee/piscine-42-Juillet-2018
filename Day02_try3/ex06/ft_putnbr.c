/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <arthur.woimbee@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 20:33:23 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/05 18:26:25 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_putnbr(int nb)
{
	long int	num;
	int			digit;
	long int	power_10;
	long int	nb2;

	nb2 = nb;
	if (nb2 < 0)
	{
		ft_putchar('-');
		nb2 = nb2 * -1;
	}
	power_10 = 1;
	num = nb2;
	while (num > 9)
	{
		num /= 10;
		power_10 *= 10;
	}
	while (power_10 > 0)
	{
		digit = (nb2 / power_10) % 10;
		ft_putchar('0' + digit);
		power_10 /= 10;
	}
	return ;
}
