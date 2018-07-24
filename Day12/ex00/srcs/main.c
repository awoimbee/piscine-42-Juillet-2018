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

int		main(int argc, char **argv)
{
	int		fd;
	char	tab[1];

	if (argc == 1)
		return (write(1, "File name missing.\n", 19));
	if (argc > 2)
		return (write(1, "Too many arguments.\n", 20));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	while (read(fd, &tab[0], 1))
		write(1, &tab[0], 1);
	close(fd);
	return (0);
}
