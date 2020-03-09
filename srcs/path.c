/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/07 11:34:53 by eutrodri       #+#    #+#                */
/*   Updated: 2020/03/09 13:08:34 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	first_node_path(t_able *hashtable, t_path *all_paths)
{
	int		i;
	t_link	*tmp;
	t_link	*tmp2;

	i = 0;
	tmp2 = (t_link*)malloc(sizeof(t_link));
	tmp = hashtable->array[hashtable->size]->link;
	while (tmp)
	{
		tmp2 = (t_link*)malloc(sizeof(t_link));
		tmp2->name = ft_strdup("start");
		tmp2->next = (t_link*)malloc(sizeof(t_link));
		tmp2->next->name = ft_strdup(tmp->name);
		tmp2->next->next = NULL;
		all_paths->array[i] = tmp2;
		tmp = tmp->next;
		i++;
	}
}

static void	find_node(t_able *hashtable, t_path *p, int index, int index_p)
{
	int		i;
	t_link	*tmp;
	t_link	*new_link;
	t_link	*tmp_p;
	t_node	*tmp_h;

	i = 0;
	new_link = (t_link*)malloc(sizeof(t_link));
	tmp_h = hashtable->array[index];
	tmp_p = p->array[index_p];
	while (tmp_p->next)
		tmp_p = tmp_p->next;
	while (ft_strcmp(tmp_p->name, tmp_h->name) != 0)
		tmp_h = tmp_h->next;
	tmp = tmp_h->link;
	while (tmp)
	{
		new_link->name = ft_strdup(tmp->name);
		new_link->next = NULL;
		tmp_p->next = new_link;
		tmp = tmp->next;
		i++;
	}
}

static void		test(t_able *hashtable, t_path *p, int index_p)
{
	int		index_h;
	t_link	*tmp;

	tmp = p->array[index_p];
	while (tmp->next)
		tmp = tmp->next;
	index_h = hash(hashtable->size, tmp->name);
	find_node(hashtable, p, index_h, index_p);
}

t_link		*find_path(t_able *hashtable)
{
	t_path	p;
	int		i;
	int		index;
	t_link	*tmp;

	index = 0;
	p.array = (t_link**)malloc(sizeof(t_link) * hashtable->cnt_s);
	ft_memset(p.array, 0, hashtable->cnt_s * sizeof(t_link));
	i = 0;
	first_node_path(hashtable, &p);
	while (i < hashtable->cnt_s)
	{
		test(hashtable, &p, i);
		tmp = p.array[i];
		while (tmp->next)
			tmp = tmp->next;
		if (ft_strcmp(tmp->name, hashtable->array[hashtable->size + 1]->name) == 0)
			return (p.array[i]);
		else if (i == hashtable->cnt_s - 1)
			i = 0;
		else
			i++;
	}
	return (NULL);
}

void		save_path(t_able *hashtable)
{
	int		i;
	t_path	p;
	t_link	*tmp;

	p.array = (t_link**)malloc(sizeof(t_link) * hashtable->max_path);
	ft_memset(p.array, 0, hashtable->max_path * sizeof(t_link));
	i = 0;
	while (i < hashtable->max_path)
	{
		if (hashtable->cnt_s < hashtable->cnt_e)
			p.array[i] = find_path(hashtable);
		tmp = p.array[i];
		while (tmp)
		{
			ft_printf("array[%i] = %s", i, tmp->name);
			ft_printf("----->");
			tmp = tmp->next;
		}
		ft_printf("\n");
		//else
		//	*array[i] = find_path_end(hashtable);
		i++;
	}
}
