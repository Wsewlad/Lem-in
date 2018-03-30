/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:51:41 by vfil              #+#    #+#             */
/*   Updated: 2018/03/13 17:51:43 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_list	*map;
	t_road	*roads;
	t_road	*current;

	setlocale(LC_ALL, "");
	init_flags(argc, argv, &data);
	map = NULL;
	parse_data(&data, &map);
	current = new_road();
	current->step = new_step(find_start(data));
	roads = current;
	find_roads(data, &roads, current, find_start(data));
	count_steps(roads, &data);
	print_from_nain(&data, roads, map, 1);
	find_best_roads(&roads);
	count_steps(roads, &data);
	check_rdlns(roads, &data);
	print_from_nain(&data, roads, map, 2);
	conductor(data, roads);
	return (0);
}
