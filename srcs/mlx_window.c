/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:01:18 by chbelan           #+#    #+#             */
/*   Updated: 2019/11/03 18:56:04 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	setup_window(t_elem *win)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, 1250, 1200, "Tchadingo fdf");
	mlx_expose_hook(win->win, drawing, &*win);
	mlx_key_hook(win->win, keyboard, &*win);
	mlx_loop(win->mlx);
}

void	gen_screen(t_elem *elem)
{
	short	i;
	short	j;

	i = 0;
	j = 0;
	while (i != 1201)
	{
		while (j != 1201)
		{
			mlx_pixel_put(elem->mlx, elem->win, i, j, BLACK);
			j++;
		}
		i++;
		j = 0;
	}
}

int		color(int value)
{
	if (value <= 0)
		return (WHITE);
	else if (value <= 10)
		return (BLUE);
	else
		return (GREEN);
}
