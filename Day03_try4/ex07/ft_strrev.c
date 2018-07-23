/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 23:25:24 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/05 00:21:20 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
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
