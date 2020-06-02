/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/30 14:41:32 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/02 16:06:42 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_node	*find_id_end(t_able *ht, int id)
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
			return (room2);
		link = link->next;
	}
	return (NULL);
}

int		bla(t_able *ht, int id, t_path *all)
{
	t_node	*tmp;
	t_node	*room;

	//make_path(ht->array[ht->size + 1], all->array[id]);
	if (!(all->array[30]))
		ft_printf("BBB\n");
	tmp = find_id_end(ht, id);
	if (!tmp)
		return (-1);
	room = find_room(ht, tmp->name);
	while (start_end_room(ht, room->name) != 1)
	{
		ft_printf("%s	%i\n", room->name, room->path_id);
		room = room->prev;
	}
	ft_printf("%s\n", room->name);
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
		i = bla(hashtable, id, &all);
		ft_printf("i is %i && id is %i\n", i, id);
		// if (i == -1 && id == 0)
		// 	i = 0;
		id++;
	}
	return (all);
	// t_path	mp;
	//int		i;

	// mp.array = (t_link**)malloc(sizeof(t_link) * hashtable->max_path);
	// ft_memset(mp.array, 0, hashtable->max_path * sizeof(t_link));
	//i = 0;
	//id = 0;
	// while (id < hashtable->max_path && i == 0)
	// {
	// 	i = bla(hashtable, id);
	// 	id++;
	// }
}