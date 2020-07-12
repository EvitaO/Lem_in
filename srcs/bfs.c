/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/04 20:27:45 by anonymous     #+#    #+#                 */
/*   Updated: 2020/07/04 20:37:24 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		give_id(t_able *ht, int *id)
{
	t_node	*tmp;
	t_link	*tmp_l;
	t_node	*room;

	tmp = find_short_link_end(ht);
	if ((!(tmp)) || (tmp->path_id != -1 || tmp->visited <= 0))
		return ;
	tmp->path_id = *id;
	while (tmp && start_end_room(ht, tmp->name) == 0)
	{
		tmp_l = tmp->link;
		while (tmp_l)
		{
			room = find_room(ht, tmp_l->name);
			if (room->visited == tmp->visited - 1 &&\
			start_end_room(ht, room->name) != 2)
			{
				room->path_id = *id;
				tmp->prev = room;
				tmp = room;
				break ;
			}
			tmp_l = tmp_l->next;
		}
	}
}

static int		bfs_loop(t_able *ht, t_link **q, t_node *prev_r, t_link *links)
{
	t_node		*room;
	t_link		*tmp_q;

	tmp_q = *q;
	while (tmp_q->next)
		tmp_q = tmp_q->next;
	while (links)
	{
		room = find_room(ht, links->name);
		if (start_end_room(ht, room->name) == 0 &&\
		room->visited == 0 && room->path_id == -1)
		{
			if (room->link->next)
			{
				room->visited = prev_r->visited + 1;
				make_q_elm(&tmp_q, room->name);
			}
			else
				room->visited = -1;
		}
		else if (start_end_room(ht, room->name) == 2)
			return (1);
		links = links->next;
	}
	return (0);
}

t_path			*bfs_path(t_able *ht, t_path *p, int *id)
{
	t_link	*q;
	t_link	*q2;
	t_node	*room;

	make_q(&q, ht);
	q2 = q;
	while (q && (*id) < ht->max_path)
	{
		room = find_room(ht, q->name);
		if (bfs_loop(ht, &q, room, room->link) == 1)
		{
			give_id(ht, id);
			ht->array[ht->size]->path_id = 0;
			(*id)++;
			p = save_and_check(p, ht, (*id) - 1);
			break ;
		}
		q = q->next;
	}
	remove_q2(&q2, ht);
	return (p);
}
