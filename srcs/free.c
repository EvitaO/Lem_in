/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_room.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 17:06:08 by eutrodri       #+#    #+#                */
/*   Updated: 2020/03/04 12:08:53 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_room(t_room **room)
{
	t_room	*tmp;

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

void	free_tmp(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

void	free_ht(t_able *hashtable)
{
	t_node		*tmp;
	t_node		*tmp_node;
	int			i;

	i = 0;
	while (i < hashtable->size)
	{
		tmp_node = hashtable->array[i];
		if (tmp_node != NULL)
		{
			while (tmp_node->next)
			{
				tmp = tmp_node;
				tmp_node = tmp_node->next;
				free(tmp->name);
				free(tmp);
			}
			free(tmp_node->name);
			free(tmp_node);
		}
		i++;
	}
	free(hashtable->array);
}
