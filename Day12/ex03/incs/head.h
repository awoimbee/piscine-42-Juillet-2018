/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 18:32:51 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/22 18:32:54 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>

void	print_str(char *str);
int		ft_open(char* filename);
char	*f_strrev(char *str, int len);
char	*itoa_base16(int value, int str_length);
void	print_str_b16(char *str, int length, char *buff);
void	print_str_special(char *str, int length, char *buff);
int		ft_strncmp(char *s1, char *s2, uint len);
void	swap_tab(char **tab1, char **tab2);
void	read_file(char *fname);
void	read_stdin(void);

#endif
