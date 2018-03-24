/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conductor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:00:43 by vfil              #+#    #+#             */
/*   Updated: 2018/03/23 15:00:44 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_stepi 	**lst2array(t_data data, t_road *roads)
{
	t_stepi	**roadsi;
	t_road	*rd;
	t_step	*stp;
	int		i;
	int 	j;

	i = 0;
	rd = roads;
	roadsi = (t_stepi**)malloc(sizeof(t_stepi*) * data.bst_rd);
	while (i < data.bst_rd)
	{
		roadsi[i] = (t_stepi*)malloc(sizeof(t_stepi) * rd->steps);
		stp = rd->step;
		j = 0;
		while (stp)
		{
			roadsi[i][j].r = stp->r;
			roadsi[i][j].ant = stp->ant;
			j++;
			stp = stp->next;
		}
		i++;
		rd = rd->next;
	}
	return (roadsi);
}

void	conductor(t_data data, t_road *roads)
{
	t_road	*rd;
	t_stepi	**roadsi;
	int 	i;
	int 	j;
	int 	ant;
	int 	k;

	ant = 1;
	k = 0;
	roadsi = lst2array(data, roads);
	while (k < 10)
	{
		i = 0;
		rd = roads;
		while (rd)
		{
			j = rd->steps - 1;
			while (j > 0)
			{
				roadsi[i][j].ant = j > 1 ? roadsi[i][j - 1].ant : ant;
				j--;
			}
			ant++;
			rd = rd->next;
			i++;
		}
		print_roads_arr(data, roadsi, roads);
		if (roadsi[data.bst_rd - 1][data.long_rd - 1].ant == data.ants)
			exit(1);
		ft_printf("\n");
		k++;
	}
}
