/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 14:04:11 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/08 14:04:15 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Wikipedia :
** Codes 20hex=32 to 7Ehex=126 are known as the printable characters.
** There are 95 printable characters in total.
*/

int	ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if (!(32 <= *str && *str <= 126))
		{
			return (0);
		}
		++str;
	}
	return (1);
}
