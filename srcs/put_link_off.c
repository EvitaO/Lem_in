/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_link_off.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/06 22:05:49 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/07 15:02:52 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	set_id_off(t_able *ht, char *name, int off)
{
	t_node	*room;

	while (off > 0)
	{
		room = find_room(ht, name);
		room->path_id = -1;
		off--;
	}
}

int		find_detour_link(t_able *ht, char *name)
{
	t_node	*room;
	t_node	*tmp;
	t_link	*link;
	int		i;
	int		off;

	room = find_room(ht, name);
	i = 0;
	off = -1;
	while (room && room->prev && i == 0)
	{
		if (start_end_room(ht, room->prev->name) == 1)
			return (0);
		room = room->prev;
		link = room->link;
		while (link && room && i == 0)
		{
			tmp = find_room(ht, link->name);
			if (tmp->path_id == -1)
				i = dfs(ht, room->path_id, tmp->name, 1);
			else if (room && tmp && room->prev != tmp && tmp->prev != room)
				i = put_link_off(ht, -1, tmp->name);
			link = link->next;
		}
		off++;
	}
	// if (off > 0 && i == 1)
	// 	set_id_off(ht, name, off);
	return (i);
}

void	change_id(int id, t_node *room, t_able *ht)
{
	t_node	*room2;
	t_link	*link;

	link = room->link;
	room->path_id = id;
	room->visited = 0;
	while (link)
	{
		room2 = find_room(ht, link->name);
		if (room2 && room2->prev == room)
			change_id(id, room2, ht);
		link = link->next;
	}
}

int		put_link_off(t_able *ht, int id, char *name)
{
	t_node	*room;
	int		i;

	i = 0;
	room = find_room(ht, name);
	if (start_end_room(ht, room->prev->name) == 1)
		return (0);
	i = dfs(ht, room->path_id, room->prev->name, 1);
	if (i != 1)
		i = find_detour_link(ht, room->prev->name);
	if (i == 1)
		change_id(id, room, ht);
	return (i);
}
