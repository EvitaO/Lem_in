/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 16:07:28 by eutrodri       #+#    #+#                */
/*   Updated: 2020/03/05 15:29:40 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"

typedef	struct		s_room
{
	char			*name;
	char			*x;
	char			*y;
	int				comment;
	struct s_room	*next;
	struct s_room	*prev;
}					t_room;

typedef struct		s_link
{
	char			*name;
	struct s_link	*next;
}					t_link;

typedef struct		s_node
{
	char			*name;
	t_link			*link;
	struct s_node	*next;
}					t_node;

typedef struct		s_able
{
	int				ants;
	int				size;
	int				cnt_l;
	t_node			**array;
}					t_able;

/*
**									CHECK
**									INPUT
*/

t_able				check_input(char **line, t_room **room, char **str);
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
void				read_links(char **line, t_room **room, char **str, t_able\
					*hashtable);
void				check_links(char *line, t_room **room, t_able *hashtable);
void				check_room_exists(char *name, t_room **room);

/*
**		go to the start / end of a list
*/
void				go_to_first_room(t_room **room);

/*
**		store in hashtable
*/
t_able				rooms_hash(t_room **room, t_able *hashtable, int size);
int					hash(int size, char *key);
void				store_links(char **tmp, t_able *hashtable);
void				put_link(t_node **t, char *name, char *new);

/*
**			FREE
**			FUNCTION
*/
void				free_room(t_room **room);
void				free_tmp(char **tmp);
void				free_ht(t_able *hashtable);
void				free_link(t_link *link);
void				free_node(t_node *node);

#endif
