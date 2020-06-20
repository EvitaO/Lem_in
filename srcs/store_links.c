/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_links.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 12:09:21 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/20 18:37:16 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		links_start_end(t_able *hashtable)
{
	t_node	*tmp;
	t_link	*tmp2;

	hashtable->cnt_s = 0;
	hashtable->cnt_e = 0;
	tmp = hashtable->array[787];
	if (tmp->link)
	{
		tmp2 = tmp->link;
		while (tmp2)
		{
			tmp2 = tmp2->next;
			hashtable->cnt_s++;
		}
	}
	tmp = hashtable->array[788];
	if (tmp->link)
	{
		tmp2 = tmp->link;
		while (tmp2)
		{
			tmp2 = tmp2->next;
			hashtable->cnt_e++;
		}
	}
}

static int	find_index(char *tmp, t_able *hashtable)
{
	if (ft_strcmp(tmp, hashtable->array[787]->name) == 0)
		return (787);
	else if (ft_strcmp(tmp, hashtable->array[788]->name) == 0)
		return (788);
	else
		return (hash(787, tmp));
}

void		put_link(t_node **t, char *name, char *new)
{
	t_link	*t2;

	while (ft_strcmp((*t)->name, name) != 0)
		*t = (*t)->next;
	if (!((*t)->link))
	{
		(*t)->link = (t_link*)malloc(sizeof(t_link));
		(*t)->link->name = ft_strdup(new);
		(*t)->link->next = NULL;
		(*t)->link->prev = NULL;
	}
	else
	{
		t2 = (*t)->link;
		while (t2 && t2->next)
			t2 = t2->next;
		t2->next = (t_link*)malloc(sizeof(t_link));
		t2->next->prev = t2;
		t2 = t2->next;
		t2->name = ft_strdup(new);
		t2->next = NULL;
	}
}

void		check_room_exists(char *name, t_able *hashtable, int index)
{
	t_node		*tmp;

	tmp = hashtable->array[index];
	while (tmp && tmp->next)
	{
		if (ft_strcmp(name, tmp->name) == 0)
			return ;
		tmp = tmp->next;
	}
	if (tmp && ft_strcmp(name, tmp->name) == 0)
		return ;
	else
		exit(ft_error(10));
}

void		store_links(char **tmp, t_able *hashtable)
{
	int		index_a;
	int		index_b;
	t_node	*t;
	t_node	*s;

	index_a = find_index(tmp[0], hashtable);
	index_b = find_index(tmp[1], hashtable);
	check_room_exists(tmp[0], hashtable, index_a);
	check_room_exists(tmp[1], hashtable, index_b);
	t = hashtable->array[index_a];
	s = hashtable->array[index_b];
	put_link(&t, tmp[0], tmp[1]);
	put_link(&s, tmp[1], tmp[0]);
}
