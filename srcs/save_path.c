/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 11:22:07 by eovertoo       #+#    #+#                */
/*   Updated: 2020/03/11 10:40:50 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_path		save_path(t_able *hashtable)
{
	int		i;
	t_path	p;

	p.array = (t_link**)malloc(sizeof(t_link) * hashtable->max_path);
	ft_memset(p.array, 0, hashtable->max_path * sizeof(t_link));
	i = 0;
	hashtable->array[hashtable->size]->visited = 1;
	while (i < hashtable->max_path)
	{
		if (hashtable->cnt_s < hashtable->cnt_e)
		{
			algo(hashtable);
			exit(1);
		}
		//	p.array[i] = find_path(hashtable);
		reset(hashtable, p.array[i]);
		//else
		//	*array[i] = find_path_end(hashtable);
		hashtable->array[hashtable->size]->visited++;
		hashtable->cnt_s--;
		i++;
	}
	return (p);
}
