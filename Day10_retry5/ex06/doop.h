/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 16:09:47 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/16 16:09:49 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOP_H
# define DOOP_H

# include <unistd.h>

typedef int(*t_fun_op)(int, int);

int			ft_add(int first, int second);
int			ft_sub(int first, int second);
int			ft_divide(int first, int second);
int			ft_multiply(int first, int second);
int			ft_modulo(int first, int second);
t_fun_op	ft_operator(char c);
int			ft_fatoi(char *str);
int			ft_fputnbr(int nb);
int			nbrs_valid(char *str);

#endif
