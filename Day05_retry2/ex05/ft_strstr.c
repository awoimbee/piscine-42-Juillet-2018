/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 12:00:56 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/08 12:01:09 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_found(char *haystack, char *needle)
{
	if (*needle == '\0')
		return (1);
	if (*haystack == '\0' || *haystack != *needle)
		return (0);
	if (*haystack == *needle)
	{
		return (is_found(haystack + 1, needle + 1));
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	while (*str != '\0')
	{
		if (is_found(str, to_find))
			return (str);
		++str;
	}
	return (0);
}
