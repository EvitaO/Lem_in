/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo_b.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/17 10:44:24 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/02 15:54:22 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
/*
int	put_link_off(t_able *ht, t_link **q)
{
	t_node	*room;
	t_link	*link;
	t_link	*tmp;

	tmp = *q;
	room = find_room(ht, tmp->name);
	while (room)
	{
		link = room->link;
		while (link)
		{
			room2 = find_room(ht, link->name);
			if (ft_strcmp(room->name, room->name) == 0 ||\
			 ft_strcmp(link->name, ht->array[ht->size]->name) == 0 ||\
			 ft_strcmp(link->name, link->prev->name) == 0)
				link = link->next;
			else
				break ;
		}
		ft_printf("room\n");
		ft_printf("room->%s\n", room->name);
			if (link == NULL)
			{
				tmp = tmp->next;
				if (tmp)
				room = find_room(ht, tmp->name);
				else
					return (0);
			}	
			else if (ft_strcmp(link->name, ht->array[ht->size + 1]->name) == 0)
				return (1);
			else
				room = find_room(ht, link->name);			
	}
	return (0);
}*/
// void	put_link_off(t_able *ht, t_link **q)
// {
// 	t_link	*links;
// 	t_node	*room;
// 	t_link	*q2;

// 	remove_q(q, ht);
// 	*q = (t_link*)malloc(sizeof(t_link));
// 	(*q)->name = ht->array[ht->size]->name;
// 	(*q)->next = NULL;
// 	q2 = *q;
// 	while (q)
// 	{
// 		room = find_room(ht, q->name);
// 		links = room->link;
// 		add_q(&q, links, ht) == 1;
// 		//ft_printf("room %s visited %i\n", room->name, room->visited);
// 		*q = (*q)->next;
// 	}
// 	remove_q(q2, ht);
// }

void	remove_q(t_link **q, t_able *hashtable)
{
	t_link	*tmp;
	t_node	*room;

	room = find_room(hashtable, (*q)->name);
	//if (room->path_id == -1)
	room->visited = 0;
	tmp = *q;
	*q = (*q)->next;
	free(tmp);
}

int		add_q(t_link **q, t_link *links, t_able *hashtable)
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
		if (start_end_room(hashtable, room->name) == 0 && room->visited == 0 && room->path_id == -1)
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
		else if (start_end_room(hashtable, room->name) == 2)
		 	return (1);
		links = links->next;
	}
	return (0);
}

t_link	*algo_b(t_able *hashtable, int id)
{
	t_link	*links;
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
		ft_printf("room is %s\n", room->name);
		links = room->link;
		if (add_q(&q, links, hashtable) == 1)
			return (q2);
		q = q->next;
	}
	ft_printf("blub\n");
	algo_d(hashtable, id);
	ft_printf("lalala\n");
	//bla(hashtable, id);
	return (q2);
}
