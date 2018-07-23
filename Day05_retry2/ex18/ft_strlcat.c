/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 17:10:25 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/08 17:10:28 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int word_nb;

	word_nb = 0;
	while (*str != '\0')
	{
		++word_nb;
		++str;
	}
	return (word_nb);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int		tmp_size;
	int		destlen;
	char	*tmp_dest;
	char	*tmp_src;

	tmp_dest = dest;
	tmp_size = size;
	while (tmp_size-- != 0 && *tmp_dest != '\0')
		++tmp_dest;
	destlen = tmp_dest - dest;
	tmp_size = size - destlen;
	if (tmp_size == 0)
		return (destlen + ft_strlen(src));
	tmp_src = src;
	while (*tmp_src != '\0')
	{
		if (tmp_size-- != 1)
			*tmp_dest++ = *tmp_src;
		++tmp_src;
	}
	*tmp_dest = '\0';
	return (destlen + (tmp_src - src));
}
