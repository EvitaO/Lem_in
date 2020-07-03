/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 11:22:07 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/06/30 13:09:46 by eutienne      ########   odam.nl         */
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

void			put_off(t_able *ht, int i, char *name)
{
	t_node	*room;
	t_link	*tmp;
	t_node	*tmp2;

	room = find_room(ht, name);
	tmp = room->link;
	while (tmp && i != 0)
	{
		if (start_end_room(ht, tmp->name) == 0)
		{
			tmp2 = find_room(ht, tmp->name);
			if (tmp2->visited == i)
			{
				tmp2->visited = -2;
				put_off(ht, i - 1, tmp2->name);
			}
		}
		tmp = tmp->next;
	}
}

t_link			*con_end(t_link *tmp, t_able *ht)
{
	t_link	*tmp2;
	t_node	*room;

	tmp2 = tmp;
	while (tmp2)
	{
		room = find_room(ht, tmp->name);
		if (start_end_room(ht, room->name) == 2)
		{
			while (ft_strcmp(tmp2->name, tmp->name) != 0)
				tmp = tmp->next;
			return (tmp);
		}
		tmp2 = tmp2->next;
	}
	return (tmp);
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

	room = find_room(ht, name);
	tmp = room->link;
	q = (t_link*)malloc(sizeof(t_link));
	q->name = ft_strdup(ht->array[ht->size]->name);
	q->next = NULL;
	q->prev = NULL;
	while (tmp)
	{
		tmp = con_end(tmp, ht);
		if (start_end_room(ht, tmp->name) == 0)
		{
			room = find_room(ht, tmp->name);
			if (room->visited > i || room->visited == 0)
			{
				if (room->visited > i)
					put_off(ht, room->visited - 1, room->name);
				room->visited = i;
				add_room(&q, room->name);
			}
		}
		if (q->next && ((start_end_room(ht, tmp->name) == 2) || (!(tmp->next))))
		{
			q = q->next;
			room = find_room(ht, q->name);
			tmp = room->link;
		}
		else
			tmp = tmp->next;
	}
	while (q)
	{
		room = find_room(ht, q->name);
		tmp = room->link;
		while (tmp)
		{
			room = find_room(ht, tmp->name);
			if (room->visited != -2)
				room->visited = 0;
			tmp = tmp->next;
		}
		q = q->prev;
	}
}

t_path			*save_path(t_able *hashtable)
{
	int		i;
	t_path	*p;

	i = 0;
	p = NULL;
	hashtable->array[hashtable->size]->visited = 0;
	put_link_off(hashtable, 1, hashtable->array[hashtable->size]->name);
	p = algo_b(hashtable, i, p);
	if (!p)
		exit(ft_error(13));
	return (p);
}
