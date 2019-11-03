/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:44:39 by chbelan           #+#    #+#             */
/*   Updated: 2019/11/03 17:51:10 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_exit(char *str)
{
	ft_putstr(str);
	exit(-1);
}

void	print_board(int **tab, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i != x)
	{
		j = 0;
		while (j != x)
		{
			ft_putnbr(tab[i][j]);
			ft_putstr("  ");
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}
