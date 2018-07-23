/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:04:42 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/09 13:04:46 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		get_base_len(char *base)
{
	long int	baselen;
	int			i;

	baselen = -1;
	while (base[++baselen])
	{
		if (baselen == 2147483647)
			return (0);
		if (base[i] == '+'
			|| base[i] == '-'
			|| base[i] < 32
			|| base[i] > 126)
			return (0);
		i = 0;
		while (i < baselen)
		{
			if (base[i] == base[baselen])
				return (0);
			++i;
		}
	}
	return (baselen);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				digits[33];
	long int		nbr2;
	int				baselen;

	baselen = get_base_len(base);
	if (baselen < 2)
		return ;
	nbr2 = nbr;
	if (nbr2 < 0)
	{
		ft_putchar('-');
		nbr2 *= -1;
	}
	nbr = 0;
	while (nbr2 != 0)
	{
		digits[nbr] = nbr2 % baselen;
		nbr2 = nbr2 / baselen;
		++nbr;
	}
	while (nbr-- > 0)
		ft_putchar(base[digits[nbr]]);
}
