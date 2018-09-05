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

/*
**  To read a file, starting at its `offset` char (when '+' is used)
*/

void		begin_read(int fd, int offset)
{
	char*		tab;

	if ((tab = malloc(offset)) == 0)
		return ;
	read(fd, tab, offset - 1);
	reset_buff(tab, offset);
	while (read(fd, tab, offset) > 0)
	{
		print_str(tab, 1);
		reset_buff(tab, offset);
	}
	free(tab);
	close(fd);
}

/*
** To print the last `offset` chars of a file (when '+' is NOT used)
*/
#include <stdio.h>
void		end_read(int fd, int offset)
{
	char*		buff1;
	char*		buff2;
	char*		tmp;
	int			buff1_len;

	if ((buff1 = malloc(offset)) == NULL)
		return ;
	if ((buff2 = malloc(offset)) == NULL)
		return ;
	while (read(fd, buff1, offset) == offset || read(fd, buff1, 1) != 0)
	{
		reset_buff(buff2, offset);
		tmp = buff2;
		buff2 = buff1;
		buff1 = tmp;
	}
	buff1_len = ft_strlen(buff1);
	if (offset - buff1_len > 0)
		write(1, buff2 + buff1_len, offset - buff1_len);
	write(1, buff1, buff1_len);
	free(buff1);
	free(buff2);
	close(fd);
}

/*
** Function to print the header in between reading multiple files
*/

void		prnt_head(char *fname)
{
	write(1, "==> ", 4);
	print_str(fname, 1);
	write(1, " <==\n", 5);
}

/*
** Checks if the offset is correct (legal)
**  Returns a negative offset if there's a '+' (yeah I know..)
*/

int			get_offset(char *str)
{
	char		*tmp;
	int			res;

	tmp = str;
	res = 1;
	if (*str == '+' && str++)
		res = -1;
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
		{
			write(2, "ft_tail: illegal offset -- ", 27);
			print_str(tmp, 2);
			write(2, "\n", 1);
			return (0);
		}
	++str;
	}
	return (res * ft_atoi(str));
}

int			main(int argc, char **argv)
{
	int			offset;
	char		header;
	int			i;

	if (argc < 3 || (offset = get_offset(argv[2])) == 0)
		return (0);
	header = (argc > 4) ? 1 : 0;
	if (argc == 3)
	{
		if (offset < 0)
			begin_read(STDIN_FILENO, offset * -1);
		else
			end_read(STDIN_FILENO, offset);
	}
	else
	{
		i = 2;
		while (++i < argc)
		{
			if (header)
				prnt_head(argv[i]);
			if (offset < 0)
				begin_read(ft_open(argv[i]), offset * -1);
			else
				end_read(ft_open(argv[i]), offset);
			if (i < argc - 1)
				write(1, "\n", 1);
		}
	}
	return (0);
}
