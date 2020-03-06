/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_links.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 12:09:21 by eutrodri       #+#    #+#                */
/*   Updated: 2020/03/06 11:58:24 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		links_start_end(t_able *hashtable)
{
	t_node	*tmp;
	t_link	*tmp2;

	hashtable->cnt_s = 0;
	hashtable->cnt_e = 0;
	tmp = hashtable->array[hashtable->size];
	if (tmp->link)
	{
		tmp2 = tmp->link;
		while (tmp2)
		{
			tmp2 = tmp2->next;
			hashtable->cnt_s++;
		}
	}
	tmp = hashtable->array[hashtable->size + 1];
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
	if (ft_strcmp(tmp, hashtable->array[hashtable->size]->name) == 0)
		return (hashtable->size);
	else if (ft_strcmp(tmp, hashtable->array[hashtable->size + 1]->name) == 0)
		return (hashtable->size + 1);
	else
		return (hash(hashtable->size, tmp));
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
	}
	else
	{
		t2 = (*t)->link;
		while (t2 && t2->next)
			t2 = t2->next;
		t2->next = (t_link*)malloc(sizeof(t_link));
		t2 = t2->next;
		t2->name = ft_strdup(new);
		t2->next = NULL;
	}
}

void		store_links(char **tmp, t_able *hashtable)
{
	int		index_a;
	int		index_b;
	t_node	*t;
	t_node	*s;

	index_a = find_index(tmp[0], hashtable);
	index_b = find_index(tmp[1], hashtable);
	t = hashtable->array[index_a];
	s = hashtable->array[index_b];
	put_link(&t, tmp[0], tmp[1]);
	put_link(&s, tmp[1], tmp[0]);
}
