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
		if (!(*line))
			print_error(line);
		lst = ft_lstnew(line, ft_strlen(line));
		ft_strdel(&line);
	}
	map = lst;
	while (get_next_line(0, &line) > 0)
	{
		line_ok(line);
		lst->next = ft_lstnew(line, ft_strlen(line) + 1);
		lst = lst->next;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (map);
}

t_list	*parse_room(t_list *map, t_data *data, char type, int *r)
{
	int	sp;
	char **splt;

	if (((char*)map->content)[0] != '#')
	{
		sp = check_spdf(map, ' ');
		if (sp == 2)
		{
			sp = 0;
			splt = ft_strsplit(map->content, ' ');
			while (splt[sp])
				sp++;
			if (sp != 3 || !ft_isdigit(splt[1][0]) || !ft_isdigit(splt[2][0]))
				print_error("wrong room");
			data->rooms[*r].name = ft_strdup(splt[0]);
			data->rooms[*r].x = ft_atoi(splt[1]);
			data->rooms[*r].y = ft_atoi(splt[2]);
			data->rooms[*r].type = type;
			ft_arriter(splt, free);
			free(splt);
			(*r)++;
		}
	}
	return(map);
}

void	parse_rooms(t_list *map, t_data *data)
{
	int r;

	r = 0;
	while (map)
	{
		if (ft_strcmp(map->content, "##start") == 0)
		{
			map = map->next;
			parse_room(map, data, 's', &r);
		}
		else if (ft_strcmp(map->content, "##end") == 0)
		{
			map = map->next;
			parse_room(map, data, 'e', &r);
		}
		else
			parse_room(map, data, 'c', &r);
		map = map->next;
	}
}

void	parse_links(t_list *map, t_data *data)
{
	int	df;
	char **splt;
	int l;

	l = 0;
	while (map)
	{
		if (((char*)map->content)[0] != '#')
		{
			df = check_spdf(map, '-');
			if (df == 1)
			{
				splt = ft_strsplit(map->content, '-');
				data->links[l].r1 = check_rindex(data, splt[0]);
				data->links[l].r1_t = data->rooms[data->links[l].r1].type;
				data->links[l].r2 = check_rindex(data, splt[1]);
				data->links[l].r2_t = data->rooms[data->links[l].r2].type;
				ft_arriter(splt, free);
				free(splt);
				l++;
			}
		}
		map = map->next;
	}
}

void	parse_data(t_data *data, t_list **map)
{
	*map = parse_map();
	count_ants(*map, data);
	count_rooms(*map, data);
	count_links(*map, data);
	parse_rooms(*map, data);
	check_es_room(data);
	check_room_identity(data);
	parse_links(*map, data);
}
