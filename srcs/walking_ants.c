/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   walking_ants.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 14:43:41 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/03/10 15:57:00 by eutrodri      ########   odam.nl         */
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
	while (counter != ants)
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

int	main(void)
{
	t_path	*p;
	int		i;
	char	*a;

	i = 0;
	a = "B";
	p->array = (t_link**)malloc(sizeof(t_link));
	while (i < 5)
	{
		p->array[0] = (t_link*)malloc(sizeof(t_link));
		p->array[0]->name = ft_strdup("end");
		p->array[0]->next = (t_link*)malloc(sizeof(t_link));
		p->array[0]->next->name = ft_strdup(a);
		p->array[0]->next->next = (t_link*)malloc(sizeof(t_link));
		p->array[0]->next->next->name = ft_strdup("bla");
		p->array[0]->next->next->next = (t_link*)malloc(sizeof(t_link));
		p->array[0]->next->next->next->name = ft_strdup("start");
		p->array[0]->next->next->next->next = NULL;
		i = 5;
	}
	i = 0;
	while (i < 5)
	{
		p->array[1] = (t_link*)malloc(sizeof(t_link));
		p->array[1]->name = ft_strdup("start");
		p->array[1]->next = (t_link*)malloc(sizeof(t_link));
		p->array[1]->next->name = ft_strdup("hallo");
		p->array[1]->next->next = (t_link*)malloc(sizeof(t_link));
		p->array[1]->next->next->name = ft_strdup("YES");
		p->array[1]->next->next->next = (t_link*)malloc(sizeof(t_link));
		p->array[1]->next->next->next->name = ft_strdup("end");
		p->array[1]->next->next->next->next = NULL;
		i = 5;
	}
	i = 0;
	while (i < 2)
	{
		if (ft_strcmp(p->array[i]->name, "start") == 0)
			all_paths(&p->array[i]);
		i++;
		ft_printf("A\n");
	}
	ft_printf("A\n");
	walking_ants(10, p, 2);
}
