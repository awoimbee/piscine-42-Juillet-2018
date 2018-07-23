/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <arthur.woimbee@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 20:33:23 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/05 18:26:01 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_comb2(void)
{
	int nb1;
	int nb2;
	int nb_digit;

	nb1 = -1;
	while (++nb1 < 100)
	{
		nb2 = nb1;
		while (++nb2 < 100)
		{
			nb_digit = nb1 / 10;
			ft_putchar('0' + nb_digit);
			ft_putchar('0' + nb1 - nb_digit * 10);
			ft_putchar(' ');
			nb_digit = nb2 / 10;
			ft_putchar('0' + nb_digit);
			ft_putchar('0' + nb2 - nb_digit * 10);
			if (!(nb1 == 98 && nb2 == 99))
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
	}
}
