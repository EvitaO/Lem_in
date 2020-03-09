/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   walking_ants.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 14:43:41 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/03/09 19:29:40 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	walking_ants(int ants, t_path *p, int size)
{
	int		a;
	int		path;
	t_link	*tmp;
	t_link	*tmp2;
	int		i;

	a = 1;
	path = 0;
	i = 0;
	while (i != ants)
	{
		if (path >= size)
			path = 0;
		tmp = p->array[path];
		while (tmp)
		{
			if (ft_strcmp(tmp->name, "start") == 0 && tmp2->visited == 0)
			{
				if (a <= ants)
				{
					ft_printf("L%i-%s ", a, tmp2->name);
					tmp2->visited = a;
					a++;
				}
			}
			else if (ft_strcmp(tmp->name, "end") != 0 && tmp->visited != 0)
			{
				if (tmp2->visited == 0 && ft_strcmp(tmp2->name, "end") != 0)
				{
					ft_printf("L%i-%s ", tmp->visited, tmp2->name);
					tmp2->visited = tmp->visited;
					tmp->visited = 0;
				}
				else if (ft_strcmp(tmp2->name, "end") == 0)
				{
					ft_printf("L%i-%s ", tmp->visited, tmp2->name);
					i++;
			//		tmp2->visited++;
					tmp->visited = 0;
				}
			}
			tmp2 = tmp;
			tmp = tmp->next;
		}
		ft_printf("\n");
		path++;
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
	walking_ants(10, p, 1);
}
