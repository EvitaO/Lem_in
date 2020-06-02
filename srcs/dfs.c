/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/30 00:27:23 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/02 14:55:55 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	test2(int id, t_node *room, t_able *ht)
{
	t_node	*room2;
	t_link	*link;

	link = room->link;
	room->path_id = id;
	room->visited = 0;
	//ft_printf("Lalaal link is %s room is %s id is %i\n", link->name, room->name, id);
	while (link)
	{
		room2 = find_room(ht, link->name);
		if (room2->prev == room)
			test2(id, room2, ht);
		link = link->next;
	}
}

int		put_link_off(t_able *ht, int id, char *name)
{
	t_node	*room;
	int		i;

	i = 0;
	//ft_printf("id is %i\n");
	room = find_room(ht, name);
	//ft_printf("room is %s\n", room->name);
	if (start_end_room(ht, room->prev->name) == 1)
		return (0);
	i = dfs(ht, room->path_id, room->prev->name, 1);
	if (i == 1)
		test2(id, room, ht);
	return (i);
}

int		rec(t_able *ht, t_link **link, int id, int vst)
{
	t_node	*room;
	int		i;

	i = 0;
	//ft_printf("link is %s\n", (*link)->name);
	room = find_room(ht, (*link)->name);
	//if (room->visited == 0)
	//	room->visited = vst;
	//ft_printf("room is %s en vst is %i\n", room->name, room->path_id);
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

int		dfs(t_able *ht, int id, char *name, int vst)
{
	t_node	*room;
	t_node	*room2;
	t_link	*link;
	int		i;

	if (ft_strcmp(name, ht->array[ht->size + 1]->name) == 0)
		return (1);
	if (ft_strcmp(name, ht->array[ht->size]->name) == 0)
		return (0);
	room = find_room(ht, name);
	if (room->visited == 0)
		room->visited = vst;
	//ft_printf("room is %s en vst is %i\n", room->name, vst);
	i = 0;
	link = room->link;
	if (room->path_id != -1)
		id = room->path_id;
	while (link && i == 0)
	{
		room2 = find_room(ht, link->name);
		//ft_printf("room2 is %s\n", room2->name);
		if (room2 != room->prev)
		{
			if (room->path_id == -1 && room2->path_id == -1)
				room2->prev = room;
			i = rec(ht, &link, id, vst + 1);
		}
		else
			link = link->next;
	}
	if (i != 1)
	{
		link = room->link;
		while (link && i == 0)
		{
			room2 = find_room(ht, link->name);
			//ft_printf("room is %s id %i room2 %s %i\n", room->name, room->path_id, room2->name, id);
			if (room2->path_id != -1 && room2->prev != room)
				i = put_link_off(ht, id, room2->name);
			if (i == 0)
				link = link->next;
		//	if (start_end_room(ht, room->prev->name) == 1)
		//		return (0);
		}
	}
	room->visited = 0;
	if (i == 1)
	{
		room->path_id = id;
		room2->prev = room;
		return (i);
	}
	if (room->path_id == -1)
		room->prev = NULL;	
	return (i);
}

void	algo_d(t_able *ht, int id)
{
	t_node	*room;
	t_node	*room2;
	t_link	*link;
	int		i;

	ft_printf("WHASGHASGKHSJKHGAS!!\n");
	i = 0;
	room = find_room(ht, ht->array[ht->size]->name);
	link = room->link;
	while (link && i == 0)
	{
		//i = rec(ht, &link, id, 1);
		room2 = find_room(ht, link->name);
		if (room2->path_id == -1)
		 	i = dfs(ht, id, link->name, 1);
		//ft_printf("%i --\n", i);
		link = link->next;
	}
}
