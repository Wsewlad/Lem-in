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
	char 		r1_t;
	char 		r2_t;
}				t_link;

typedef	struct	s_room
{
	char 		type;
	char 		*name;
	int 		x;
	int 		y;
}				t_room;

typedef struct	s_data
{
	int 		ants;
	int 		r_nb;
	t_room		*rooms;
	int 		l_nb;
	t_link		*links;
}				t_data;

typedef	struct		s_step
{
	int 			r;
	struct s_step	*next;
}					t_step;

typedef struct		s_road
{
	int 			steps;
	t_step			*step;
	struct s_road	*next;
}					t_road;

void			parse_data(t_data *data);
t_list			*parse_map(void);
int				check_spdf(t_list *map, char c);
void			count_ants(t_list *map, t_data *data);
void			count_rooms(t_list *map, t_data *data);
void			count_links(t_list *map, t_data *data);
void			parse_rooms(t_list *map, t_data *data);
t_list			*parse_room(t_list *map, t_data *data, char type, int *r);
void			parse_links(t_list *map, t_data *data);
int			 	check_rindex(t_data *data, char *name);
void			find_roads(t_data data, t_road *roads, t_road *current, int start);
int			 	find_start(t_data data);
t_road			*new_road();
t_step			*new_step(int room);
void			step_append(t_step *head, t_step *new);
void			road_append(t_road *head, t_road *new);
t_road			*copy_road(t_road *road);
void			print_map(t_list *map);
void			print_error(char *str);
void			print_data(t_data *data);
void		 	print_roads(t_road	*roads);

#endif
