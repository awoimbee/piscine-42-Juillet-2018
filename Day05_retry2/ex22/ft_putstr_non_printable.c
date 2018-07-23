/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:27:54 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/09 18:27:57 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	putnbr_hex(int nbr)
{
	char	*base;

	base = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(base[(nbr / 16) % 16]);
	ft_putchar(base[nbr % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str < 32 || *str == 127)
			putnbr_hex((int)*str);
		else
			ft_putchar(*str);
		++str;
	}
	return ;
}
