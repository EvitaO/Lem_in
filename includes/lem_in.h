/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 16:07:28 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/02/25 15:27:24 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "../libft/includes/libft.h"

typedef	struct			s_room
{
	char				*name;
	char				*x;
	char				*y;
	struct s_room		*next;
	struct s_room		*prev;
}						t_room;

typedef struct			s_able
{
	int					size;
	t_room				**array;
}						t_able;

/* 		count ants 				*/
int					count_ants(char **line);
int					check_ants(int ants, char **line);

/*		check rooms				*/
void				read_rooms(char **line, t_room **room);
int					check_rooms(char *line, t_room **room);
void				store_room(char **tmp, t_room **room);

/*		check links				*/
void				read_links(char **line, t_room **room);
void				check_links(char *line, t_room **room);
void				check_room_exists(char *name, t_room **room);

/*		go to the start / end of a list		*/
void				go_to_first_room(t_room **room);

#endif
