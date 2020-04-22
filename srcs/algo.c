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

void		close_lost_rooms(t_node *room, t_able *hashtable)
{
	t_link	*link;
	t_node	*link_room;

	link = room->link;
	while (link)
	{
		link_room = find_room(hashtable, link->name);
		if (start_end_room(hashtable, link_room->name) == 1)
			link = link->next;
		else if (start_end_room(hashtable, link_room->name) == 2)
			return ;
		else if (room->prev && ft_strcmp(link_room->name, room->prev->name) == 0)
			link = link->next;
		else if (link_room->visited < 1)
			link = link->next;
		else
			break ;
	}
	if (link == NULL)
		room->visited = -1;
}		

static void	algo1(t_able *hashtable, t_link *links, int size)
{
	t_node	*room;
	t_node	*r;
	t_link	*l;

	l = links;
	while (links)
	{
		if (start_end_room(hashtable, links->name) == 0)
		{
			room = find_room(hashtable, links->name);
			if (room->visited != 1000 && (room->visited == 0 || room->visited > size))
			{
				room->visited = size;
				ft_printf("room is %s and visited is %i\n", room->name, room->visited);
				r = hashtable->array[hash(hashtable->size, room->link->name)];
				if (start_end_room(hashtable, r->name) == 1)
					room->prev = r;
				else if (start_end_room(hashtable, r->name) == 0 && r->visited > size + 1)
					r->prev = room;
				else if (start_end_room(hashtable, r->name) == 0 && r->visited == 0)
					r->prev = room;
				algo1(hashtable, room->link, size + 1);
			}
		}
		links = links->next;
	}
	while (l)
	{
		close_lost_rooms(find_room(hashtable, l->name), hashtable);
		room = find_room(hashtable, l->name);
		ft_printf("room is %s visited is %i\n", room->name, room->visited);
		l = l->next;
	}
}

void		algo(t_able *hashtable)
{
	t_link	*links;

	links = hashtable->array[hashtable->size]->link;
	algo1(hashtable, links, 1);
	ft_printf("finished\n");
}
