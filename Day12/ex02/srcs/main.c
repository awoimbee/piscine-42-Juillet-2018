/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 18:30:47 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/22 18:30:48 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		read_stdin(int offset)
{
	char	c;

	lseek(STDIN_FILENO, lseek(STDIN_FILENO, 0, SEEK_END) - offset, SEEK_SET);
	while (read(STDIN_FILENO, &c, 1) > 0)
		write(1, &c, 1);
	return (4454);
}

void	prnt_head(char *fname)
{
	write(1, "==> ", 4);
	print_str(fname, 1);
	write(1, " <==\n", 5);
}

int		isoffsetlegal(char *str)
{
	char		*tmp;

	tmp = str;
	while (*str)
		if (!('0' <= *str && *str <= '9') || str++ == 0)
		{
			write(2, "ft_tail: illegal offset -- ", 27);
			print_str(tmp, 2);
			write(2, "\n", 1);
			return (0);
		}
	return (1);
}

int		main(int argc, char **argv)
{
	unsigned int	offset;
	char			header;
	int				i;

	if (!isoffsetlegal(argv[2]))
		return (0);
	offset = ft_atoi(argv[2]);
	header = (argc > 4) ? 1 : 0;
	if (argc == 3)
		return (read_stdin(offset));
	i = 2;
	while (++i < argc)
	{
		if (header)
			prnt_head(argv[i]);
		read_file(argv[i], offset);
		if (i < argc - 1)
			write(1, "\n", 1);
	}
	return (0);
}
