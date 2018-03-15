/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:13:46 by vfil              #+#    #+#             */
/*   Updated: 2018/03/13 17:13:48 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_list *parse_map(void)
{
	t_list	*map;
	t_list	*lst;
	char 	*line;

	lst = NULL;
	if (get_next_line(0, &line) > 0)
	{
		lst = ft_lstnew(line, ft_strlen(line));
		ft_strdel(&line);
	}
	map = lst;
	while (get_next_line(0, &line) > 0)
	{
		lst->next = ft_lstnew(line, ft_strlen(line) + 1);
		lst = lst->next;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (map);
}

void	parse_room(t_list *map, t_data *data, int type, int *r)
{

}

void	parse_rooms(t_list *map, t_data *data)
{
	int sp;
	int r;

	r = 0;
	while (map)
	{
		sp = 0;
		if (((char*)map->content)[0] != '#')
		{
			check_spdf(map, ' ', &sp);
			if (sp == 2)
				parse_room(map, data, 0, &r);
		}
		else if (ft_strcmp(map->content, "##start") == 0)
		{
			map = map->next;
			if (((char*)map->content)[0] != '#')
			{
				check_spdf(map, ' ', &sp);
				if (sp == 2)
					parse_room(map, data, 0, &r);
			}
		}
		else if (ft_strcmp(map->content, "##end") == 0)
		{
			map = map->next;
			if (((char*)map->content)[0] != '#')
			{
				check_spdf(map, ' ', &sp);
				if (sp == 2)
					parse_room(map, data, 2, &r);
			}
		}
		map = map->next;
	}
}


void	parse_data(t_data *data)
{
	t_list *map;
	map = parse_map();
	count_ants(map, data);
	count_rooms(map, data);
	count_links(map, data);
	ft_printf("ants: %d\n", data->ants);
	ft_printf("rooms: %d\n", data->r_nb);
	ft_printf("links: %d\n", data->l_nb);
	print_map(map);
}
