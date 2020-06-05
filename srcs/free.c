/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 17:06:08 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/05 13:12:10 by eutrodri      ########   odam.nl         */
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

void	free_link(t_link *link, char *x)
{
	t_link		*tmp_link;

	while (link)
	{
		tmp_link = link;
		if (ft_strcmp(x, "prev") == 0)
			link = link->prev;
		else
			link = link->next;
		free(tmp_link->name);
		free(tmp_link);
	}
}

void	free_node(t_node *node)
{
	t_node		*tmp;

	while (node->next)
	{
		if (node->link)
			free_link(node->link, "next");
		tmp = node;
		node = node->next;
		free(tmp->name);
		free(tmp);
	}
	if (node->link)
		free_link(node->link, "next");
	free(node->name);
	free(node);
}

void	free_ht(t_able *hashtable)
{
	t_node		*tmp_node;
	int			i;

	i = 0;
	while (i < hashtable->size + 2)
	{
		tmp_node = hashtable->array[i];
		if (tmp_node != NULL)
			free_node(tmp_node);
		i++;
	}
	free(hashtable->array);
}
