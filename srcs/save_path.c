/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 11:22:07 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/06/29 14:27:21 by eutrodri      ########   odam.nl         */
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
	p = algo_b(hashtable, i, p);
	if (!p)
		exit(ft_error(13));
	return (p);
}
