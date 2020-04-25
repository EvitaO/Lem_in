/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_room.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutienne <eutienne@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/25 11:05:13 by eutienne      #+#    #+#                 */
/*   Updated: 2020/04/25 11:14:33 by eutienne      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		start_end_room(t_able *hashtable, char *name)
{
	if (ft_strcmp(name, hashtable->array[hashtable->size]->name) == 0)
		return (1);
	if (ft_strcmp(name, hashtable->array[hashtable->size + 1]->name) == 0)
		return (2);
	return (0);
}

t_node	*find_room(t_able *hashtable, char *name)
{
	int		ret;
	t_node	*room;

	ret = start_end_room(hashtable, name);
	if (ret == 1)
		room = hashtable->array[hashtable->size];
	else if (ret == 2)
		room = hashtable->array[hashtable->size + 1];
	else
	{
		room = hashtable->array[hash(hashtable->size, name)];
		while (ft_strcmp(room->name, name) != 0)
			room = room->next;
	}
	return (room);
}
