/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:10:00 by vfil              #+#    #+#             */
/*   Updated: 2018/03/30 13:10:01 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		print_help(int is_exit)
{
	ft_printf("Usage:\n\n%C  ./lem-in -d -h OR ./lem-in -dh\n\n", L'🐜');
	ft_printf("\t-h\tprint help info\n");
	ft_printf("\t-d\tdebug mode\n");
	ft_printf("\t-a\tprint all found roads\n");
	ft_printf("\t-b\tprint 'best' roads that haven't intersections\n");
	ft_printf("\t-s\tshow detail ants %C  moving\n", L'🐜');
	ft_printf("\t-v\tvisualize ants %C  moving\n", L'🐜');
	ft_printf("\t-f\tinitialize all flags\n\n");
	if (is_exit)
		exit(1);
}

static void	init2int(t_data *data, int i)
{
	data->flag.d = i;
	data->flag.h = i;
	data->flag.a = i;
	data->flag.b = i;
	data->flag.s = i;
}

static void	check_flags(char c, t_data *data)
{
	if (c == 'd')
		data->flag.d = 1;
	else if (c == 'h')
		data->flag.h = 1;
	else if (c == 'a')
		data->flag.a = 1;
	else if (c == 'b')
		data->flag.b = 1;
	else if (c == 's')
		data->flag.s = 1;
	else if (c == 'v')
		data->flag.v = 1;
	else if (c == 'f')
	{
		init2int(data, 1);
		print_help(0);
	}
}

void		init_flags(int ac, char **av, t_data *data)
{
	int i;
	int j;

	data->flag.v = 0;
	init2int(data, 0);
	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][0] == '-')
		{
			if (!av[i][1])
				print_help(1);
			while (av[i][j])
			{
				check_flags(av[i][j], data);
				j++;
			}
		}
		else
			print_help(1);
		i++;
	}
}

void		parse_links_helper(t_data *data, char **splt, int *l)
{
	data->links[*l].r1 = check_rindex(data, splt[0]);
	data->links[*l].r1_t = data->rooms[data->links[*l].r1].type;
	data->links[*l].r2 = check_rindex(data, splt[1]);
	data->links[*l].r2_t = data->rooms[data->links[*l].r2].type;
	(*l)++;
}
