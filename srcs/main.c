/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:52:15 by chbelan           #+#    #+#             */
/*   Updated: 2019/11/03 18:41:11 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void __attribute__((destructor)) calledLast();

int			main(int argc, char **argv)
{
	t_elem	elem;

	program(argc, argv, elem);
	return (0);
}

void	calledLast()
{
	while (1)
		;
}