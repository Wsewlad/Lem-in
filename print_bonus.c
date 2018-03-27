/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:32:24 by vfil              #+#    #+#             */
/*   Updated: 2018/03/26 14:32:25 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_data(t_data *data)
{
	int i;

	i = 0;
	ft_printf("-----------\n{grn}Ants:{eoc} %d\n-----------\n", data->ants);
	ft_printf("{grn}Rooms:{eoc} %d\n", data->r_nb);
	while (i < data->r_nb)
	{
		ft_printf("{gry}Room{eoc} %d name: %s, x: %d, y: %d, type: %c\n", i, \
		data->rooms[i].name, data->rooms[i].x, data->rooms[i].y, \
		data->rooms[i].type);
		i++;
	}
	ft_printf("\n{grn}Links:{eoc} %d:\n", data->l_nb);
	i = 0;
	while (i < data->l_nb)
	{
		ft_printf("{mag}Link %d{eoc} {cyn}names:{eoc}  %s - %s, ", i + 1, \
		data->rooms[data->links[i].r1].name, \
		data->rooms[data->links[i].r2].name);
		ft_printf("{cyn}indexes:{eoc} %d - %d, {cyn}types:{eoc} %c - %c\n", \
		data->links[i].r1, data->links[i].r2, \
		data->links[i].r1_t, data->links[i].r2_t);
		i++;
	}
	ft_printf("\n");
}

void 	print_roads(t_data data, t_road	*roads)
{
	t_road	*current;
	t_step	*stp;
	int i;

	current = roads;
	i = 1;
	while (current)
	{
		ft_printf("{grn}Road %d:{eoc}    ", i);
		stp = current->step;
		while (stp)
		{
			if (data.rooms[stp->r].type == 'e')
			{
				if (stp->ant > 0 && stp->ant <= data.ants)
					ft_printf("%s {yel}L%d{eoc} | {blu}len: %d{eoc}", \
					data.rooms[stp->r].name, stp->ant, current->steps);
				else
					ft_printf("%s {blu}L%d{eoc} | {blu}len: %d{eoc}", \
					data.rooms[stp->r].name, stp->ant, current->steps);
			}
			else
			{
				if (stp->ant > 0 && stp->ant <= data.ants)
					ft_printf("%s {yel}L%d{eoc} {blu}->{eoc} ", \
					data.rooms[stp->r].name, stp->ant);
				else
					ft_printf("%s {blu}L%d{eoc} {blu}->{eoc} ", \
					data.rooms[stp->r].name, stp->ant);
			}
			stp = stp->next;
		}
		ft_printf("\n");
		current = current->next;
		i++;
	}
	ft_printf("\n");
}

void 	print_roads_arr(t_data data, t_stepi **roadsi, t_road *roads)
{
	int i;
	int j;

	i = 0;
	ft_printf("\n");
	while (i < data.bst_rd)
	{
		ft_printf("{grn}Road %d:{eoc}    ", i);
		j = 1;
		while (j < roads->steps)
		{
			if (data.rooms[roadsi[i][j].r].type == 'e')
			{
				if (roadsi[i][j].ant > 0 && roadsi[i][j].ant <= data.ants)
					ft_printf("{yel}L%d{eoc} %s | {blu}len: %d{eoc}", roadsi[i][j].ant, data.rooms[roadsi[i][j].r].name, \
				roads->steps);
				else
					ft_printf("{blu}L%d{eoc} %s | {blu}len: %d{eoc}", roadsi[i][j].ant, data.rooms[roadsi[i][j].r].name, \
				roads->steps);
			}
			else
			{
				if (roadsi[i][j].ant > 0 && roadsi[i][j].ant <= data.ants)
					ft_printf("{yel}L%d{eoc} %s {blu}->{eoc} ", roadsi[i][j].ant, data.rooms[roadsi[i][j].r].name);
				else
					ft_printf("{blu}L%d{eoc} %s {blu}->{eoc} ", roadsi[i][j].ant, data.rooms[roadsi[i][j].r].name);
			}
			j++;
		}
		ft_printf("\n");
		roads = roads->next;
		i++;
	}
}
