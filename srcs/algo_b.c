/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo_b.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/17 10:44:24 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/05/17 10:45:31 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	remove_q(t_link **q)
{
	t_link	*tmp;

	tmp = *q;
	*q = (*q)->next;
	free(tmp);
}

void	add_q(t_link **q, t_link *links, t_able *hashtable)
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
		if (start_end_room(hashtable, room->name) == 0 && room->visited == 0)
		{
			room->prev = prev;
			if (room->link->next)
				room->visited = prev->visited + 1;
			else
				room->visited = -1;
			tmp->next = (t_link*)malloc(sizeof(t_link));
			tmp = tmp->next;
			tmp->name = room->name;
			tmp->next = NULL;
		}
		links = links->next;
	}
}

void	algo_b(t_able *hashtable)
{
	t_link	*links;
	t_link	*q;
	t_node	*room;

	q = (t_link*)malloc(sizeof(t_link));
	q->name = hashtable->array[hashtable->size]->name;
	q->next = NULL;
	while (q)
	{
		room = find_room(hashtable, q->name);
		links = room->link;
		add_q(&q, links, hashtable);
		ft_printf("room %s visited %i\n", room->name, room->visited);
		remove_q(&q);
	}
}
