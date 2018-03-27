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

int main(void)
{
	t_data	data;
	t_road	*roads;
	t_road	*current;

	parse_data(&data);
	current = new_road();
	current->step = new_step(find_start(data));
	roads = current;
	find_roads(data, &roads, current, find_start(data));
	count_steps(roads, &data);
	ft_printf("{blu}All roads:{eoc}\n");
	print_roads(data, roads);
	find_best_roads(&roads);
	count_steps(roads, &data);
	check_rdlns(roads, &data);
	//ft_printf("{red}Best roads (%d):{eoc}\n", data.bst_rd);
	//print_roads(data, roads);
	//ft_printf("-----------------------\n");
	conductor(data, roads);
	return 0;
}
