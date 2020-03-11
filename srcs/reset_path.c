/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset_path.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 11:17:32 by eovertoo       #+#    #+#                */
/*   Updated: 2020/03/11 10:33:20 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		reset(t_able *hashtable, t_link *p)
{
	t_link	*tmp;
	t_node	*tmp2;

	tmp = p;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, "start") == 0 || \
			ft_strcmp(tmp->name, "end") == 0)
			tmp = tmp->next;
		else
		{
			tmp2 = hashtable->array[hash(hashtable->size, tmp->name)];
			while (ft_strcmp(tmp->name, tmp2->name) != 0)
				tmp2 = tmp2->next;
			tmp2->visited = 1000;
			tmp = tmp->next;
		}
	}
}
