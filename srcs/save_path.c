/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 11:22:07 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/05/25 12:12:10 by eutrodri      ########   odam.nl         */
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

static t_node	*find_short_link_end(t_able *ht)
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
	return (tmp);
}
int			find_short_path(t_able *ht, t_path *path, int i)
{
	t_node	*tmp;
	t_node	*tmp2;
	t_link	*link;

	tmp = find_short_link_end(ht);
	if (tmp->visited >= 1000)
		return (i + 1);
	link = path->array[i];
	link->prev = (t_link*)malloc(sizeof(t_link));
	tmp2 = ht->array[ht->size];
	while (!(ft_strcmp(tmp->name, tmp2->name) == 0))
	{
		tmp->visited = tmp->visited + 1000;
		link->prev->next = link;
		link = link->prev;
		make_path(tmp, link);
		tmp = tmp->prev;
		if (tmp->visited >= 1000)
		{
			free_link(path->array[i], "prev");
			return (i);
		}
		link->prev = (t_link*)malloc(sizeof(t_link));
	}
	link->prev->name = tmp2->name;
	path->array[i]->next = link->prev;
	link->prev->prev = NULL;
	return (i + 1);
}

t_path			save_path(t_able *hashtable)
{
	int		i;
	t_path	p;

	p.array = (t_link**)malloc(sizeof(t_link) * hashtable->max_path);
	ft_memset(p.array, 0, hashtable->max_path * sizeof(t_link));
	i = 0;
	hashtable->array[hashtable->size]->visited = 0;
	algo_b(hashtable);
	while (i < hashtable->max_path)
	{
		p.array[i] = (t_link*)malloc(sizeof(t_link));
		p.array[i]->prev = NULL;	
		make_path(hashtable->array[hashtable->size + 1], p.array[i]);
		i = find_short_path(hashtable, &p, i);
	}
	ft_printf("\n");
	// i = 0;
	// while (p.array[i])
	// {
	// 	while (p.array[i])
	// 	{
	//  		if (p.array[i]->prev)
	//  			ft_printf(" %s -", p.array[i]->name);
	//  		else
	//  			ft_printf(" %s\n", p.array[i]->name);
	//  		p.array[i] = p.array[i]->prev;
	// 	}
	// 	i++;
	// }
	// exit(1);
	return (p);
}
