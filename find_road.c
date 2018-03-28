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

void	find_roads(t_data data, t_road **roads, t_road *current, int start)
{
	int		i;
	t_road	*new;
	int		nw;

	while (current)
	{
		i = 0;
		data.rooms[start].type = (char)(data.rooms[start].type != 'e' ? 'v' : 'e');
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
				}
			}
			i++;
		}
		del_not_full(data, roads, &current);
		find_last_stp(current, &start);
	}
}

int 	find_start(t_data data)
{
	int i;

	i = 0;
	while (i < data.r_nb && data.rooms[i].type != 's')
		i++;
	if (i == data.r_nb)
		print_error("No start room");
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

void	del_not_full(t_data data, t_road **head, t_road **current)
{
	int 	last;
	t_road	*lst;

	find_last_stp(*current, &last);
	if (data.rooms[last].type != 'e')
	{
		if (*head == *current)
		{

			lst = (*head)->next;
			if (!lst)
				print_error("No full roads!");
			del_road(head);
			*head = lst;
			*current = *head;
			return ;
		}
		lst = *head;
		while (lst->next && lst->next != *current)
			lst = lst->next;
		if (lst->next)
			lst->next = lst->next->next;
		del_road(current);
		*current = lst->next;
	}
	else
		*current = (*current)->next;
}
