/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:29:04 by vfil              #+#    #+#             */
/*   Updated: 2018/03/15 16:29:05 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_map(t_list *map)
{
	while (map)
	{
		ft_printf("%s\n", map->content);
		map = map->next;
	}
}

void	print_error(char *str)
{
	ft_printf("{red}ERROR: '%s'{eoc}\n", str);
	exit(1);
}

void	print_data(t_data *data)
{
	int i;

	i = 0;
	ft_printf("\n\n");
	ft_printf("ants: %d\n", data->ants);
	ft_printf("rooms: %d\n", data->r_nb);
	ft_printf("links: %d\n\n", data->l_nb);
	while (i < data->r_nb)
	{
		ft_printf("Room %d: name = %s, x = %d, y = %d, type = %c\n", i, \
		data->rooms[i].name, data->rooms[i].x, data->rooms[i].y, data->rooms[i].type);
		i++;
	}
	ft_printf("\n");
	i = 0;
	while (i < data->l_nb)
	{
		ft_printf("%d - %d, t: %c - %c\n", data->links[i].r1, data->links[i].r2, \
		data->links[i].r1_t, data->links[i].r2_t);
		/*ft_printf("Link %d: %s - %s\n", i, data->rooms[data->links[i].r1].name, \
		data->rooms[data->links[i].r2].name);*/
		i++;
	}
}

void 	print_roads(t_road	*roads)
{
	t_road	*current;
	t_step	*stp;
	int i;

	current = roads;
	i = 1;
	while (current)
	{
		ft_printf("Road %d: ", i);
		stp = current->step;
		while (stp)
		{
			ft_printf("%d -> ", stp->r);
			stp = stp->next;
		}
		ft_printf("\n");
		current = current->next;
		i++;
	}
}
