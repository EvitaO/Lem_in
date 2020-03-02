/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 13:28:12 by eutrodri       #+#    #+#                */
/*   Updated: 2020/03/02 15:42:21 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ht_get(int size, t_able *hashtable)
{
	t_node		*tmp;

	tmp = hashtable->array[size];
	if (hashtable->array[size] != NULL)
	{
		tmp = hashtable->array[size];
		while (tmp->next)
		{
			ft_printf("string is %s\n", tmp->name);
			tmp = tmp->next;
		}
		ft_printf("string2 is %s\n", tmp->name);
	}
	else
	{
		ft_printf("no string there\n");
	}
}

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
	int		i;

	i = 0;
	hashtable = (t_able*)malloc(sizeof(t_able));
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

void	check_input(int *ants, char **line, t_room **room, char **str)
{
	int		size;
	t_able	hashtable;
	int		i;

	i = 0;
	*ants = count_ants(line, str);
	size = read_rooms(line, room, str);
	hashtable = rooms_hash(room, &hashtable, size);
	read_links(line, room, str);
}
