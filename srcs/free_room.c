/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_room.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 17:06:08 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/03/02 17:13:35 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			free_room(t_room **room)
{
	t_room		*tmp;

	while ((*room)->next)
	{
		tmp = *room;
		*room = (*room)->next;
		(*room)->prev = NULL;
		free(tmp->name);
		free(tmp->x);
		free(tmp->y);
		free(tmp);
	}
	free((*room)->name);
	free((*room)->x);
	free((*room)->y);
	free(*room);
}
