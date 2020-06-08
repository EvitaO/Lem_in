/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/30 00:27:23 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/07 14:49:25 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		rec(t_able *ht, t_link **link, int id, int vst)
{
	t_node	*room;
	int		i;

	i = 0;
	room = find_room(ht, (*link)->name);
	if ((!room))
		return (0);
	if (room->visited == 0)
		room->visited = vst;
	if (start_end_room(ht, room->name) == 1)
	{
		room->prev = NULL;
		*link = (*link)->next;
		return (0);
	}
	if (room->path_id == -1)
		i = dfs(ht, id, (*link)->name, vst);
	*link = (*link)->next;
	return (i);
}

int		next_link_id(t_able *ht, t_node *room, int id)
{
	t_node	*room2;
	t_link	*link;
	int		i;

	i = 0;
	link = (room)->link;
	while (link && i == 0)
	{
		room2 = find_room(ht, link->name);
		if (room2->path_id != -1 && room2->prev != room)
			i = put_link_off(ht, id, room2->name);
		link = link->next;
	}
	if (i == 1)
	{
		(room)->path_id = id;
		room2->prev = room;
	}
	return (i);
}

int		next_link(t_able *ht, t_node *room, int id, int vst)
{
	t_node	*room2;
	t_link	*link;
	int		i;

	i = 0;
	link = (room)->link;
	while (link && i == 0)
	{
		room2 = find_room(ht, link->name);
		if (room2 == (room)->prev || room2->path_id != -1)
			link = link->next;
		else
		{
			if (room2->path_id == -1)
				room2->prev = room;
			i = rec(ht, &link, id, vst + 1);
		}
	}
	if (i == 1)
	{
		(room)->path_id = id;
		room2->prev = room;
	}
	return (i);
}

int		dfs(t_able *ht, int id, char *name, int vst)
{
	t_node	*room;
	int		i;

	if (ft_strcmp(name, ht->array[ht->size + 1]->name) == 0)
		return (1);
	if (ft_strcmp(name, ht->array[ht->size]->name) == 0)
		return (0);
	room = find_room(ht, name);
	if ((!room))
		return (0);
	if (room->visited == 0)
		room->visited = vst;
	i = 0;
	if (room->path_id != -1)
		id = room->path_id;
	i = next_link(ht, room, id, vst);
	if (i != 1)
		i = next_link_id(ht, room, id);
	return (i);
	room->visited = 0;
	if (i == 1)
		return (i);
	if (room->path_id == -1)
		room->prev = NULL;
	return (i);
}
