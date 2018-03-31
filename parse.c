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

/*
** Validate input and save it in list
*/

t_list	*parse_map(t_data *data)
{
	t_list	*map;
	t_list	*lst;
	char	*line;
	int		is_ant;

	is_ant = 0;
	lst = NULL;
	if (get_next_line(0, &line) > 0)
	{
		line_ok(line, &is_ant, data);
		lst = ft_lstnew(line, ft_strlen(line));
		ft_strdel(&line);
	}
	else
		print_error("Not valid file", data);
	map = lst;
	while (get_next_line(0, &line) > 0)
	{
		line_ok(line, &is_ant, data);
		lst->next = ft_lstnew(line, ft_strlen(line) + 1);
		lst = lst->next;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (map);
}

t_list	*parse_room(t_list *map, t_data *data, char type, int *r)
{
	int		i;
	char	**splt;

	if (((char*)map->content)[0] != '#')
	{
		if (check_spdf(map, ' ') == 2)
		{
			i = 0;
			splt = ft_strsplit(map->content, ' ');
			while (splt[i])
				i++;
			if (i != 3 || !ft_isdigit(splt[1][0]) || !ft_isdigit(splt[2][0]))
				print_error("wrong room", data);
			data->rooms[*r].name = ft_strdup(splt[0]);
			data->rooms[*r].x = ft_atoi(splt[1]);
			data->rooms[*r].y = ft_atoi(splt[2]);
			data->rooms[*r].type = type;
			ft_arriter(splt, free);
			free(splt);
			(*r)++;
		}
	}
	return (map);
}

void	parse_rooms(t_list *map, t_data *data)
{
	int r;
	int se;

	se = 0;
	r = 0;
	while (map)
	{
		if (ft_strcmp(map->content, "##start") == 0 && ++se)
		{
			if ((map = map->next))
				parse_room(map, data, 's', &r);
		}
		else if (ft_strcmp(map->content, "##end") == 0 && ++se)
		{
			if ((map = map->next))
				parse_room(map, data, 'e', &r);
		}
		else
			parse_room(map, data, 'c', &r);
		if (map)
			map = map->next;
	}
	if (se != 2)
		print_error("Problem with ##start or ##end", data);
}

void	parse_links(t_list *map, t_data *data)
{
	char	**splt;
	int		l;

	l = 0;
	while (map)
	{
		if (((char*)map->content)[0] != '#')
		{
			if (check_spdf(map, '-') == 1)
			{
				splt = ft_strsplit(map->content, '-');
				if (!check_links_identity(data, l, \
				check_rindex(data, splt[0]), check_rindex(data, splt[1])))
					parse_links_helper(data, splt, &l);
				ft_arriter(splt, free);
				free(splt);
			}
		}
		map = map->next;
	}
}

void	parse_data(t_data *data, t_list **map)
{
	*map = parse_map(data);
	count_ants(*map, data);
	count_rooms(*map, data);
	count_links(*map, data);
	parse_rooms(*map, data);
	check_es_room(data);
	check_room_identity(data);
	parse_links(*map, data);
}
