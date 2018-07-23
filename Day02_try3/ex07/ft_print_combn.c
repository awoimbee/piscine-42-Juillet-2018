/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 12:22:40 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/05 18:29:41 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_plz_putnbr(int nb)
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
}

int		cal_max(int max)
{
	if (max == 1000000000)
		return (123456789 + 1);
	if (max == 100000000)
		return (23456789 + 1);
	if (max == 10000000)
		return (3456789 + 1);
	if (max == 1000000)
		return (456789 + 1);
	if (max == 100000)
		return (56789 + 1);
	if (max == 10000)
		return (6789 + 1);
	if (max == 1000)
		return (789 + 1);
	return (max);
}

int		cal_pow(int n)
{
	int	result;

	result = 1;
	while (n > 0)
	{
		result *= 10;
		--n;
	}
	return (result);
}

/*
** for a combinason abc, abc is new/valid only if :
** a<b<c
*/

int		test_iscombnew(int comb)
{
	while (comb >= 10)
	{
		if ((comb / 10) % 10 >= comb % 10)
		{
			return (0);
		}
		comb /= 10;
	}
	return (1);
}

void	ft_print_combn(int n)
{
	int	comb;
	int	max;
	int tmp_pow10;

	n = cal_pow(n);
	max = cal_max(n);
	comb = -1;
	while (++comb < max)
	{
		if (test_iscombnew(comb))
		{
			if (comb > 0)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			tmp_pow10 = n;
			while (comb < tmp_pow10 / 10 && tmp_pow10 > 10)
			{
				ft_putchar('0');
				tmp_pow10 /= 10;
			}
			ft_plz_putnbr(comb);
		}
	}
}
