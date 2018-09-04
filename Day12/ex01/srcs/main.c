/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 18:30:47 by awoimbee          #+#    #+#             */
/*   Updated: 2018/09/04 01:17:48 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	print_str(char *str)
{
	int		i;

	i = 0;
	while (str[i] > 0)
		++i;
	if (i > 0)
		write(1, str, i);
}

int	ft_open(char* filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "ft_strcat: ", 12);
		if (errno == 21 || errno == 2)
			print_str(filename);
		if (errno == 21)
			write(2, ": Is a directory\n", 15);
			
		if (errno == 2)
			write(2, ": No such file or directory\n", 28);
	}
	return fd;
}

void	read_file(char *filename)
{
	int		fd;
	char	tab[28000];

	if ((fd = ft_open(filename)) == -1)
		return ;
	while (read(fd, &tab[0], 28000) > 0)
		print_str(&tab[0]);
	close(fd);
}

void	read_stdin(void)
{
	char	c;

	while (read(STDIN_FILENO, &c, 1) > 0)
		write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int i;

	if (argc == 1)
		read_stdin();
	i = 0;	
	while (++i < argc) //its reading args in the wrong way !
	{
		if (argv[i][0] == '-' && argv[i][1] == '\0')
			read_stdin();
		else
			read_file(argv[i]);
	}
	return (0);
}
