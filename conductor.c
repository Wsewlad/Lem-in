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

void	conductor(t_data data, t_road *roads)
{
	t_road	*rd;
	t_stepi	**roadsi;
	int 	i;
	int 	j;
	int 	ant;
	int 	k;

	ant = 1;
	roadsi = lst2array(data, roads);
	if (data.bst_rd > 1)
		k = data.ants + data.bst_rd - (data.lng_rd - 1);
	else
		k = data.ants + (data.lng_rd - 1);
	ft_printf("{mag}k = %d{eoc}\n", k);
	while (k)
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
		ft_printf("\n");
		print_res(data, roadsi);
		ft_printf("\n");
		k--;
		//is_last_ant_home(data, roadsi);
	}
}

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

void		is_last_ant_home(t_data data, t_stepi **roadsi)
{
	int i;

	i = 0;
	while (i < data.bst_rd - 1)
	{
		if (roadsi[i][data.lns2[i]].ant == data.ants)
			exit(1);
		i++;
	}
}

