/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 17:12:18 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/07 14:32:40 by eutrodri      ########   odam.nl         */
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

typedef struct		s_tab
{
	t_room			**array;
}					t_tab;

typedef struct		s_link
{
	char			*name;
	int				visited;
	struct s_link	*next;
	struct s_link	*prev;
}					t_link;

typedef struct		s_node
{
	char			*name;
	int				visited;
	int				path_id;
	t_link			*link;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_able
{
	int				ants;
	int				size;
	int				cnt_e;
	int				cnt_s;
	int				max_path;
	t_node			**array;
}					t_able;

typedef struct		s_path
{
	t_link			**array;
	int				instruction;
}					t_path;

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
void				links_start_end(t_able *hashtable);
void				max_path(t_able *ht);
/*
**			FREE
**			FUNCTION
*/
void				free_room(t_room **room);
void				free_tmp(char **tmp);
void				free_ht(t_able *hashtable);
void				free_link(t_link *link, char *x);
void				free_node(t_node *node);

/*
**			PATH
*/
t_path				save_path(t_able *hashtable);
t_link				*find_path(t_able *hashtable);
void				find_short_path(t_able *ht, t_path *path, int i);
void				find_node(t_able *hash, t_path *p, int index, int index_p);
t_node				*find_room(t_able *hashtable, char *name);
int					start_end_room(t_able *hashtable, char *name);
void				make_path(t_node *room, t_link *path);
t_link    			*algo_b(t_able *hashtable, int id);
int	    			add_q(t_link **q, t_link *links, t_able *hashtable);
void				remove_q(t_link **q, t_able *hashtable);

t_node				*find_short_link_end(t_able *ht);
void				algo_d(t_able *ht, int id);
int					dfs(t_able *ht, int id, char *name, int vst);
int					rec(t_able *ht, t_link **link, int id, int vst);
int					put_link_off(t_able *ht, int id, char *name);
void				change_id(int id, t_node *room, t_able *ht);
int					next_link(t_able *ht, t_node *room, int id, int vst);
int					next_link_id(t_able *ht, t_node *room, int id);
int					find_detour_link(t_able *ht, char *name);
void				set_id_off(t_able *ht, char *name, int off);

/*
**			SAVE ALL PATHS
*/
t_path				save_all_p(t_able *hashtable);
int					save_a_p(t_able *ht, int id, t_path *all);
t_link				*find_id_end(t_able *ht, int id);
void				size_sort_all(t_path *all);
void				size_path(t_path *all);
void				sort_all(t_path *all);
int					check_if_sorted(t_path *all);
void				swap_tlink(t_link *big, t_link *smal);

void				use_one_p(t_path *p, t_able *hashtable);

/*
**			DEVIDE ANTS
*/
void				devide_ants(t_path *p, int ants);
int					choose_path(t_link *tmp, t_link *tmp2, int i, t_link *p);
void				reset_vst(t_path *p);
void				all_instruction(t_path *p);

/*
**			WALKING ANTS
*/
int					check_paths(t_path *p);
int					ants_end(int cnt_p, int ants, t_path *p);
int					move_ants(int print, t_link *p, int *a);
int					move_ants2(int print, t_link *tmp, t_link *p, int *a);
void				walk_ants(t_path *p, int ants);
int					print_ant(int print, int ant, char *name);

#endif
