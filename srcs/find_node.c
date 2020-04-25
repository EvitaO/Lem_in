/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_node.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 13:54:45 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/04/25 11:06:25 by eutienne      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_link	*find_in_p(t_path *p, int index_p)
{
	t_link		*tmp;

	tmp = p->array[index_p];
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

static t_link	*find_link(t_able *hashtable, int index, t_link *tmp_p)
{
	t_node		*tmp_h;
	t_link		*tmp;

	tmp_h = hashtable->array[index];
	while (ft_strcmp(tmp_p->name, tmp_h->name) != 0)
		tmp_h = tmp_h->next;
	tmp = tmp_h->link;
	return (tmp);
}

static t_link	*new_link(char *str)
{
	t_link		*new;

	new = (t_link*)malloc(sizeof(t_link));
	new->name = ft_strdup(str);
	new->visited = 0;
	new->next = NULL;
	return (new);
}

static int		add_link(t_able *hashtab, t_link **tmp, t_link **tmp_p)
{
	t_node		*ht;

	ht = hashtab->array[hash(hashtab->size, (*tmp)->name)];
	while (ft_strcmp(ht->name, (*tmp)->name) != 0)
		ht = ht->next;
	if (ht->visited == 1000 || ht->visited >= \
		hashtab->array[hashtab->size]->visited)
		*tmp = (*tmp)->next;
	else
	{
		(*tmp_p)->next = new_link((*tmp)->name);
		ht->visited++;
		return (1);
	}
	return (0);
}

void			find_node(t_able *hash, t_path *p, int index, int index_p)
{
	t_link	*tmp;
	t_link	*tmp_p;
	int		ret;

	ret = 0;
	tmp_p = find_in_p(p, index_p);
	tmp = find_link(hash, index, tmp_p);
	while (tmp && ret == 0)
	{
		if (ft_strcmp(tmp->name, hash->array[hash->size]->name) == 0)
			tmp = tmp->next;
		else if (ft_strcmp(tmp->name, hash->array[hash->size + 1]->name) == 0)
		{
			tmp_p->next = new_link("end");
			break ;
		}
		else
			ret = add_link(hash, &tmp, &tmp_p);
	}
}
