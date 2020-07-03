/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo_b.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/17 10:44:24 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/07/03 22:07:59 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	make_q(t_link **q, t_able *hashtable)
{
	*q = (t_link*)malloc(sizeof(t_link));
	(*q)->name = ft_strdup(hashtable->array[hashtable->size]->name);
	(*q)->next = NULL;
}

static int	give_path_id(t_able *hashtable, int *id, t_link **q2)
{
	put_id(hashtable, *id);
	remove_q2(q2, hashtable);
	(*id)++;
	return (1);
}

static void	give_path_id2(t_able *ht, int *id, t_link **q2)
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
			if (room->visited == tmp->visited - 1)
			{
				room->path_id = *id;
				tmp->prev = room;
				tmp = room;
				break ;
			}
			tmp_l = tmp_l->next;
		}
	}
	remove_q2(q2, ht);
	(*id)++;
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

static t_path	*bfs_path(t_able *ht, t_path *p, int *id)
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
			give_path_id2(ht, id, &q2);
			p = save_and_check(p, ht, (*id) - 1);
			break ;
		}
		q = q->next;
	}
	remove_q2(&q2, ht);
	return (p);
}

t_path		*algo_b(t_able *hashtable, int id, t_path *p)
{
	t_link	*q;
	t_node	*room;
	t_link	*q2;
	int		i;

	i = 1;
	p = bfs_path(hashtable, p, &id);
	while (i == 1 && id < hashtable->max_path && hashtable->check != -5)
	{
		i = 0;
		make_q(&q, hashtable);
		q2 = q;
		while (q)
		{
			room = find_room(hashtable, q->name);
			if (add_q(&q, room->link, hashtable) == 1)
			{
				i = give_path_id(hashtable, &id, &q2);
				if (hashtable->check != -5)
					p = save_and_check(p, hashtable, id - 1);
				break ;
			}
			q = q->next;
		}
	}
	if (id <= hashtable->max_path && (i = 0 || hashtable->check == -5))
		remove_q2(&q2, hashtable);
	return (p);
}
