/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hashtables.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 13:21:38 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/10 15:30:50 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		hash_co(int size, int x)
{
	int	hash;

	hash = x % size;
	return (hash);
}

void	store_check_coord(t_xy *coord, t_room *room, int index)
{
	t_info	*tmp;
	t_info	*new;

	tmp = coord->array[index];
	new = (t_info*)malloc(sizeof(t_info));
	new->x = room->x;
	new->y = room->y;
	if (!tmp)
	{
		new->next = NULL;
		coord->array[index] = new;
	}
	else
	{
		while (tmp)
		{
			if (tmp->x == room->x)
			{
				if (tmp->y == room->y)
					exit(ft_printf("Error\n"));
			}
			tmp = tmp->next;
		}
		tmp = coord->array[index];
		new->next = tmp;
		coord->array[index] = new;
	}
}

void	check_cordinates(t_room **room)
{
	t_xy	coord;
	int		index;

	index = 0;
	coord.array = (t_info**)malloc(787 * sizeof(t_info));
	ft_memset(coord.array, 0, 787 * sizeof(t_info));
	while (*room)
	{
		index = hash_co(787, (*room)->x);
		store_check_coord(&coord, *room, index);
		*room = (*room)->next;
	}
}

void	check_name_exist(t_able *hashtable, int index, t_node **node)
{
	t_node		*tmp;

	tmp = hashtable->array[index];
	while (tmp)
	{
		if (ft_strcmp(tmp->name, (*node)->name) == 0)
			exit(ft_printf("Error\n"));
		tmp = tmp->next;
	}
}

void	add_node_ht(t_able *hashtable, t_node **node, int index)
{
	t_node			*tmp;

	tmp = hashtable->array[index];
	if ((index == hashtable->size + 1 || index == hashtable->size)\
			&& tmp != NULL)
		exit(-1);
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

void	ht_put(t_able *hashtable, t_room **room, int index)
{
	t_node		*node;

	node = (t_node*)malloc(sizeof(t_node));
	node->name = ft_strdup((*room)->name);
	node->visited = 0;
	node->path_id = -1;
	node->link = NULL;
	node->prev = NULL;
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

	hashtable->array = (t_node**)malloc((size + 2) * sizeof(t_node));
	ft_memset(hashtable->array, 0, (size + 2) * sizeof(t_node));
	while ((*room)->prev)
	{
		if ((*room)->comment == 1)
			index = size;
		else if ((*room)->comment == 2)
			index = size + 1;
		else
			index = hash(hashtable->size, (*room)->name);
		ht_put(hashtable, room, index);
		*room = (*room)->prev;
	}
	if ((*room)->comment == 1)
		index = size;
	else if ((*room)->comment == 2)
		index = size + 1;
	else
		index = hash(hashtable->size, (*room)->name);
	ht_put(hashtable, room, index);
	check_cordinates(room);
	return (*hashtable);
}
