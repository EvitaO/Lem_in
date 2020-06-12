/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo_d.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/06 22:07:37 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/12 20:32:12 by eutienne      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	algo_d(t_able *ht, int id)
{
	t_node	*room;
	t_node	*room2;
	t_link	*link;
	int		i;

	i = 0;
	room = find_room(ht, ht->array[ht->size]->name);
	link = room->link;
	while (link && i == 0)
	{
		room2 = find_room(ht, link->name);
		if (room2->path_id == -1)
			i = dfs(ht, id, link->name, 1);
		link = link->next;
	}
}
