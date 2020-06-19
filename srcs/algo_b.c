/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo_b.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/17 10:44:24 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/19 22:10:09 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_path		*algo_b(t_able *hashtable, int id, t_path *p)
{
	t_link	*q;
	t_node	*room;
	t_link	*q2;
	int		i;

	i = 1;
	while (i == 1 && hashtable->check == 0)
	{
		i = 0;
		q = (t_link*)malloc(sizeof(t_link));
		q->name = ft_strdup(hashtable->array[hashtable->size]->name);
		q->next = NULL;
		q2 = q;
		while (q)
		{
			room = find_room(hashtable, q->name);
			if (add_q(&q, room->link, hashtable) == 1)
			{
				put_id(hashtable, id);
				remove_q2(&q2, hashtable);
				p = save_and_check(p, hashtable, id);
				id++;
				i = 1;
				break ;
			}
			q = q->next;
		}
	}
	remove_q2(&q2, hashtable);
	return (p);
}
