/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   use_one_p.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/04 12:39:25 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/05 13:08:35 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	use_one_p(t_path *p, t_able *hashtable)
{
	int		size;
	t_link	*tmp;

	if (p->array[0])
	{
		p->array[0]->next->visited = hashtable->ants;
		tmp = p->array[0];
		size = 0;
		while (tmp->prev)
		{
			tmp = tmp->prev;
			size++;
		}
		p->instruction = size - 1 + hashtable->ants;
	}
}
