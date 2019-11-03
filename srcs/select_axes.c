/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_axes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 20:25:21 by chbelan           #+#    #+#             */
/*   Updated: 2019/11/03 18:26:21 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			select_axes(int value, t_elem *elem, int i, t_trace *s)
{
	if (value == 0)
		gen_x_axes_mid(elem, i, elem->lenght, s);
	if (value == 1)
		gen_x_axes_top(elem, i, elem->lenght, s);
	if (value == 2)
		gen_y_axes_mid(elem, i, elem->lenght, s);
	if (value == 3)
		gen_y_axes_top(elem, i, elem->lenght, s);
}
