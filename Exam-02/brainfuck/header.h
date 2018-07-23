/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 19:51:11 by exam              #+#    #+#             */
/*   Updated: 2018/07/20 20:47:20 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>

void	init_g_ptr(void);
int		*alloc_loops(char *inp);
void	sht_parser(char c);
void	parser(char *p, int *loops);

#endif
