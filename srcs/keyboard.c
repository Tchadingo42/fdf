/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 12:55:45 by chbelan           #+#    #+#             */
/*   Updated: 2019/11/03 18:25:22 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		key_map(int key, t_elem *elem)
{
	if (key == ESC)
		ft_exit("end program \n");
	else if (key == RIGHT)
		elem->basex += 75;
	else if (key == LEFT)
		elem->basex -= 50;
	else
		return ;
	drawing(elem);
}

int			keyboard(int key, t_elem *elem)
{
	key_map(key, elem);
	return (0);
}
