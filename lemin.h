/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:13:08 by vfil              #+#    #+#             */
/*   Updated: 2018/03/13 17:13:10 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"

typedef	struct	s_link
{
	int 		r1;
	int 		r2;
}				t_link;

typedef	struct	s_room
{
	int 		type;
	char 		name;
	int 		x;
	int 		y;
}				t_room;

typedef struct	s_data
{
	int 		r_nb;
	t_room		*rooms;
	int 		l_nb;
	t_link		*links;
	int 		ants;
}				t_data;

t_list			*parse_map(void);
void			parse_data(t_data *data);
void			check_spdf(t_list *map, char c, int *d);
void			count_ants(t_list *map, t_data *data);
void			count_rooms(t_list *map, t_data *data);
void			count_links(t_list *map, t_data *data);
void			print_map(t_list *map);
void			print_error(char *str);

#endif
