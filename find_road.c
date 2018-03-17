/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_road.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:48:15 by vfil              #+#    #+#             */
/*   Updated: 2018/03/16 14:48:17 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int 	find_start(t_data data)
{
	int i;

	i = 0;
	while (data.rooms[i].type != 's')
		i++;
	return (i);
}

void	find_roads(t_data data, t_road *roads, t_road *current, int start)
{
	int		i;
	t_link	*links;

	links = data.links;
	i = 0;
	while (i < data.l_nb && data.rooms[start].type != 'e')
	{
		if (!links[i].status && (links[i].r1 == start || \
		links[i].r2 == start))
		{
			current = copy_road(current);
			road_append(roads, current);
			start = links[i].r1 == start ? links[i].r2 : links[i].r1;
			step_append(current->step, new_step(start));
			links[i].status = 1;
			find_roads(data, roads, current, start);
		}
		i++;
	}
}


