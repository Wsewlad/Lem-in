/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:26:00 by vfil              #+#    #+#             */
/*   Updated: 2018/03/15 16:26:02 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	count_ants(t_list *map, t_data *data)
{
	int	i;

	i = 0;
	while (((char*)map->content)[i])
	{
		if (!ft_isdigit(((char*)map->content)[i]))
			print_error(map->content);
		i++;
	}
	if (i > 9)
		print_error(map->content);
	data->ants = ft_atoi(map->content);
	if (data->ants <= 0)
		print_error(map->content);
}

int	check_spdf(t_list *map, char c)
{
	int i;
	int d;

	i = 0;
	d = 0;
	while (((char*)map->content)[i])
	{
		if (((char*)map->content)[i] == c)
			d++;
		i++;
	}
	return (d);
}

void	count_rooms(t_list *map, t_data *data)
{
	int sp;

	map = map->next;
	data->r_nb = 0;
	while (map)
	{
		if (((char*)map->content)[0] != '#')
		{
			sp = check_spdf(map, ' ');
			if (sp == 2)
				data->r_nb++;
			else if (sp)
				print_error(map->content);
		}
		map = map->next;
	}
	if (data->r_nb)
		data->rooms = (t_room*)malloc(sizeof(t_room) * data->r_nb);
	else
		print_error("0 rooms");
}

void	count_links(t_list *map, t_data *data)
{
	int df;

	map = map->next;
	data->l_nb = 0;
	while (map)
	{
		if (((char*)map->content)[0] != '#')
		{
			df = check_spdf(map, '-');
			if (df == 1)
				data->l_nb++;
			else if (df > 1)
				print_error(map->content);
		}
		map = map->next;
	}
	if (data->l_nb)
		data->links = (t_link*)malloc(sizeof(t_link) * data->l_nb);
	else
		print_error("0 links");
}

int 	check_rindex(t_data *data, char *name)
{
	int i;

	i = 0;
	while (i < data->r_nb && ft_strcmp(data->rooms[i].name, name) != 0)
		i++;
	if (i == data->r_nb)
	{
		ft_printf("{red}Wrong link, non-existent room!{eoc}\n");
		print_error(name);
	}
	return (i);
}