/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 18:48:12 by exam              #+#    #+#             */
/*   Updated: 2018/07/06 19:31:32 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int				l;
	unsigned char	a;
	unsigned char	b;

	l = 0;
	while (s1[l] != '\0' || s2[l] != '\0')
	{
		a = s1[l];
		b = s2[l];
		if (b - a != 0)
			return (a - b);
		++l;
	}
	return (0);
}
