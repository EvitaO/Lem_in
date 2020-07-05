/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   id.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/19 15:58:26 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/07/05 01:13:37 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		give_id(t_node **tmp, t_node **tmp2, t_able *ht)
{
	(*tmp2)->path_id = (*tmp)->path_id;
	*tmp = *tmp2;
	ht->check = 1;
}

static void		switch_id(char *name, t_able *ht)
{
	t_node	*tmp;
	t_node	*tmp2;
	t_link	*link;

	tmp = find_room(ht, name);
	ht->check = 1;
	while (tmp && start_end_room(ht, tmp->name) != 2 && ht->check == 1)
	{
		ht->check = 0;
		link = tmp->link;
		while (link)
		{
			tmp2 = find_room(ht, link->name);
			if (start_end_room(ht, tmp2->name) == 2)
				return ;
			if (tmp2->prev == tmp)
			{
				give_id(&tmp, &tmp2, ht);
				break ;
			}
			link = link->next;
		}
	}
	if (tmp && start_end_room(ht, tmp->name) != 2)
		ht->check = -5;
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

static void		change_or_switch(t_node **tmp, t_able *ht)
{
	if ((!((*tmp)->prev2)) && (*tmp)->prev != (*tmp)->n)
		change_path_id((*tmp)->name, ht);
	else if ((*tmp)->prev2 && (*tmp)->visited == -2)
	{
		(*tmp)->prev = (*tmp)->prev2;
		(*tmp)->prev->path_id = (*tmp)->path_id;
		switch_id((*tmp)->name, ht);
	}
}

void			put_id(t_able *ht, int i)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = find_short_link_end(ht);
	if ((!(tmp)) || (tmp->path_id != -1 || tmp->visited <= 0))
		return ;
	tmp->path_id = i;
	tmp2 = ht->array[ht->size];
	while (tmp && ht->check != -5 && (!(ft_strcmp(tmp->name, tmp2->name) == 0)))
	{
		if ((!(tmp->prev)) && tmp->n->visited == tmp->visited - 1)
		{
			tmp->n->path_id = tmp->path_id;
			tmp->prev = tmp->n;
		}
		else if (tmp->prev && tmp->visited != tmp->prev->visited - 1)
			change_or_switch(&tmp, ht);
		else if (tmp->prev && tmp->visited == tmp->prev->visited + 1)
			tmp->prev = NULL;
		tmp->visited = 0;
		tmp = tmp->n;
	}
}
