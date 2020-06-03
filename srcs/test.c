/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/30 14:41:32 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/03 11:45:07 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_link	*find_id_end(t_able *ht, int id)
{
	t_link	*link;
	t_node	*room;
	t_node	*room2;

	room = ht->array[ht->size + 1];
	link = room->link;
	while (link)
	{
		room2 = find_room(ht, link->name);
		//ft_printf("la	r	%s	i %i\n", room2->name, room2->path_id);
		if (room2->path_id == id)
			return (link);
		link = link->next;
	}
	return (NULL);
}

int		bla(t_able *ht, int id, t_path *all)
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
	while (start_end_room(ht, room->name) != 1)
	{
		tmp->prev = (t_link*)malloc(sizeof(t_link));
		tmp->prev->next = tmp;
		tmp = tmp->prev;
		make_path(room, tmp);
		room = room->prev;
	}
	tmp->prev = (t_link*)malloc(sizeof(t_link));
	tmp->prev->name = ft_strdup(room->name);
	all->array[id]->next = tmp->prev;
	tmp->prev->prev = NULL;
	return (0);

}

t_path	test(t_able *hashtable)
{
	int		i;
	int		id;
	t_path	all;

	all.array = (t_link**)malloc(sizeof(t_link) * hashtable->max_path);
	ft_memset(all.array, 0, hashtable->max_path * sizeof(t_link));
	i = 0;
	id = 0;
	while (id < hashtable->max_path && i != -1)
	{
		all.array[id] = (t_link*)malloc(sizeof(t_link));
		all.array[id]->prev = NULL;
		i = bla(hashtable, id, &all);
		id++;
	}
	return (all);
}