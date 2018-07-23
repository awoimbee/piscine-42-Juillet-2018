/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 00:50:54 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/05 12:57:10 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*skip_lead_whitespace(char *str)
{
	while (*str == ' '
		|| *str == '\n'
		|| *str == '\t'
		|| *str == '\f'
		|| *str == '\v'
		|| *str == '\r')
	{
		++str;
	}
	return (str);
}

int		str_to_int(char *str_start, char *str_end, long int ten_pow_len)
{
	int		return_nb;

	return_nb = 0;
	while (str_start < str_end)
	{
		return_nb += (*str_start - '0') * ten_pow_len;
		++str_start;
		ten_pow_len /= 10;
	}
	return (return_nb);
}

int		ft_atoi(char *str)
{
	char		*str_start;
	long int	coeff;

	str = skip_lead_whitespace(str);
	coeff = 1;
	if (*str == '-')
	{
		coeff *= -1;
		++str;
	}
	else if (*str == '+')
		++str;
	str_start = str;
	while ('0' <= *str && *str <= '9')
	{
		coeff *= 10;
		++str;
	}
	coeff /= 10;
	return (str_to_int(str_start, str, coeff));
}
