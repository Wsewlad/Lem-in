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

void	print_map(t_list *map)
{
	while (map)
	{
		ft_printf("%s\n", map->content);
		map = map->next;
	}
}

void	print_error(char *str)
{
	ft_printf("{red}ERROR: '%s'{eoc}\n", str);
	exit(1);
}