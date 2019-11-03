/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:06:57 by chbelan           #+#    #+#             */
/*   Updated: 2019/11/03 18:26:38 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	text_window(t_elem *elem)
{
	mlx_string_put(elem->mlx, elem->win, 20, 25, WHITE, elem->name);
	mlx_string_put(elem->mlx, elem->win, 20, 40, WHITE, "ECS == EXIT");
}
