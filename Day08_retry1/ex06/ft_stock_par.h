/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_par.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:45:20 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/12 12:45:22 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_PAR_H
# define FT_STOCK_PAR_H

typedef struct		s_stock_par
{
	int		size_param;
	char	*str;
	char	*copy;
	char	**tab;
}					t_stock_par;

#endif

#ifndef FT_STOCK_PAR_SHOW_H
# define FT_STOCK_PAR_SHOW_H

int					ft_putchar(char c);
void				ft_show_tab(struct s_stock_par *par);

#endif
