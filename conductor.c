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

void		go_ant(t_data data, t_road *roads, t_stepi **roadsi, int *ant)
{
	t_road	*rd;
	int		i;
	int		j;
	int		lant;

	i = 0;
	rd = roads;
	while (rd)
	{
		j = rd->steps - 1;
		while (j > 0)
		{
			lant = *ant <= data.ants ? *ant : 0;
			roadsi[i][j].ant = j > 1 ? roadsi[i][j - 1].ant : lant;
			j--;
		}
		(*ant)++;
		rd = rd->next;
		i++;
	}
}

void		conductor(t_data data, t_road *roads)
{
	t_stepi	**roadsi;
	int		ant;

	ant = 1;
	roadsi = lst2array(data, roads);
	while (1)
	{
		go_ant(data, roads, roadsi, &ant);
		is_last_ant_home(data, roadsi);
		//print_roads_arr(data, roadsi, roads);
		//ft_printf("\n");
		print_res(data, roadsi);
		ft_printf("\n");
	}
}

t_stepi		**lst2array(t_data data, t_road *roads)
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
	int j;
	int len;
	int ant;

	i = 0;
	ant = 0;
	while (i < data.bst_rd)
	{
		len = data.lns2[i];
		j = 0;
		while (j < len)
		{
			if (roadsi[i][j].ant)
				ant++;
			j++;
		}
		i++;
	}
	if (!ant)
		exit(1);
}
