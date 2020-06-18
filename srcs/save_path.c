/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 11:22:07 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/06/18 14:18:40 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		switch_id(char* name, t_able *ht)
{
	t_node	*tmp;
	t_node	*tmp2;
	t_link	*link;
	int		i;

	tmp = find_room(ht, name);
	i = tmp->path_id;
	while (tmp && start_end_room(ht, tmp->name) != 2)
	{
		link = tmp->link;
		while (link)
		{
			tmp2 = find_room(ht, link->name);
			if (start_end_room(ht, tmp2->name) == 2)
				return ;
			if (tmp2->prev == tmp)
			{
				tmp2->path_id = i;
				tmp = tmp2;
				break ;
			}
			link = link->next;
		}
	}
}

static void		change_path_id(char *name, t_able *ht)
{
	t_node	*tmp;
	int		i;

	tmp = find_room(ht, name);
	i = tmp->path_id;
	tmp = tmp->prev;
	while (tmp && start_end_room(ht, tmp->name) != 1)
	{
		tmp->path_id = i;
		tmp = tmp->prev;
	}
}

void			put_id(t_able *ht, int i)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = find_short_link_end(ht);
	if ((!(tmp)) || (tmp->path_id != -1 || tmp->visited <= 0))
		return ;
	//tmp->visited = 0;
	tmp->path_id = i;
	tmp2 = ht->array[ht->size];
	while (tmp && (!(ft_strcmp(tmp->name, tmp2->name) == 0)))
	{
		if ((!(tmp->prev)) && tmp->n->visited == tmp->visited -1)
		{
			tmp->n->path_id = tmp->path_id;
			tmp->prev = tmp->n;
		}
		else if (tmp->prev && tmp->visited != tmp->prev->visited -1)
		{
			if ((!(tmp->prev2)) && tmp->prev && tmp->prev != tmp->n)
				change_path_id(tmp->name, ht);
			else if (tmp->prev && tmp->prev2 && tmp->visited == -2)
			{
				tmp->prev = tmp->prev2;
				tmp->prev->path_id = tmp->path_id;
				switch_id(tmp->name, ht);
			}
		}
		tmp->visited = 0;
		tmp = tmp->n;
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
		i++;
	}
	ft_printf("\n");
	return (p);
}
