/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <arthur.woimbee@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 23:33:23 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/05 18:17:03 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_numbers(void)
{
	char digit;

	digit = '0';
	while (digit <= '9')
	{
		ft_putchar(digit);
		++digit;
	}
	return ;
}
