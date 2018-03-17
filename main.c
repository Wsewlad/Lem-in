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

	parse_data(&data);
	roads = new_road();
	roads->step = new_step(find_start(data));
	find_roads(data, roads, roads, find_start(data));
	print_roads(roads);
	return 0;
}