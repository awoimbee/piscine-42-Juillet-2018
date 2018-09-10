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

#include <stdio.h>
void	print_nbr_hex(int nb)
{
	char	c;
	char*	nums; 

	nums = "0123456789abcdef";
	int divider = 0xffffffff;
	while (divider != 0)
	{
		c = (nb / divider);
		nb %= divider;
		divider /= 0xf;
		write (1, &nums[c], 1);
	}
	write (1, "  ", 2); 
	printf("%s \n", "PUTE DE SALOPE");
}


void	read_file(char *filename)
{
	int		fd;
	char	tab[10];
	int		offset;

	offset = 0;
	if ((fd = ft_open(filename)) == -1)
		return ;
	while ((read(fd, &tab[0], 10) > 0) && (offset += 10))
	{
		print_nbr_hex(offset);
		//print_str(&tab[0]);
	}
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
