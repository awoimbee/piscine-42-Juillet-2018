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
# include <stdlib.h>
# include <errno.h>

int		ft_atoi(char *str);
int		ft_strlen(char *str);
void	print_str(char *str, int channel);
int		ft_open(char* filename);
void	reset_buff(char* buffer, int size);
void	begin_read(int fd, int offset);
void	end_read(int fd, int offset);
void	prnt_head(char *fname);
int		isoffsetlegal(char *str);

#endif
