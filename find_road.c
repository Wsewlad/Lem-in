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

void 	find_last_stp(t_road *current, int *start)
{
	t_step	*stp;

	if (current)
	{
		stp = current->step;
		while (stp->next)
			stp = stp->next;
		*start = stp->r;
	}
}

void	find_roads(t_data data, t_road *roads, t_road *current, int start)
{
	int		i;
	t_road	*new;
	int		nw;

	current = roads;
	data.rooms[start].type = 'v';
	while (current)
	{
		i = 0;
		while (i < data.l_nb && data.rooms[start].type != 'e')
		{
			if ((data.links[i].r1 == start || data.links[i].r2 == start))
			{
				nw = data.links[i].r1 == start ? data.links[i].r2 : data.links[i].r1;
				if (data.rooms[nw].type != 'v')
				{
					new = copy_road(current);
					step_append(new->step, new_step(nw));
					road_append(current, new);
					data.rooms[nw].type = data.rooms[nw].type != 'e' ? 'v' : 'e';
				}
			}
			i++;
		}
		current = current->next;
		find_last_stp(current, &start);
	}
}


