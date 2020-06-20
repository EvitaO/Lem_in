/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_all_p.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/04 12:46:20 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/20 19:25:46 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_link		*find_id_end(t_able *ht, int id)
{
	t_link	*link;
	t_node	*room;
	t_node	*room2;

	room = ht->array[ht->size + 1];
	link = room->link;
	while (link)
	{
		room2 = find_room(ht, link->name);
		if (room2->path_id == id)
			return (link);
		link = link->next;
	}
	return (NULL);
}

int			save_a_p(t_able *ht, int id, t_path *all)
{
	t_link	*tmp;
	t_link	*tmp2;
	t_node	*room;

	make_path(ht->array[ht->size + 1], all->array[id]);
	tmp = all->array[id];
	tmp2 = find_id_end(ht, id);
	if (!tmp2)
		return (-1);
	room = find_room(ht, tmp2->name);
	while (room && start_end_room(ht, room->name) != 1)
	{
		tmp->prev = (t_link*)malloc(sizeof(t_link));
		tmp->prev->next = tmp;
		tmp = tmp->prev;
		make_path(room, tmp);
		room = room->prev;
	}
	if (!room)
		return (-1);
	tmp->prev = (t_link*)malloc(sizeof(t_link));
	tmp->prev->name = ft_strdup(room->name);
	all->array[id]->next = tmp->prev;
	all->array[id]->next->visited = 0;
	tmp->prev->prev = NULL;
	return (0);
}

t_path		*save_all_p(t_able *hashtable, int max)
{
	int		i;
	int		id;
	t_path	*all;

	all = (t_path*)malloc(sizeof(t_path));
	all->array = (t_link**)malloc(sizeof(t_link) * hashtable->max_path);
	ft_memset(all->array, 0, hashtable->max_path * sizeof(t_link));
	all->instruction = 0;
	i = 0;
	id = 0;
	while (id <= max && i != -1)
	{
		all->array[id] = (t_link*)malloc(sizeof(t_link));
		all->array[id]->prev = NULL;
		i = save_a_p(hashtable, id, all);
		id++;
	}
	size_sort_all(all);
	return (all);
}

t_path		*save_and_check(t_path *p, t_able *hashtable, int id)
{
	t_path	*p2;

	p2 = save_all_p(hashtable, id);
	devide_ants(p2, hashtable->ants);
	if (p && p->instruction <= p2->instruction)
	{
		free_p(p2, hashtable);
		hashtable->check = 1;
		return (p);
	}
	else if (p)
	{
		free_p(p, hashtable);
		return (p2);
	}
	return (p2);
}
