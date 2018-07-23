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

int		ft_atoi(char *str)
{
	short int	sign;
	int			return_nb;

	while (!(return_nb = 0) && (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\f' || *str == '\v' || *str == '\r'))
		++str;
	sign = (*str == '-' && ++str) ? -1 : 1;
	str += (*str == '+') ? 1 : 0;
	while ('0' <= *str && *str <= '9')
		return_nb = return_nb * 10 + (*(str++) - '0');
	return (return_nb * sign);
}
