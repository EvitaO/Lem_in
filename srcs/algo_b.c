/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo_b.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/17 10:44:24 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/07 15:03:44 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	make_q_elm(t_link **tmp, char *name)
{
	(*tmp)->next = (t_link*)malloc(sizeof(t_link));
	*tmp = (*tmp)->next;
	(*tmp)->name = name;
	(*tmp)->next = NULL;
}

void		remove_q(t_link **q, t_able *hashtable)
{
	t_link	*tmp;
	t_node	*room;

	room = find_room(hashtable, (*q)->name);
	room->visited = 0;
	tmp = *q;
	*q = (*q)->next;
	free(tmp);
}

int			add_q(t_link **q, t_link *links, t_able *hashtable)
{
	t_link	*tmp;
	t_node	*room;
	t_node	*prev;

	tmp = *q;
	prev = find_room(hashtable, (*q)->name);
	while (tmp->next)
		tmp = tmp->next;
	while (links)
	{
		room = find_room(hashtable, links->name);
		if (start_end_room(hashtable, room->name) == 0 &&\
		room->visited == 0 && room->path_id == -1)
		{
			room->prev = prev;
			if (room->link->next)
				room->visited = prev->visited + 1;
			else
				room->visited = -1;
			make_q_elm(&tmp, room->name);
		}
		else if (start_end_room(hashtable, room->name) == 2)
			return (1);
		links = links->next;
	}
	return (0);
}

t_link		*algo_b(t_able *hashtable, int id)
{
	t_link	*q;
	t_node	*room;
	t_link	*q2;

	q = (t_link*)malloc(sizeof(t_link));
	q->name = hashtable->array[hashtable->size]->name;
	q->next = NULL;
	q2 = q;
	while (q)
	{
		room = find_room(hashtable, q->name);
		if (add_q(&q, room->link, hashtable) == 1)
			return (q2);
		q = q->next;
	}
	algo_d(hashtable, id);
	return (q2);
}
