/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 16:07:28 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/02/25 11:18:19 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "libft/libft.h"

typedef	struct			s_room
{
	char				*name;
	char				*x;
	char				*y;
	struct s_room		*next;
	struct s_room		*prev;
}						t_room;

int					check_ants(int ants, char **line);
int					check_rooms(char *line, t_room *room);
void				store_room(char **tmp, t_room *room);

#endif
