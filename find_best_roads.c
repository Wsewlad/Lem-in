/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_roads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 20:14:10 by vfil              #+#    #+#             */
/*   Updated: 2018/03/21 20:14:14 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Check if roads have intersection
*/

int		check_intersection(t_road *prev, t_road *current)
{
	t_step	*stp;
	t_step	*stp2;

	stp = prev->step->next;
	while (stp->next)
	{
		stp2 = current->step->next;
		while (stp2->next)
		{
			if (stp->r == stp2->r)
				return (1);
			stp2 = stp2->next;
		}
		stp = stp->next;
	}
	return (0);
}

/*
** Delete current road and relink list
*/

void	del_rd(t_road **head, t_road **current, int *nxt)
{
	t_road	*lst;

	lst = *head;
	while (lst->next && lst->next != *current)
		lst = lst->next;
	if (lst->next)
		lst->next = lst->next->next;
	del_road(current);
	*current = lst->next;
	*nxt = 1;
}

/*
** Find roads that haven't intersections
*/

void	find_best_roads(t_road **roads)
{
	t_road	*current;
	t_road	*prev;
	int		nxt;

	if ((*roads)->next)
	{
		prev = *roads;
		current = (*roads)->next;
		while (current)
		{
			nxt = 0;
			while (prev != current)
			{
				if (check_intersection(prev, current))
				{
					del_rd(roads, &current, &nxt);
					break ;
				}
				prev = prev->next;
			}
			if (!nxt)
				current = current->next;
		}
	}
}

/*
** Count steps (rooms) in road and find longest one
*/

void	count_steps(t_road *roads, t_data *data)
{
	t_road	*current;
	t_step	*stp;

	current = roads;
	data->bst_rd = 0;
	while (current)
	{
		stp = current->step;
		current->steps = 0;
		while (stp)
		{
			current->steps++;
			stp->ant = 0;
			stp = stp->next;
		}
		data->bst_rd++;
		current = current->next;
	}
}

/*
** Check length of all roads and save it in array of ints
*/

void	check_rdlns(t_road *roads, t_data *data)
{
	t_road	*rd;
	int		i;

	data->lns = (int*)malloc(sizeof(int) * data->bst_rd);
	data->lns2 = (int*)malloc(sizeof(int) * data->bst_rd);
	rd = roads;
	i = 0;
	while (rd)
	{
		data->lns[i] = rd->steps;
		data->lns2[i] = rd->steps;
		i++;
		rd = rd->next;
	}
}
