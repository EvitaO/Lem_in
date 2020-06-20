/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hashtables.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 13:21:38 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/20 19:07:16 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	check_name_exist(t_able *hashtable, int index, t_node **node)
{
	t_node		*tmp;

	tmp = hashtable->array[index];
	while (tmp)
	{
		if (ft_strcmp(tmp->name, (*node)->name) == 0)
			exit(ft_error(5));
		tmp = tmp->next;
	}
}

void	add_node_ht(t_able *hashtable, t_node **node, int index)
{
	t_node			*tmp;

	tmp = hashtable->array[index];
	if (tmp && (index == hashtable->size + 1 || index == hashtable->size))
		exit(ft_error(7));
	if (index == hashtable->size + 1 || index == hashtable->size)
		check_name_exist(hashtable, hash(787, (*node)->name), node);
	check_name_exist(hashtable, 787, node);
	check_name_exist(hashtable, 788, node);
	if (hashtable->array[index] != NULL)
	{
		check_name_exist(hashtable, index, node);
		(*node)->next = tmp;
		hashtable->array[index] = *node;
	}
	else
	{
		(*node)->next = NULL;
		hashtable->array[index] = *node;
	}
}

void	ht_put(t_able *hashtable, char *name, int index)
{
	t_node		*node;

	node = (t_node*)malloc(sizeof(t_node));
	node->name = ft_strdup(name);
	node->visited = 0;
	node->path_id = -1;
	node->link = NULL;
	node->prev = NULL;
	node->prev2 = NULL;
	node->n = NULL;
	add_node_ht(hashtable, &node, index);
}

int		hash(int size, char *key)
{
	int	hash;
	int	i;

	i = 0;
	hash = 0;
	while (key && key[i] != '\0')
	{
		hash = (hash + key[i]) % size;
		i++;
	}
	return (hash);
}
