/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_links_off.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/03 11:29:16 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/07/05 14:47:18 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		cnt_links(t_able *ht, t_node *room)
{
	t_link	*links;
	int		cnt;
	t_node	*tmp;

	cnt = 0;
	links = room->link;
	while (links)
	{
		tmp = find_room(ht, links->name);
		if (tmp->visited != -5)
			cnt++;
		links = links->next;
	}
	if (start_end_room(ht, room->name) == 0 && cnt <= 1)
		return (1);
	if (start_end_room(ht, room->name) != 0 && cnt < 1)
		return (1);
	return (0);
}

static void		put_off(t_able *ht, char *name)
{
	t_node	*room;
	t_link	*tmp;

	room = find_room(ht, name);
	room->visited = -5;
	tmp = room->link;
	while (tmp)
	{
		room = find_room(ht, tmp->name);
		if (cnt_links(ht, room) != 0 && room->visited != -5)
		{
			room->visited = -5;
			tmp = room->link;
		}
		else
			tmp = tmp->next;
	}
}

static void		put_vst(t_able *ht, t_node *room, t_link *q)
{
	t_link		*tmp;

	while (q->next)
		q = q->next;
	tmp = room->link;
	while (tmp)
	{
		room = find_room(ht, tmp->name);
		if (room->visited == 0)
		{
			room->visited = 1;
			make_q_elm(&q, room->name);
		}
		tmp = tmp->next;
	}
}

void			put_link_off(t_able *ht)
{
	t_node	*room;
	t_link	*q;
	t_link	*q2;
	t_link	*q3;

	q = (t_link*)malloc(sizeof(t_link));
	q->name = ft_strdup(ht->array[ht->size]->name);
	q->next = NULL;
	q->prev = NULL;
	q2 = q;
	q3 = q;
	while (q2->next)
		q2 = q2->next;
	while (q)
	{
		room = find_room(ht, q->name);
		if (cnt_links(ht, room) == 0)
			put_vst(ht, room, q2);
		else
			put_off(ht, room->name);
		q = q->next;
	}
	remove_q2(&q3, ht);
}
