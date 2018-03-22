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

int 	check_intersection(t_road *prev, t_road *current)
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
			{
				ft_printf("%d\n", stp->r);
				return (1);
			}
			stp2 = stp2->next;
		}
		stp = stp->next;
	}
	return (0);
}

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

void 	find_best_roads(t_road **roads)
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
					break;
				}
				prev = prev->next;
			}
			if (!nxt)
				current = current->next;
		}
	}
}
