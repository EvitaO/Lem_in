/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/14 13:46:09 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/05/16 16:30:08 by eutrodri      ########   odam.nl         */
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
		else if (room->prev && ft_strcmp(link_room->name, room->prev->name)\
		== 0)
			link = link->next;
		else if (link_room->visited < 1)
			link = link->next;
		else
			break ;
	}
	if (link == NULL)
		room->visited = -1;
}

static void	put_prev(t_link *l, t_able *hashtable)
{
	t_node *room;
	t_node *r;
	t_link *links;

	while (l)
	{
		close_lost_rooms(find_room(hashtable, l->name), hashtable);
		room = find_room(hashtable, l->name);
		links = room->link;
		while (links)
		{
			r = find_room(hashtable, links->name);
			if (r->visited < room->visited && r->visited != -1)
			{
				if (start_end_room(hashtable, links->name) == 0)
					room->prev = r;
				else if (start_end_room(hashtable, links->name) == 1)
					r->prev = room;
			}
			links = links->next;
		}
		l = l->next;
	}
}

static void	algo1(t_able *hashtable, t_link *links, int size)
{
	t_node	*room;
	t_link	*l;

	l = links;
	while (links)
	{
		if (start_end_room(hashtable, links->name) == 0)
		{
			room = find_room(hashtable, links->name);
			if (room->visited == 0 || room->visited > size)
			{
				room->visited = size;
				algo1(hashtable, room->link, size + 1);
			}
		}
		links = links->next;
		if (links)
			ft_printf("link\n %s --> %i\n", links->name, links->visited);
	}
	put_prev(l, hashtable);
}

void		algo(t_able *hashtable)
{
	t_link	*links;
	t_link	*l;
	t_node	*room;

	links = hashtable->array[hashtable->size]->link;
	l = links;
	while (l)
	{
		room = find_room(hashtable, l->name);
		room->prev = hashtable->array[hashtable->size];
		l = l->next;
	}
	algo1(hashtable, links, 1);
	ft_printf("finished\n");
	exit(1);
}
