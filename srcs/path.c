/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/07 11:34:53 by eutrodri       #+#    #+#                */
/*   Updated: 2020/03/09 19:44:59 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	first_node_path(t_able *hashtable, t_path *all_paths)
{
	int		i;
	t_link	*tmp;
	t_link	*tmp2;
	t_node	*tmp3;

	i = 0;
	tmp2 = (t_link*)malloc(sizeof(t_link));
	tmp = hashtable->array[hashtable->size]->link;
	while (tmp)
	{
		tmp3 = hashtable->array[hash(hashtable->size, tmp->name)];
		while (ft_strcmp(tmp3->name, tmp->name) != 0)
			tmp3 = tmp3->next;
		if (tmp3->visited == 1000)
			tmp = tmp->next;
		else
		{
			tmp2 = (t_link*)malloc(sizeof(t_link));
			tmp2->name = ft_strdup("start");
			tmp2->next = (t_link*)malloc(sizeof(t_link));
			tmp2->next->name = ft_strdup(tmp->name);
			tmp2->next->next = NULL;
			hashtable->array[hash(hashtable->size, tmp->name)]->visited = 1;
			all_paths->array[i] = tmp2;
			tmp = tmp->next;
			i++;
		}
	}
}

static void	find_node(t_able *hashtable, t_path *p, int index, int index_p)
{
	int		i;
	t_link	*tmp;
	t_link	*new_link;
	t_link	*tmp_p;
	t_node	*tmp_h;
	t_able	*c;

	i = 0;
	c = hashtable;
	new_link = (t_link*)malloc(sizeof(t_link));
	tmp_h = hashtable->array[index];
	tmp_p = p->array[index_p];
	while (tmp_p->next)
		tmp_p = tmp_p->next;
	while (ft_strcmp(tmp_p->name, tmp_h->name) != 0)
		tmp_h = tmp_h->next;
	tmp = tmp_h->link;
	if (ft_strcmp(tmp->name, hashtable->array[hashtable->size]->name) == 0)
		tmp = tmp->next;
	while (tmp)
	{
		// ft_printf("tmp is %s--------\n", tmp->name);
		if (ft_strcmp(tmp->name, hashtable->array[hashtable->size + 1]->name) == 0)
		{
			new_link->name = ft_strdup("end");
			new_link->next = NULL;
			tmp_p->next = new_link;
			break ;
		}
		// else
		// {
		// 	ft_printf("b;alala\n");
		// 	while (ft_strcmp(c->array[hash(c->size, tmp->name)]->name, tmp->name) != 0)
		// 		c->array[hash(c->size, tmp->name)] = c->array[hash(c->size, tmp->name)]->next;
			// if (hashtable->array[hash(hashtable->size, tmp->name)]->visited == 1)
			// {
			// 	if (tmp->next)
			// 		tmp = tmp->next;
			// 	else
			// 		tmp = tmp_h->link;	
			// 	ft_printf("tmp next is %s\n", tmp->name);
			// }
			else
			{
				new_link->name = ft_strdup(tmp->name);
				new_link->next = NULL;
				// while (ft_strcmp(c->array[hash(c->size, tmp->name)]->name, tmp->name) != 0)
				// 	c->array[hash(c->size, tmp->name)] = c->array[hash(c->size, tmp->name)]->next;
				// c->array[hash(c->size, tmp->name)]->visited = 1;
				// ft_printf("name is %s\n", new_link->name);
				tmp_p->next = new_link;
				tmp = tmp->next;
				i++;
				// ft_printf("koekeoekoe\n");
			}
		// }
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
		if (ft_strcmp(tmp->name, "end") == 0)
			return (p.array[i]);
		else if (i == hashtable->cnt_s - 1)
			i = 0;
		else
			i++;
	}
	return (NULL);
}

void		reset(t_able *hashtable, t_link *p)
{
	int		index_p;
	int		index_h;
	t_link	*tmp;
	t_node	*tmp2;

	index_p = 0;
	index_h = 0;
	tmp = p;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, "start") == 0 || ft_strcmp(tmp->name, "end") == 0)
			tmp = tmp->next;
		else
		{
			tmp2 = hashtable->array[hash(hashtable->size, tmp->name)];
			while (ft_strcmp(tmp->name, tmp2->name) != 0)
				tmp2 = tmp2->next;
			tmp2->visited = 1000;
			tmp = tmp->next;
		}
	}
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
		reset(hashtable, p.array[i]);
		//else
		//	*array[i] = find_path_end(hashtable);
		i++;
	}
}

// printing loop
// tmp = p.array[i];
// 		while (tmp)
// 		{
// 			ft_printf("array[%i] = %s", i, tmp->name);
// 			ft_printf("----->");
// 			tmp = tmp->next;
// 		}
// 		ft_printf("\n");