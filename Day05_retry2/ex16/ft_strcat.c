/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 14:05:12 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/08 14:05:15 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*result;

	result = dest;
	while (*dest != '\0')
	{
		++dest;
	}
	while (*src != '\0')
	{
		*dest = *src;
		++src;
		++dest;
	}
	*dest = *src;
	return (result);
}
