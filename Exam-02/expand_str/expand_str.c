/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 19:02:28 by exam              #+#    #+#             */
/*   Updated: 2018/07/20 19:20:06 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	trigger;

	trigger = 0;
	if (argc == 2)
	{
		while (*argv[1] && (*argv[1] == ' ' || *argv[1] == '	'))
			++argv[1];

		while (*argv[1])
		{
			while (*argv[1] && *argv[1] != ' ' && *argv[1] != '	')
			{
				if (trigger == 1 && !(trigger = 0))
					write(1, "   ", 3);
				write(1, argv[1], 1);
				++argv[1];
			}
			trigger = 1;
			if (*argv[1])
				++argv[1];
		}

	}
	write(1, "\n", 1);
}

