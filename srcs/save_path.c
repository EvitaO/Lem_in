/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 11:22:07 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/03 11:37:29 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			make_path(t_node *room, t_link *path)
{
	t_link	*p;

	p = path;
	p->name = ft_strdup(room->name);
	p->prev = NULL;
	p->visited = 0;
}

t_node			*find_short_link_end(t_able *ht)
{
	t_node	*tmp;
	t_link	*link;

	tmp = ht->array[ht->size + 1];
	link = tmp->link;
	tmp = find_room(ht, link->name);
	while (link->next && tmp->visited <= 0)
	{
		link = link->next;
		tmp = find_room(ht, link->name);
	}
	return (tmp);
}

int			cnt_links(t_able *ht, t_node *room)
{
	t_link	*links;
	int		cnt;
	t_node	*tmp;

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

void			put_off(t_able *ht, char *name)
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
	t_link	*tmp;
	t_link	*q2;

	q = (t_link*)malloc(sizeof(t_link));
	q->name = ft_strdup(ht->array[ht->size]->name);
	q->next = NULL;
	q->prev = NULL;
	tmp = q;
	q2 = q;
	while (q)
	{
		room = find_room(ht, q->name);
		if (cnt_links(ht, room) == 0)
			put_vst(ht, room, tmp);
		else
			put_off(ht, room->name);
		q = q->next;
	}
	remove_q2(&q2, ht);
}

t_path			*save_path(t_able *hashtable)
{
	int		i;
	t_path	*p;

	i = 0;
	p = NULL;
	hashtable->array[hashtable->size]->visited = 0;
	put_link_off(hashtable);
	p = algo_b(hashtable, i, p);
	if (!p)
		exit(ft_error(13));
	return (p);
}
