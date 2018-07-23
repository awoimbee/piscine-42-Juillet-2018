/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 22:01:58 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/07 22:02:02 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char				*srccpy;
	unsigned int		i;

	srccpy = dest;
	i = 0;
	while (i < n && *src != '\0')
	{
		*dest = *src;
		++dest;
		++src;
		++i;
	}
	while (i < n && *dest != '\0')
	{
		*dest = '\0';
		++dest;
		++i;
	}
	return (srccpy);
}
