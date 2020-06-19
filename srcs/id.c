/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   id.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/19 15:58:26 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/19 15:58:43 by eutrodri      ########   odam.nl         */
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
	tmp->path_id = i;
	tmp2 = ht->array[ht->size];
	while (tmp && (!(ft_strcmp(tmp->name, tmp2->name) == 0)))
	{
		if ((!(tmp->prev)) && tmp->n->visited == tmp->visited - 1)
		{
			tmp->n->path_id = tmp->path_id;
			tmp->prev = tmp->n;
		}
		else if (tmp->prev && tmp->visited != tmp->prev->visited - 1)
		{
			if ((!(tmp->prev2)) && tmp->prev != tmp->n)
				change_path_id(tmp->name, ht);
			else if (tmp->prev2 && tmp->visited == -2)
			{
				tmp->prev = tmp->prev2;
				tmp->prev->path_id = tmp->path_id;
				switch_id(tmp->name, ht);
			}
		}
		else if (tmp->prev && tmp->visited == tmp->prev->visited + 1)
			tmp->prev = NULL;
		tmp->visited = 0;
		tmp = tmp->n;
	}
}