/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfuck.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 20:09:03 by exam              #+#    #+#             */
/*   Updated: 2018/07/13 21:16:38 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BFUCK_H
# define BFUCK_H
# include <unistd.h>
# include <stdlib.h>

char	*g_ptr;

void	init(void);
void	parser(char *in);
void	dothething(char c);

#endif
