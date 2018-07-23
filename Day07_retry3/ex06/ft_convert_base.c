/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:23:59 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/10 17:24:02 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strrev(char *str)
{
	char buffer;
	char *str_start;
	char *str_end;

	str_start = str;
	str_end = str;
	while (*(str_end + 1) != '\0')
	{
		++str_end;
	}
	while (str_start < str_end)
	{
		buffer = *str_start;
		*str_start = *str_end;
		*str_end = buffer;
		++str_start;
		--str_end;
	}
	return (str);
}

char		*ft_to_base(long int nbr, int len_base, char *base, int sign)
{
	char	*result;
	int		tmp_nbr;
	int		i;

	i = (sign > 0) ? 1 : 2;
	tmp_nbr = nbr;
	while (tmp_nbr > 0 && i++)
		tmp_nbr /= len_base;
	result = malloc(i * sizeof(char));
	if (nbr == 0)
		return ("0");
	i = 0;
	while (nbr > 0)
	{
		result[i++] = base[nbr % len_base];
		nbr /= len_base;
	}
	if (sign == -1)
		result[i++] = '-';
	result[i] = '\0';
	ft_strrev(result);
	return (result);
}

long int	ft_atoi_base(char *nbr, char *base_from, int len_base)
{
	int			i;
	long int	nbr_b10;

	nbr_b10 = 0;
	while (*nbr)
	{
		i = -1;
		while (base_from[++i] && base_from[i] != *nbr)
			;
		if (base_from[i] != *nbr)
			return (nbr_b10);
		nbr_b10 *= len_base;
		nbr_b10 += i;
		++nbr;
	}
	return (nbr_b10);
}

int			get_base_len(char *base)
{
	int		base_len;
	char	tmp;

	base_len = 0;
	while (base[base_len])
	{
		tmp = base[base_len];
		if (tmp < 33 || tmp == 127 || tmp == '+' || tmp == '-')
			return (0);
		++base_len;
	}
	return (base_len);
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int len_base_in;
	int len_base_to;
	int sign;

	len_base_in = 0;
	len_base_to = 0;
	sign = 1;
	while (*nbr < 33 && *nbr != '\0')
		++nbr;
	if (*nbr == '-' && ++nbr)
		sign = -1;
	if (*nbr == '+')
		++nbr;
	len_base_in = get_base_len(base_from);
	len_base_to = get_base_len(base_to);
	if (len_base_in < 2 || len_base_to < 2)
		return ("0");
	return (ft_to_base(
		ft_atoi_base(nbr, base_from, len_base_in),
		len_base_to,
		base_to,
		sign));
}
