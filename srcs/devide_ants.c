/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   devide_ants.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/18 16:48:09 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/05/18 17:34:27 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	size_path(t_path *p)
{
	int		i;
	int		size;
	t_link	*tmp;

	i = 0;
	while (p->array[i])
	{
		tmp = p->array[i];
		size = 0;
		while (tmp->prev)
		{
			tmp = tmp->prev;
			size++;
		}
		p->array[i]->visited = size;
		i++;
	}
}

void	devide_ants(t_path *p, int ants)
{
	t_link	*tmp;
	t_link	*tmp2;
	int		i;

	i = 0;
	if (!(p->array[i + 1]))
	{
		p->array[i]->next->visited = ants;
		ft_printf("%i\n", p->array[i]->next->visited);
		exit(1);
		//return ;
	}
	size_path(p);
	while (ants != 0)
	{
		tmp = p->array[i];
		tmp2 = p->array[i + 1];
		if (tmp->visited + tmp->next->visited <= tmp2->visited + tmp2->next->visited)
		{
			tmp->visited++;
			tmp->next->visited++;
		}
		else if (tmp2->visited + tmp2->next->visited >= p->array[0]->visited + p->array[0]->next->visited)
		{
			p->array[0]->visited++;
			p->array[0]->next->visited++;
			i = 0;
		}
		else
		{
			tmp2->visited++;
			tmp2->next->visited++;
			i++;
		}
		ants--;
	}
}