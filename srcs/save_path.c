/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 11:22:07 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/05/03 15:58:18 by eutienne      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	make_path(t_node *room, t_link *path)
{
	t_link	*p;

	p = path;
	p->name = room->name;
	p->prev = NULL;
}

void	find_short_path(t_able *ht, t_path *path)
{
	t_node	*tmp;
	t_node	*tmp2;
	t_link	*link;

	tmp = ht->array[ht->size + 1];
	link = tmp->link;
	tmp = find_room(ht, link->name);
	link = link->next;
	while (link)
	{
		tmp2 = find_room(ht, link->name);
		if (tmp2->visited < tmp->visited && tmp2->visited > 0)
			tmp = tmp2;
		link = link->next;
	}
	link = path->array[0];
	link->prev = (t_link*)malloc(sizeof(t_link));
	tmp2 = ht->array[ht->size];
	while (!(ft_strcmp(tmp->name, tmp2->name) == 0))
	{
		ft_printf("%s - ", link->name);
		link->prev->next = link;
		link = link->prev;
		make_path(tmp, link);
		tmp = tmp->prev;
		if (!(ft_strcmp(tmp->name, tmp2->name) == 0))
			link->prev = (t_link*)malloc(sizeof(t_link));
	}
}

t_path	save_path(t_able *hashtable)
{
	int		i;
	t_path	p;

	p.array = (t_link**)malloc(sizeof(t_link) * hashtable->max_path);
	ft_memset(p.array, 0, hashtable->max_path * sizeof(t_link));
	i = 0;
	hashtable->array[hashtable->size]->visited = 1;
	while (i < hashtable->max_path)
	{
		algo(hashtable);
		p.array[0] = (t_link*)malloc(sizeof(t_link));
		p.array[0]->prev = NULL;
		make_path(hashtable->array[hashtable->size + 1], p.array[0]);
		find_short_path(hashtable, &p);
		while (p.array[0])
		{
			ft_printf(" %s -", p.array[0]->name);
			p.array[0] = p.array[0]->prev;
		}
		exit(1);
	}
	return (p);
}
