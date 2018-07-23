/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <arthur.woimbee@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 20:33:23 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/05 18:17:58 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_comb(void)
{
	char digits[3];

	digits[0] = '0' - 1;
	while (++digits[0] <= '9')
	{
		digits[1] = digits[0];
		while (++digits[1] <= '9')
		{
			digits[2] = digits[1];
			while (++digits[2] <= '9')
			{
				ft_putchar(digits[0]);
				ft_putchar(digits[1]);
				ft_putchar(digits[2]);
				if (!(digits[0] == '7' && digits[1] == '8' && digits[2] == '9'))
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
		}
	}
	return ;
}
