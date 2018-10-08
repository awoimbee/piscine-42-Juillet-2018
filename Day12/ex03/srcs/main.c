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
	while (str[i] != 0)
		++i;
	if (i != 0)
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

char*	ft_strcpy(char *dest, char *src)
{
	while (*src != '\0')
	{
		*dest = *src;
		++dest;
		++src;
	}
	*dest = '\0';
	return (dest);
}

char*	ft_strncpy(char *dest, char *src, uint len)
{
	uint		i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		++i;
	}
	return (dest + len);
}

char		*f_strrev(char *str, int len)
{
	char	*start;
	char	*end;
	char	buff;

	start = str;
	end = str + len - 1;
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

/*
** result needs to be freed
*/
char		*itoa_base16(int value, int str_length)
{
	char	*str_base;
	char	*result;
	int		i;
	int		base;

	base = 16;
	str_base = "0123456789abcdef";
	if (!(result = malloc((str_length + 1) * sizeof(char))))
		return (" ");
	i = 0;
	while (i != str_length)
	{
		result[i++] = str_base[value % base];
		value /= base;
	}
	result[i] = '\0';
	return(f_strrev(result, str_length));
}

void	print_str_b16(char *str, int length, char *buff)
{
	int		i;

	i = -1;
	while (++i < length)
	{
		ft_strcpy(buff, itoa_base16((int)(unsigned char)str[i], 2));
		if (i == 7)
			buff = ft_strcpy(buff + 2, "  ");
		else
			buff = ft_strcpy(buff + 2, " ");
	}
	while (i < 16)
	{
		if (i == 7)
			buff = ft_strcpy(buff, "    ");
		else
			buff = ft_strcpy(buff, "   ");
		++i;
	}
	return ;
}

void	print_str_special(char *str, int length, char *buff)
{
	int		i;

	*buff = '|';
	++buff;
	i = -1;
	while (++i < length)
	{
		if (str[i] < 32)
			buff[i] = '.';
		else
			buff[i] = str[i];
	}
	buff[i] = '|';
}

int	ft_strcmp(char *s1, char *s2, int len)
{
	int		i;

	i = 0;
	--len;
	while (s1[i] == s2[i] && i < len)
		++i;
	return (s1[i] - s2[i]);
}

void	swap_tab(char **tab1, char **tab2)
{
	char	*tmp;

	tmp = *tab1;
	*tab1 = *tab2;
	*tab2 = tmp;
}

void	read_file(char *fname)
{
	int		fd;
	char	*tab;
	char	*otab;
	int		glob_read;
	int		loc_read;
	char	output[79] = "\0";

	glob_read = 0;
	if ((fd = ft_open(fname)) == -1
		|| !(tab = malloc(17)) || !(otab = malloc(17)))
		return ;
	tab[16] = '\0';
	otab[16] = '\0';
	while ((loc_read = read(fd, tab, 16)) > 0)
	{
		tab[loc_read] = '\0';
		if (ft_strcmp(tab, otab, 16) == 0)
		{
			if (ft_strcmp(&output[0], "*\n", 2) != 0)
			{
				print_str(&output[0]);
				ft_strcpy(&output[0], "*\n");
			}
			glob_read += loc_read;
			continue ;
		}
		print_str(&output[0]);

		ft_strcpy(&output[0], itoa_base16(glob_read, 8));
		ft_strcpy(&output[8], "  ");
		print_str_b16(tab, loc_read, &output[10]);
		ft_strcpy(&output[59], " ");
		print_str_special(tab, loc_read, &output[60]);
		ft_strcpy(&output[60 + 2 + loc_read], "\n");
		swap_tab(&otab, &tab);
		glob_read += loc_read;
	}
	print_str(&output[0]);
	print_str(itoa_base16(glob_read, 8));
	write(1, "\n", 1);
	free(tab);
	free(otab);
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
