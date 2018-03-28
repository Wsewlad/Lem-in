/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:56:03 by vfil              #+#    #+#             */
/*   Updated: 2018/03/28 15:56:04 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void line_ok(char *line)
{
	int		sp;
	int		df;
	char	*str;

	sp = 0;
	df = 0;
	str = line;
	if (!(*line) || *line == 'L')
		print_error(line);
	if (line[2] &&  line[2] == '#')
		print_error(str);
	if (*line == '#')
		return ;
	while (*line)
	{
		if (*line == ' ')
			sp++;
		else if (*line == '-')
			df++;
		line++;
	}
	if (!sp && !df)
		print_error(str);
}

void	check_room_identity(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->r_nb)
	{
		j = 0;
		while (j < data->r_nb)
		{
			if (i != j)
			{
				if (ft_strcmp(data->rooms[i].name, data->rooms[j].name) == 0)
					print_error(data->rooms[j].name);
				if (data->rooms[i].x == data->rooms[j].x && \
				data->rooms[i].y == data->rooms[j].y)
					print_error(data->rooms[j].name);
				if ((data->rooms[i].type == 's' || data->rooms[i].type == 'e') \
					&& data->rooms[i].type == data->rooms[j].type)
					print_error(data->rooms[j].name);
			}
			j++;
		}
		i++;
	}
}

void	check_es_room(t_data *data)
{
	int i;
	int s;
	int e;

	i = 0;
	s = 0;
	e = 0;
	while (i < data->r_nb)
	{
		if (data->rooms[i].type == 's')
			s++;
		else if (data->rooms[i].type == 'e')
			e++;
		i++;
	}
	if (s != 1)
		print_error("Problem with start room");
	if (e != 1)
		print_error("Problem with end room");
	i = -1;
	while (++i < data->l_nb)
	{
		if (data->links[i].r1 == data->links[i].r2)
			print_error("Link to the same room");
	}
}
