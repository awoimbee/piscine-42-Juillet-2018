/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 00:06:34 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/07 00:14:28 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_putchar(char c)
{
		write(1, &c, 1);
			return 0;
}

int		cal_skip(int size)
{
	int		i;
	int		height;
	float 	skip;

	height = 3;
	i = -1;
	skip = ((size - 1) * 2) - 1;
	while (++i < size){
		skip += 1 * height;
		skip += 0.25;
		++height;
	}
	return ((int)skip);
}

void	sastantua(int size)
{
 	int width = 1;
	int height = 3;
	int stage = -1;
	int i;

	int skip = cal_skip(size);

	while (++stage < size) //pyramid stages
	{
		i = -1;
		
		while (++i < height) //each row
		{
			int w = -1;
			while (++w < skip)
			{
				ft_putchar(' ');
			}
			ft_putchar('/');
			int l = -1;
			while (++l < width)
			{
				if (stage == size - 1)
				{
					if (size < 4 && i == height - 1 && l == width / 2)
					{
						ft_putchar('|');
						continue;
					}
					if (size == 4 && i > height - 4 && (l > (width / 2) - 2 && l < (width / 2) + 2) )
					{
						ft_putchar('|');
						continue;
					}
					if (size > 4 && i > height - 6 && (l > (width / 2) - 3 && l < (width / 2) + 3) )
					{
						ft_putchar('|');
						continue;
					}
				}
				ft_putchar('*');
			}
			ft_putchar('\\');
			ft_putchar('\n');
			width += 2;
			--skip;
		}

		width += 4;
		skip -= 2;
		i = 1;
		while (++i < stage)
		{
			width+=2;
			skip -= 1;
		}
		++height;
	}

}


int main(void)
{
	sastantua(4);
	return(0);
}
