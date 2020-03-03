/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 16:07:28 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/03/03 12:19:56 by eutrodri      ########   odam.nl         */
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

typedef struct			s_node
{
	char				*name;
	struct s_node		*next;
}						t_node;

typedef struct			s_able
{
	int					size;
	t_node				**array;
}						t_able;

/*
**									CHECK
**									INPUT
*/

t_able				check_input(int *ants, char **line,\
					t_room **room, char **str);
void				store_input_str(char **str, char **line);
int					check_comment(char *line);

/*
**		count ants
*/
int					count_ants(char **line, char **str);
int					check_ants(int ants, char **line);

/*
**		check rooms
*/
int					read_rooms(char **line, t_room **room, char **str);
int					check_rooms(char *line, t_room **room);
void				store_room(char **tmp, t_room **room);
void				check_valid_room(char **tmp, t_room **room);
void				valid_cordinates(char **tmp);
void				valid_name(char *tmp);

/*
**		check links
*/
void				read_links(char **line, t_room **room, char **str);
void				check_links(char *line, t_room **room);
void				check_room_exists(char *name, t_room **room);

/*
**		go to the start / end of a list
*/
void				go_to_first_room(t_room **room);

/*
**		store rooms in hashtable
*/
t_able			rooms_hash(t_room **room, t_able *hashtable, int size);
int				hash(int size, char *key);

/*
**			FREE
**			FUNCTION
*/
void			free_room(t_room **room);
void			free_tmp(char **tmp);

#endif
