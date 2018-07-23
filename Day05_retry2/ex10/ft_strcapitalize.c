/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 12:31:21 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/08 12:31:23 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_alphanum(char letter)
{
	if (('0' <= letter && letter <= '9')
		|| ('A' <= letter && letter <= 'Z')
		|| ('a' <= letter && letter <= 'z'))
	{
		return (1);
	}
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += 32;
	}
	i = -1;
	while (str[++i])
	{
		if (('a' <= str[i] && str[i] <= 'z')
			&& (i == 0 || !is_alphanum(str[i - 1])))
			str[i] -= 32;
	}
	return (str);
}
