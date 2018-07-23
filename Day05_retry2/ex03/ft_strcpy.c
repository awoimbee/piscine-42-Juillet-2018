/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:26:41 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/07 21:26:48 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char *srccpy;

	srccpy = dest;
	while (*src != '\0')
	{
		*dest = *src;
		++dest;
		++src;
	}
	*dest = *src;
	return (srccpy);
}
