/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_all.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/04 13:10:17 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/19 12:46:08 by eutrodri      ########   odam.nl         */
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
		p->array[i]->visited = size - 1;
		i++;
	}
}

void	swap_tlink(t_link *big, t_link *smal)
{
	t_link tmp;

	tmp = *big;
	*big = *smal;
	*smal = tmp;
}

int		check_if_sorted(t_path *all)
{
	int		i;
	t_link	**tmp;

	tmp = all->array;
	i = 0;
	while (tmp[i + 1])
	{
		if (tmp[i + 1])
		{
			if (tmp[i]->visited <= tmp[i + 1]->visited ||\
				tmp[i + 1]->visited <= 0)
				i++;
			else
				return (-1);
		}
	}
	return (0);
}

void	sort_all(t_path *all)
{
	t_link	*tmp;
	t_link	*tmp2;
	int		i;

	i = 0;
	while (all->array[i])
	{
		tmp = all->array[i];
		if (all->array[i + 1])
		{
			tmp2 = all->array[i + 1];
			if (tmp->visited > tmp2->visited && tmp2->visited > 0)
				swap_tlink(tmp, tmp2);
			i++;
		}
		else
			i = 0;
		if (check_if_sorted(all) == 0)
			return ;
	}
}

void	size_sort_all(t_path *all)
{
	size_path(all);
	sort_all(all);
}
