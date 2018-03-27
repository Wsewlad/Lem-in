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

void		print_map(t_list *map)
{
	t_list	*buf;

	while (map)
	{
		ft_printf("%s\n", map->content);
		free(map->content);
		buf = map->next;
		free(map);
		map = buf;
	}
	ft_printf("\n");
}

void		print_error(char *str)
{
	ft_printf("{red}ERROR: '%s'{eoc}\n", str);
	/*str = NULL;
	ft_printf("ERROR\n");*/
	exit(1);
}


static void	check_last_ant(t_data *data, t_stepi **roadsi, int i, int *in)
{
	int	rd_len;

	rd_len = data->lns[i] - 1;
	while (rd_len > 0)
	{
		if (roadsi[i][rd_len].ant > 0 && roadsi[i][rd_len].ant <= data->ants)
		{
			if (*in)
				ft_printf(" ");
			ft_printf("L%d-%s", roadsi[i][rd_len].ant, \
			data->rooms[roadsi[i][rd_len].r].name);
			*in = 1;
			return ;
		}
		rd_len--;
		data->lns[i]--;
	}
}

void	print_res(t_data data, t_stepi **roadsi)
{
	int i;
	int in;

	i = 0;
	in = 0;
	while (i < data.bst_rd)
	{
		data.lns[i] = data.lns2[i];
		i++;
	}
	while (1)
	{
		i = 0;
		while (i < data.bst_rd)
		{
			check_last_ant(&data, roadsi, i, &in);
			data.lns[i]--;
			i++;
		}
		if (!data.lns[data.bst_rd - 1])
			return ;
	}
}
