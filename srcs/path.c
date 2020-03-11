/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/07 11:34:53 by eutrodri       #+#    #+#                */
/*   Updated: 2020/03/11 12:24:12 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_link	*add_first_node(char *str)
{
	t_link		*new;

	new = (t_link*)malloc(sizeof(t_link));
	new->name = ft_strdup("start");
	new->visited = 0;
	new->next = (t_link*)malloc(sizeof(t_link));
	new->next->name = ft_strdup(str);
	new->next->visited = 0;
	new->next->next = NULL;
	return (new);
}

static void		first_node_path(t_able *hashtable, t_path *all_paths)
{
	int		i;
	t_link	*tmp;
	t_node	*tmp3;

	i = 0;
	tmp = hashtable->array[hashtable->size]->link;
	while (tmp)
	{
		tmp3 = hashtable->array[hash(hashtable->size, tmp->name)];
		while (ft_strcmp(tmp3->name, tmp->name) != 0)
			tmp3 = tmp3->next;
		if (tmp3->visited == 1000 || \
			tmp3->visited >= hashtable->array[hashtable->size]->visited)
			tmp = tmp->next;
		else
		{
			tmp3->visited++;
			all_paths->array[i] = add_first_node(tmp->name);
			tmp = tmp->next;
			i++;
		}
	}
}

static void		search_node(t_able *hashtable, t_path *p, int index_p)
{
	int		index_h;
	t_link	*tmp;

	tmp = p->array[index_p];
	while (tmp->next)
		tmp = tmp->next;
	index_h = hash(hashtable->size, tmp->name);
	find_node(hashtable, p, index_h, index_p);
}

static void		free_patha(t_able *hashtable, t_path *p, int i)
{
	int			j;
	t_link		*tmp;

	j = 0;
	while (j < hashtable->cnt_s)
	{
		if (j != i)
		{
			tmp = p->array[j];
			free_link(tmp);
		}
		j++;
	}
}

t_link			*find_path(t_able *hashtable)
{
	t_path	p;
	int		i;
	t_link	*tmp;

	p.array = (t_link**)malloc(sizeof(t_link) * hashtable->cnt_s);
	ft_memset(p.array, 0, hashtable->cnt_s * sizeof(t_link));
	i = -1;
	first_node_path(hashtable, &p);
	tmp = p.array[0];
	while (ft_strcmp(tmp->name, "end") != 0)
	{
		if (i == hashtable->cnt_s - 1)
			i = 0;
		else
			i++;
		search_node(hashtable, &p, i);
		tmp = p.array[i];
		while (tmp->next)
			tmp = tmp->next;
	}
	free_patha(hashtable, &p, i);
	tmp = p.array[i];
	free(p.array);
	return (&*tmp);
}
