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
		if (((char*)map->content)[i] < 48 || ((char*)map->content)[i] > 57)
			print_error(map->content);
		i++;
	}
	data->ants = ft_atoi(map->content);
}

void	check_spdf(t_list *map,char c, int *d)
{
	int i;

	i = 0;
	while (((char*)map->content)[i])
	{
		if (((char*)map->content)[i] == c)
			(*d)++;
		if ((!ft_isdigit(((char*)map->content)[i])) && \
				((char*)map->content)[i] != c && \
				((char*)map->content)[i] != (c == ' ' ? '-' : ' '))
			print_error(map->content);
		i++;
	}
}

void	count_rooms(t_list *map, t_data *data)
{
	int sp;

	map = map->next;
	data->r_nb = 0;
	while (map)
	{
		sp = 0;
		if (((char*)map->content)[0] != '#')
		{
			check_spdf(map, ' ', &sp);
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
		df = 0;
		if (((char*)map->content)[0] != '#')
		{
			check_spdf(map, '-', &df);
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
