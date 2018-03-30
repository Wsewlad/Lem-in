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

static void	count_symb(char *line, int *sp, int *df, int *chr)
{
	while (*line)
	{
		if (*line == ' ')
			(*sp)++;
		else if (*line == '-')
			(*df)++;
		else if (!ft_isdigit(*line))
			(*chr)++;
		line++;
	}
}

/*
** Check line (not empty, not start with 'L', not more
** then 1 '-' and 2 ' ')
*/

void		line_ok(char *line, int *is_ant, t_data *data)
{
	int		sp;
	int		df;
	char	*str;
	int		chr;

	chr = 0;
	sp = 0;
	df = 0;
	str = line;
	if (!(*line) || *line == 'L')
		print_error(line, data);
	if (*line == '#')
		return ;
	count_symb(line, &sp, &df, &chr);
	if (!*is_ant && !sp && !df && !chr)
	{
		*is_ant = 1;
		return ;
	}
	if (!sp && !df)
		print_error(str, data);
}

/*
** Check if room's name and coordinates identity
*/

void		check_room_identity(t_data *data)
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
					print_error(data->rooms[j].name, data);
				if (data->rooms[i].x == data->rooms[j].x && \
				data->rooms[i].y == data->rooms[j].y)
					print_error(data->rooms[j].name, data);
			}
			j++;
		}
		i++;
	}
}

/*
** Check end, start rooms identity
*/

void		check_es_room(t_data *data)
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
		print_error("Problem with start room", data);
	if (e != 1)
		print_error("Problem with end room", data);
}

int			check_links_identity(t_data *data, int l, int r1, int r2)
{
	int i;

	i = 0;
	if (r1 == r2)
	{
		data->l_nb--;
		return (1);
	}
	while (i < l)
	{
		if (data->links[i].r1 == r1 && data->links[i].r2 == r2)
		{
			data->l_nb--;
			return (1);
		}
		if (data->links[i].r1 == r2 && data->links[i].r2 == r1)
		{
			data->l_nb--;
			return (1);
		}
		i++;
	}
	return (0);
}
