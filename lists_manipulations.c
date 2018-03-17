/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_manipulations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 16:54:14 by vfil              #+#    #+#             */
/*   Updated: 2018/03/17 16:54:16 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_step	*new_step(int room)
{
	t_step	*new;

	new = (t_step*)malloc(sizeof(t_step));
	new->r = room;
	new->next = NULL;
	return (new);
}

void	step_append(t_step *head, t_step *new)
{
	t_step	*current;

	current = head;
	while (current->next)
		current = current->next;
	current->next = new;
}

t_road	*new_road(void)
{
	t_road	*new;

	new = (t_road*)malloc(sizeof(t_road));
	new->steps = 0;
	new->step = NULL;
	new->next = NULL;
	return (new);
}

void	road_append(t_road *head, t_road *new)
{
	t_road	*current;

	current = head;
	while (current->next)
		current = current->next;
	current->next = new;
}

t_road	*copy_road(t_road *road)
{
	t_road	*new;
	t_step	*stp;

	new	= (t_road*)malloc(sizeof(t_road));
	new->steps = 0;
	stp = road->step;
	new->step = new_step(stp->r);
	stp = stp->next;
	while (stp)
	{
		step_append(new->step, new_step(stp->r));
		stp = stp->next;
	}
	new->next = NULL;
	return (new);
}