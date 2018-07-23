/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 19:25:26 by exam              #+#    #+#             */
/*   Updated: 2018/07/13 19:40:46 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		finder(char *needle, char *haystack)
{
	int i;

	if (*needle == '\0')
		return (1);
	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == *needle)
			return (finder(needle + 1, haystack + i));
		++i;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (*argv[2])
	{
		if (finder(argv[1], argv[2]))
		{
			write(1, "1\n", 2);
			return (1);
		}
		++argv[2];
	}
	write(1, "0\n", 2);
	return (0);
}
