/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/07 11:34:53 by eutrodri       #+#    #+#                */
/*   Updated: 2020/03/07 15:37:38 by eovertoo      ########   odam.nl         */
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

static void	find_node(t_able *hashtable, t_path *all_paths, int index, int index_all_path)
{
	int		i;
	t_link	*tmp;
	t_link	*tmp2;
	t_node	*tmp3;

	i = 0;
	tmp2 = (t_link*)malloc(sizeof(t_link));
	tmp3 = hashtable->array[index];
	while (ft_strcmp(all_paths->array[index_all_path]->next->name, tmp3->name) != 0)
		tmp3 = tmp3->next;
	tmp = tmp3->link;
	while (tmp)
	{
		tmp2->name = ft_strdup(tmp->name);
		tmp2->next = NULL;
		all_paths->array[index_all_path]->next->next = tmp2;
		tmp = tmp->next;
		i++;
	}
}

t_link		*find_path(t_able *hashtable)
{
	t_path	all_paths;
	int		i;
	int		index;

	index = 0;
	all_paths.array = (t_link**)malloc(sizeof(t_link) * hashtable->cnt_s);
	ft_memset(all_paths.array, 0, hashtable->cnt_s * sizeof(t_link));
	i = 0;
	first_node_path(hashtable, &all_paths);
	while (i < hashtable->cnt_s)
	{
		ft_printf("array[%i] is %s-----%s\n", i, all_paths.array[i]->name, all_paths.array[i]->next->name);
		i++;
	}
	i = 0;
	while (i < hashtable->cnt_s)
	{
		index = hash(hashtable->size, all_paths.array[i]->next->name);
		find_node(hashtable, &all_paths, index, i);
		i++;
	}
	i = 0;
	while (i < hashtable->cnt_s)
	{
		ft_printf("array[%i] is %s-----%s\n", i, all_paths.array[i]->next->name, all_paths.array[i]->next->next->name);
		i++;
	}
	exit(1);
}

void		save_path(t_able *hashtable)
{
	int		i;
	t_path	p;

	p.array = (t_link**)malloc(sizeof(t_link) * hashtable->max_path);
	ft_memset(p.array, 0, hashtable->max_path * sizeof(t_link));
	i = 0;
	while (i < hashtable->max_path)
	{
		if (hashtable->cnt_s <= hashtable->cnt_e)
			p.array[i] = find_path(hashtable);
		//else
		//	*array[i] = find_path_end(hashtable);
		i++;
	}
}
