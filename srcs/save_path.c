/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 11:22:07 by eovertoo       #+#    #+#                */
/*   Updated: 2020/03/10 15:58:50 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		save_path(t_able *hashtable)
{
	int		i;
	t_path	p;
	t_link	*tmp;

	p.array = (t_link**)malloc(sizeof(t_link) * hashtable->max_path);
	ft_memset(p.array, 0, hashtable->max_path * sizeof(t_link));
	i = 0;
	hashtable->array[hashtable->size]->visited = 1;
	while (i < hashtable->max_path)
	{
		if (hashtable->cnt_s < hashtable->cnt_e)
			p.array[i] = find_path(hashtable);
		tmp = p.array[i];
		while (tmp)
		{
			ft_printf("array[%i] = %s", i, tmp->name);
			tmp = tmp->next;
			if (tmp)
				ft_printf("----->");
		}
		ft_printf("\n");
		reset(hashtable, p.array[i]);
		//else
		//	*array[i] = find_path_end(hashtable);
		hashtable->array[hashtable->size]->visited++;
		hashtable->cnt_s--;
		i++;
	}
	exit(1);
}
