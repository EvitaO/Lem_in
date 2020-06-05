/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   walk_ants.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/20 13:13:36 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/05 13:09:37 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			check_paths(t_path *p)
{
	t_link	*tmp;
	int		i;

	i = 0;
	while (p->array[i] && p->array[i]->prev)
	{
		tmp = p->array[i];
		if (tmp->next->visited != 0)
			i++;
		else
			break ;
	}
	return (i);
}

int			ants_end(int cnt_p, int ants, t_path *p)
{
	int		cnt;
	int		i;

	i = 0;
	cnt = 0;
	while (i < cnt_p)
	{
		cnt = cnt + p->array[i]->visited;
		i++;
	}
	if (cnt == ants)
		return (0);
	return (1);
}

int			move_ants2(int print, t_link *tmp, t_link *p, int *a)
{
	if (tmp == p)
	{
		print = print_ant(print, tmp->prev->visited, tmp->name);
		tmp->visited++;
		tmp->prev->visited = 0;
	}
	else if (tmp->prev && tmp->prev->visited != 0 && tmp->prev != p->next)
	{
		tmp->visited = tmp->prev->visited;
		print = print_ant(print, tmp->visited, tmp->name);
		tmp->prev->visited = 0;
	}
	else if (tmp->prev && tmp->prev->visited != 0 && tmp->prev == p->next)
	{
		tmp->visited = *a;
		(*a)++;
		print = print_ant(print, tmp->visited, tmp->name);
		tmp->prev->visited--;
	}
	return (print);
}

int			move_ants(int print, t_link *p, int *a)
{
	t_link	*tmp;

	tmp = p;
	while (tmp->prev && tmp->prev->visited == 0)
		tmp = tmp->prev;
	if (tmp->prev && tmp->prev->visited != 0)
	{
		while (tmp && tmp->prev)
		{
			print = move_ants2(print, tmp, p, a);
			tmp = tmp->prev;
		}
	}
	return (print);
}

void		walk_ants(t_path *p, int ants)
{
	int		cnt_p;
	int		print;
	int		i;
	int		a;

	cnt_p = check_paths(p);
	i = 0;
	a = 1;
	while (ants_end(cnt_p, ants, p) != 0)
	{
		print = 0;
		while (i < cnt_p)
		{
			print = move_ants(print, p->array[i], &a);
			i++;
		}
		i = 0;
		write(1, "\n", 1);
	}
}
