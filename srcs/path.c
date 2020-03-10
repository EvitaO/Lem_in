/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/07 11:34:53 by eutrodri       #+#    #+#                */
/*   Updated: 2020/03/10 11:38:02 by eovertoo      ########   odam.nl         */
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
	//tmp2 = (t_link*)malloc(sizeof(t_link));
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
			tmp2 = (t_link*)malloc(sizeof(t_link));
			tmp2->name = ft_strdup("start");
			tmp2->next = (t_link*)malloc(sizeof(t_link));
			tmp2->next->name = ft_strdup(tmp->name);
			tmp2->next->next = NULL;
			tmp3->visited++;
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
	t_node	*ht;

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
		ft_printf("htstart visited = %i\n", hashtable->array[hashtable->size]->visited);
		ht = hashtable->array[hash(hashtable->size, tmp->name)];
		if (ft_strcmp(tmp->name, hashtable->array[hashtable->size]->name) == 0)
			tmp = tmp->next;
		else if (ft_strcmp(tmp->name, hashtable->array[hashtable->size + 1]->name) == 0)
		{
			new_link->name = ft_strdup("end");
			new_link->next = NULL;
			tmp_p->next = new_link;
			break ;
		}
		else
		{
			while (ft_strcmp(ht->name, tmp->name) != 0)
			{
				ft_printf("b;alala\n");
				ht = ht->next;
			}
			ft_printf("%i\n", ht->visited);
			if (ht->visited == 1000 || ht->visited >= hashtable->array[hashtable->size]->visited)
			{
				ft_printf("22222\n");
				tmp = tmp->next;
			}
			else
			{
				ft_printf("bbbbbb\n");
				new_link->name = ft_strdup(tmp->name);
				new_link->next = NULL;
				while (ft_strcmp(ht->name, tmp->name) != 0)
					ht = ht->next;
				ht->visited++;
				tmp_p->next = new_link;
				// break ;
				tmp = tmp->next;
				i++;
				//ft_printf("koekeoekoe\n");
			}
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

t_link		*find_path(t_able *hashtable)
{
	t_path	p;
	int		i;
	int		index;
	t_link	*tmp;

	index = 0;
	p.array = (t_link**)malloc(sizeof(t_link) * hashtable->cnt_s);
	ft_memset(p.array, 0, hashtable->cnt_s * sizeof(t_link));
	i = -1;
	first_node_path(hashtable, &p);
	tmp = p.array[0];
	while (ft_strcmp(tmp->name, "end") != 0)//verkeerd statement was i <hashtable->cnt_s
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
	return (p.array[i]);
}
