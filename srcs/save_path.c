/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 11:22:07 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/04 20:50:17 by anonymous     ########   odam.nl         */
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

t_path			*save_path(t_able *hashtable)
{
	int		i;
	t_path	*p;

	i = 0;
	p = NULL;
	hashtable->array[hashtable->size]->visited = 0;
	put_link_off(hashtable);
	p = algo_b(hashtable, i, p, 1);
	if (!p)
		exit(ft_error(13));
	return (p);
}
