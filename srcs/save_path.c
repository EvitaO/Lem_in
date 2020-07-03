/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 11:22:07 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/03 11:16:33 by eutrodri      ########   odam.nl         */
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

void			add_room(t_link **q, char *name)
{
	t_link		*tmp;

	tmp = *q;
	while ((*q)->next)
		*q = (*q)->next;
	(*q)->next = (t_link*)malloc(sizeof(t_link));
	(*q)->next->name = ft_strdup(name);
	(*q)->next->next = NULL;
	(*q)->next->prev = (*q);
	*q = tmp;
}

void			put_link_off(t_able *ht, int i, char *name)
{
	t_node	*room;
	t_link	*tmp;
	t_link	*q;
	t_link	*q2;

	q = (t_link*)malloc(sizeof(t_link));
	q->name = ft_strdup(ht->array[ht->size]->name);
	q->next = NULL;
	q->prev = NULL;
	q2 = q;
	if (i != 0 && start_end_room(ht, name) == 0)
		return ;
	while (q)
	{
		room = find_room(ht, q->name);
		if (cnt_links(ht, room) == 0)
		{
			tmp = room->link;
			while (tmp)
			{
				room = find_room(ht, tmp->name);
				if (room->visited == 0)
				{
					room->visited = 1;
					add_room(&q, room->name);
				}
				tmp = tmp->next;
			}
		}
		else
			put_off(ht, room->name);
		q = q->next;
	}
	while (q2)
	{
		room = find_room(ht, q2->name);
		if (room->visited != -5)
			room->visited = 0;
		room->prev2 = NULL;
		room->n = NULL;
		tmp = q2;
		q2 = q2->next;
		free(tmp->name);
		free(tmp);
	}
}

t_path			*save_path(t_able *hashtable)
{
	int		i;
	t_path	*p;

	i = 0;
	p = NULL;
	hashtable->array[hashtable->size]->visited = 0;
	put_link_off(hashtable, 0, hashtable->array[hashtable->size]->name);
	p = algo_b(hashtable, i, p);
	if (!p)
		exit(ft_error(13));
	return (p);
}
