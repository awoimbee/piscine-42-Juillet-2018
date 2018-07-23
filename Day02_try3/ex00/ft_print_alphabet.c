/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <arthur.woimbee@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 20:33:23 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/05 18:26:54 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_alphabet(void)
{
	char letter;

	letter = 'a';
	while (letter <= 'z')
	{
		ft_putchar(letter);
		++letter;
	}
	return ;
}
