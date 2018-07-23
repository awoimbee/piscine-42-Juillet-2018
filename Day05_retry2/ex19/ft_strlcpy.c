/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 01:06:02 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/09 01:06:05 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int		tmp_size;
	char	*source;

	source = src;
	tmp_size = size;
	if (size != 0)
	{
		while (--tmp_size > 0)
		{
			*dest = *src;
			++dest;
			++src;
			if (*(dest - 1) == '\0')
				break ;
		}
	}
	if (tmp_size == 0)
	{
		if (size > 0)
			*dest = '\0';
		while (*src)
			++src;
		++src;
	}
	return (src - source - 1);
}
