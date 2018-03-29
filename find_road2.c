/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_road2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 19:43:05 by vfil              #+#    #+#             */
/*   Updated: 2018/03/29 19:43:07 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Find room with type "start" and return it index
*/

int		find_start(t_data data)
{
	int	i;

	i = 0;
	while (i < data.r_nb && data.rooms[i].type != 's')
		i++;
	if (i == data.r_nb)
		print_error("No start room", &data);
	return (i);
}
