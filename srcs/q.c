/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   q.c                                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/14 08:57:39 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/07/03 11:27:53 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		make_q_elm(t_link **tmp, char *name)
{
	(*tmp)->next = (t_link*)malloc(sizeof(t_link));
	*tmp = (*tmp)->next;
	(*tmp)->name = ft_strdup(name);
	(*tmp)->next = NULL;
}

void		remove_q2(t_link **q, t_able *hashtable)
{
	t_link	*tmp;
	t_node	*room;

	while (*q)
	{
		room = find_room(hashtable, (*q)->name);
		if (room->visited != -5)
			room->visited = 0;
		room->prev2 = NULL;
		room->n = NULL;
		tmp = *q;
		*q = (*q)->next;
		free(tmp->name);
		free(tmp);
	}
}

int			add_q(t_link **q, t_link *links, t_able *hashtable)
{
	t_link	*tmp;
	t_node	*room;
	t_node	*room2;
	t_node	*prev;

	tmp = *q;
	prev = find_room(hashtable, (*q)->name);
	while (tmp->next)
		tmp = tmp->next;
	while (links && prev->visited != -2)
	{
		room = find_room(hashtable, links->name);
		if (start_end_room(hashtable, room->name) == 0 &&\
		room->visited == 0)
		{
			if (room->path_id == -1)
			{
				room->n = prev;
				if (room->link->next)
				{
					room->visited = prev->visited + 1;
					make_q_elm(&tmp, room->name);
				}
				else
					room->visited = -1;
			}
			else if (room->prev && room->path_id != -1 &&\
				prev->path_id != room->path_id &&\
				start_end_room(hashtable, room->prev->name) != 1)
			{
				if (room->prev && room->prev->visited == 0 &&\
				start_end_room(hashtable, room->prev->name) == 0)
				{
					room2 = find_room(hashtable, room->prev->name);
					room->prev2 = prev;
					room->n = prev;
					room2->n = room;
					room->visited = -2;
					room2->visited = prev->visited + 1;
					make_q_elm(&tmp, room->name);
					make_q_elm(&tmp, room2->name);
					if (room2->prev && room2->prev->visited == 0 &&\
						start_end_room(hashtable, room2->prev->name) != 1)
					{
						room2->prev->n = room2;
						room2->prev->visited = room2->visited + 1;
						make_q_elm(&tmp, room2->prev->name);
					}
				}
			}
		}
		else if (start_end_room(hashtable, room->name) == 2 &&\
			prev->path_id == -1)
			return (1);
		links = links->next;
	}
	return (0);
}
