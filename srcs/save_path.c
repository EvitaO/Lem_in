/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 11:22:07 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/06/19 16:00:31 by eutrodri      ########   odam.nl         */
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

t_node	*find_short_link_end(t_able *ht)
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
void		find_short_path(t_able *ht, t_path *path, int i)
{
	t_node	*tmp;
	t_node	*tmp2;
	t_link	*link;

	tmp = find_short_link_end(ht);
	if (tmp->path_id != -1 || tmp->visited <= 0)
		return ;
	link = path->array[i];
	link->prev = (t_link*)malloc(sizeof(t_link));
	tmp2 = ht->array[ht->size];
	while (!(ft_strcmp(tmp->name, tmp2->name) == 0))
	{
		link->prev->next = link;
		link = link->prev;
		make_path(tmp, link);
		tmp->path_id = i;
		tmp = tmp->prev;
		link->prev = (t_link*)malloc(sizeof(t_link));
	}
	link->prev->name = tmp2->name;
	path->array[i]->next = link->prev;
	link->prev->prev = NULL;
}

t_path			*save_path(t_able *hashtable)
{
	int		i;
	t_path	*p;

	i = 0;
	p = NULL;
	hashtable->array[hashtable->size]->visited = 0;
	p = algo_b(hashtable, i, p);
	return (p);
}
