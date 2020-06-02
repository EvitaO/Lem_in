/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 11:22:07 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/06/02 16:09:37 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			put_id(t_able *ht, int i)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = find_short_link_end(ht);
	if (tmp->path_id != -1 || tmp->visited <= 0)
		return ;
	tmp2 = ht->array[ht->size];
	while (!(ft_strcmp(tmp->name, tmp2->name) == 0))
	{
		tmp->path_id = i;
		tmp = tmp->prev;
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
	t_node	*tmp2;
	t_link	*link;

	tmp = ht->array[ht->size + 1];
	link = tmp->link;
	tmp = find_room(ht, link->name);
	while (link && (tmp->path_id != -1 && tmp->visited <= 0))
	{
		link = link->next;
		tmp = find_room(ht, link->name);
	}
	while (link)
	{
		tmp2 = find_room(ht, link->name);
		if (tmp2->visited > 0 && tmp2->visited < tmp->visited &&\
		 tmp2->path_id == -1)
			tmp = tmp2;
		link = link->next;
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
	t_link	*q;

	p.array = (t_link**)malloc(sizeof(t_link) * hashtable->max_path);
	ft_memset(p.array, 0, hashtable->max_path * sizeof(t_link));
	i = 0;
	hashtable->array[hashtable->size]->visited = 0;
	while (i < hashtable->max_path)
	{
		q = algo_b(hashtable, i);
		if (i == 0)
		{
			p.array[0] = (t_link*)malloc(sizeof(t_link));
			p.array[0]->prev = NULL;	
			make_path(hashtable->array[hashtable->size + 1], p.array[i]);
			find_short_path(hashtable, &p, i);
			// while (p.array[i])
			// {
	 		// 	if (p.array[i]->prev)
	 		// 		ft_printf(" %s -", p.array[i]->name);
	 		// 	else
	 		// 		ft_printf(" %s\n", p.array[i]->name);
	 		// 	p.array[i] = p.array[i]->prev;
			// }
			//./exit(1);
		}
		else
			put_id(hashtable, i);
		i++;
		remove_q(&q, hashtable);
	}
	i = 0;
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
