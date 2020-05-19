/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   devide_ants.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/18 16:48:09 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/05/19 20:07:21 by eutrodri      ########   odam.nl         */
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

int		choose_path(t_link *tmp, t_link *tmp2, int i, t_link *p)
{
	if (tmp->visited <= tmp2->visited)
	{
		tmp->visited++;
		tmp->next->visited++;
	}
	else if (tmp2->visited >= p->visited)
	{
		p->visited++;
		p->next->visited++;
		i = 0;
	}
	else
	{
		tmp2->visited++;
		tmp2->next->visited++;
		i++;
	}
	return (i);
}

void	reset_vst(t_path *p)
{
	int		i;

	i = 0;
	while (p->array[i])
	{
		p->array[i]->visited = 0;
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
		if (!(p->array[i + 1]))
			i = -1;
		tmp2 = p->array[i + 1];
		i = choose_path(tmp, tmp2, i, p->array[0]);
		ants--;
	}
	reset_vst(p);
}
