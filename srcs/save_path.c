/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 11:22:07 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/06/12 22:33:16 by eutienne      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			put_id(t_able *ht, int i)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = find_short_link_end(ht);
	if ((!(tmp)) || (tmp->path_id != -1 || tmp->visited <= 0))
		return ;
	tmp->visited = 0;
	// tmp2 = tmp;
	// while (tmp)
	// {
	// 	ft_printf("%s	", tmp->name);
	// 	tmp = tmp->prev;
	// }
	// tmp = tmp2;
	tmp2 = ht->array[ht->size];
	while (!(ft_strcmp(tmp->name, tmp2->name) == 0))
	{
		tmp->path_id = i;
		tmp = tmp->prev;
		tmp->visited = 0;
	}
}

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
		// tmp->visited = tmp->visited + 1000;
		link->prev->next = link;
		link = link->prev;
		make_path(tmp, link);
		//ft_printf("%i\n", link->visited);
		tmp->path_id = i;
		//ft_printf("a\n");
		tmp = tmp->prev;
		// if (tmp->visited >= 1000)
		// {
		// 	free_link(path->array[i], "prev");
		// 	return (i);
		// }
		link->prev = (t_link*)malloc(sizeof(t_link));
	}
	link->prev->name = tmp2->name;
	path->array[i]->next = link->prev;
	link->prev->prev = NULL;
}

t_path			save_path(t_able *hashtable)
{
	int		i;
	t_path	p;
	int		id;
	int		ret;
//	t_link	*q;
//	t_node	*room;

	p.array = (t_link**)malloc(sizeof(t_link) * hashtable->max_path);
	ft_memset(p.array, 0, hashtable->max_path * sizeof(t_link));
	p.instruction = 0;
	i = 0;
	ret = 0;
	hashtable->array[hashtable->size]->visited = 0;
	id = algo_b(hashtable, i);
	ft_printf("id is %i\n", id);
	while (i < id && ret != -1)
	{
		p.array[i] = (t_link*)malloc(sizeof(t_link));
		p.array[i]->prev = NULL;	
		ret = save_a_p(hashtable, i, &p);
		//make_path(hashtable->array[hashtable->size + 1], p.array[i]);
		//find_short_path(hashtable, &p, i);
		//devide_ants(p, hashtable->ants);
		i++;
	}
	ft_printf("maxp is %i\n", hashtable->max_path);
	algo_d(hashtable, id);
	// while (id < hashtable->max_path)
	// {
	// 	algo_d(hashtable, id);
	// 	id++;
	// }
	ft_printf("\n");
	return (p);
}
