/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 19:36:54 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/12 19:36:56 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

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

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		++str;
	}
	return ;
}

void	ft_show_tab(struct s_stock_par *par)
{
	int	i;

	while (par->str != 0)
	{
		ft_putstr(par->str);
		ft_putchar('\n');
		ft_putnbr(par->size_param);
		ft_putchar('\n');
		i = -1;
		while (par->tab[++i] != 0)
		{
			ft_putstr(par->tab[i]);
			ft_putchar('\n');
		}
		par += 1;
	}
	return ;
}
