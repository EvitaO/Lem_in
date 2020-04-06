/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/14 13:46:09 by eovertoo       #+#    #+#                */
/*   Updated: 2020/03/14 15:27:28 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	algo1(t_able *hashtable, t_link *links, int size)
{
	t_node	*room;

	while (links)
	{
		if (ft_strcmp(links->name, hashtable->array[hashtable->size]->name) != 0 && ft_strcmp(links->name, hashtable->array[hashtable->size + 1]->name) != 0)
		{
			room = hashtable->array[hash(hashtable->size, links->name)];
			while (ft_strcmp(room->name, links->name) != 0)
				room = room->next;
			if (room->visited != 1000 && (room->visited == 0 || room->visited > size))
			{
				room->visited = size;
				ft_printf("room is %s and visited is %i\n", room->name, room->visited);
				algo1(hashtable, room->link, size + 1);
			}
		}
		links = links->next;
	}
}

void		algo(t_able *hashtable)
{
	t_link	*links;

	links = hashtable->array[hashtable->size]->link;
	algo1(hashtable, links, 1);
	ft_printf("finished\n");
}
