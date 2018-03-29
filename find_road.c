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

/*
** Find all roads
*/

void	find_roads(t_data data, t_road **roads, t_road *current, int start)
{
	int		i;
	int		nw;

	while (current)
	{
		i = 0;
		data.rooms[start].type = \
		(char)(data.rooms[start].type != 'e' ? 'v' : 'e');
		while (i < data.l_nb && data.rooms[start].type != 'e')
		{
			if ((data.links[i].r1 == start || data.links[i].r2 == start))
			{
				nw = data.links[i].r1 == start ? data.links[i].r2 : \
				data.links[i].r1;
				if (data.rooms[nw].type != 'v')
					add_extended_road(current, nw);
			}
			i++;
		}
		del_not_full(data, roads, &current);
		find_last_stp(current, &start);
	}
}

void	add_extended_road(t_road *current, int nw)
{
	t_road	*new;

	new = copy_road(current);
	step_append(new->step, new_step(nw));
	road_append(current, new);
}

/*
** Delete all not completed roads and relink list of roads
*/

void	del_not_full(t_data data, t_road **head, t_road **current)
{
	int		last;
	int		nxt;
	t_road	*lst;

	find_last_stp(*current, &last);
	if (data.rooms[last].type != 'e')
	{
		if (*head == *current)
		{
			lst = (*head)->next;
			if (!lst)
				print_error("No full roads!", &data);
			del_road(head);
			*head = lst;
			*current = *head;
			return ;
		}
		del_rd(head, current, &nxt);
	}
	else
		*current = (*current)->next;
}

/*
** Delete road
*/

void	del_road(t_road **road)
{
	t_step	*stp;

	if (*road)
	{
		while ((*road)->step)
		{
			stp = (*road)->step->next;
			free((*road)->step);
			(*road)->step = stp;
		}
		free(*road);
		*road = NULL;
	}
}

/*
** Find last room index in road
*/

void	find_last_stp(t_road *current, int *start)
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
