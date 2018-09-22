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

char		*f_strrev(char *str)
{
	char	*start;
	char	*end;
	char	buff;

	start = str;
	end = str;
	while (*(end + 1))
		++end;
	while (start < end)
	{
		buff = *start;
		*start = *end;
		*end = buff;
		start++;
		end--;
	}
	return (str);
}

void		itoa_base16(int value, int str_length)
{
	char	*str_base;
	char	*result;
	int		i;
	int		base;

	base = 16;
	str_base = "0123456789abcdef";
	if (!(result = malloc((str_length + 1) * sizeof(char))))
		return ;
	i = 0;
	result[i] = '0';
	while (value != 0 && i < str_length)
	{
		result[i++] = str_base[value % base];
		value /= base;
	}
	while (i != str_length)
		result[i++] = '0';
	result[i++] = '\0';
	write(1, f_strrev(result), str_length);
}

void	print_str_b16(char *str, int length)
{
	int		i;

	i = -1;
	while (++i < length)
	{
		itoa_base16((int)str[i], 2);
		if (i == 7)
			write(1, "  ", 2);
		else
			write(1, " ", 1);
	}
	while (length++ < 16)
		write(1, "   ", 3);
	write(1, " ", 1);
}

void	print_str_special(char *str, int length)
{
	int		i;

	i = -1;
	while (++i < length)
	{
		if (str[i] < 32)
			str[i] = '.';
	}
	write(1, "|", 1);
	write(1, str, length);
	write(1, "|", 1);
}

void	read_file(char *filename)
{
	int		fd;
	char	tab[16];
	int		global_read;
	int		local_read;

	global_read = 0;
	if ((fd = ft_open(filename)) == -1)
		return ;
	while ((local_read = read(fd, &tab[0], 16)) > 0)
	{
		global_read += local_read;
		itoa_base16(global_read, 8);
		write(1, "  ", 2);
		print_str_b16(&tab[0], local_read);
		print_str_special(&tab[0], local_read);
		write(1, "\n", 1);
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
