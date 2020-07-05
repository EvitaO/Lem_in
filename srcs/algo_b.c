/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo_b.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/17 10:44:24 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/07/05 15:07:39 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		make_q(t_link **q, t_able *hashtable)
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

t_path		*algo_b(t_able *hashtable, int id, t_path *p, int i)
{
	t_link	*q;
	t_node	*room;
	t_link	*q2;

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
				p = save_and_check(p, hashtable, id - 1);
				break ;
			}
			q = q->next;
		}
	}
	if (id <= hashtable->max_path && (i == 0 || hashtable->check == -5))
		remove_q2(&q2, hashtable);
	return (p);
}
