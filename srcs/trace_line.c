/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:08:38 by chbelan           #+#    #+#             */
/*   Updated: 2019/11/03 18:30:49 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			trace_line(t_pos *v0, t_pos *v1, t_elem *elem)
{
	t_cor t;

	t.dx = ft_abs(v1->x - v0->x);
	t.sx = v0->x < v1->x ? 1 : -1;
	t.dy = ft_abs(v1->y - v0->y);
	t.sy = v0->y < v1->y ? 1 : -1;
	t.fault = (t.dx > t.dy ? t.dx : -t.dy) / 2;
	while (42)
	{
		mlx_pixel_put(elem->mlx, elem->win, v0->x, v0->y, elem->color);
		if (v0->x == v1->x && v0->y == v1->y)
			break ;
		t.value = t.fault;
		if (t.value > -t.dx)
		{
			t.fault -= t.dy;
			v0->x += t.sx;
		}
		if (t.value < t.dy)
		{
			t.fault += t.dx;
			v0->y += t.sy;
		}
	}
}

int				drawing(t_elem *elem)
{
	int			value;
	t_trace		trace;

	value = 0;
	gen_screen(elem);
	while (value <= 3)
	{
		trace.i = 0;
		trace.k = 0;
		trace.x = elem->basex;
		trace.y = elem->basey;
		select_axes(value, elem, 200, &trace);
		value += 1;
	}
	text_window(elem);
	return (0);
}
