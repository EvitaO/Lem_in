/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   walking_ants.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 14:43:41 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/03/10 17:53:26 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	ants_on_the_walk(t_link **tmp, t_link **tmp2, int counter)
{
	if ((*tmp2)->visited == 0 && ft_strcmp((*tmp2)->name, "end") != 0)
	{
		ft_printf(" L%i-%s", (*tmp)->visited, (*tmp2)->name);
		(*tmp2)->visited = (*tmp)->visited;
		(*tmp)->visited = 0;
	}
	else if (ft_strcmp((*tmp2)->name, "end") == 0)
	{
		ft_printf(" L%i-%s", (*tmp)->visited, (*tmp2)->name);
		counter++;
		(*tmp)->visited = 0;
	}
	return (counter);
}

static int	one_path(t_link **tmp, int *a, int ants, int counter)
{
	t_link	*tmp2;

	while (*tmp)
	{
		if (ft_strcmp((*tmp)->name, "start") == 0 && tmp2->visited == 0)
		{
			if (*a <= ants)
			{
				ft_printf(" L%i-%s", *a, tmp2->name);
				tmp2->visited = *a;
				(*a)++;
			}
		}
		else if (ft_strcmp((*tmp)->name, "end") != 0 && (*tmp)->visited != 0)
			counter = ants_on_the_walk(tmp, &tmp2, counter);
		tmp2 = *tmp;
		*tmp = (*tmp)->next;
	}
	return (counter);
}

void		walking_ants(int ants, t_path *p, int size)
{
	int		a;
	int		path;
	t_link	*tmp;
	int		counter;

	a = 1;
	path = 0;
	counter = 0;
	while (counter < ants)
	{
		if (path >= size)
			path = 0;
		while (path < size)
		{
			tmp = p->array[path];
			if (tmp)
				counter = one_path(&tmp, &a, ants, counter);
			path++;
		}
		ft_printf("\n");
	}
}
