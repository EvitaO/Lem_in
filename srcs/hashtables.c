/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hashtables.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 13:21:38 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/03/03 12:26:36 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	add_node_ht(t_able *hashtable, t_node **node, int index)
{
	t_node			*tmp;

	tmp = hashtable->array[index];
	if (hashtable->array[index] != NULL)
	{
		(*node)->next = tmp;
		hashtable->array[index] = *node;
	}
	else
	{
		(*node)->next = NULL;
		hashtable->array[index] = *node;
	}
}

void	ht_put(t_able *hashtable, t_room **room, int index)
{
	t_node		*node;

	node = (t_node*)malloc(sizeof(t_node));
	node->name = ft_strdup((*room)->name);
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

t_able	rooms_hash(t_room **room, t_able *hashtable, int size)
{
	int		index;

	hashtable->array = (t_node**)malloc(size * sizeof(t_node));
	ft_memset(hashtable->array, 0, size * sizeof(t_node));
	hashtable->size = size;
	while ((*room)->next)
	{
		index = hash(hashtable->size, (*room)->name);
		ht_put(hashtable, room, index);
		*room = (*room)->next;
	}
	index = hash(hashtable->size, (*room)->name);
	ht_put(hashtable, room, index);
	return (*hashtable);
}