/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 16:14:46 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/02 16:24:43 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	free_p(t_path *p, t_able *hashtable)
{
	t_link	*tmp;
	int		i;

	i = 0;
	while (i < hashtable->max_path)
	{
		if (p->array[i])
		{
			tmp = p->array[i];
			free_link(tmp, "prev");
		}
		i++;
	}
	free(p->array);
}

static void	input(t_able *hashtable)
{
	char	*line;
	char	*output;
	t_room	*room;

	line = NULL;
	output = "";
	room = NULL;
	*hashtable = check_input(&line, &room, &output);
	ft_printf("%s\n", output);
	free(output);
	free_room(&room);
}

int			main(void)
{
	t_able	hashtable;
	t_path	p;
	t_path	all;
//	int		i;

	input(&hashtable);
	ft_printf("max path is %i\n", hashtable.max_path);
	p = save_path(&hashtable);
	ft_printf("blblblblb\n");
	all = test(&hashtable);
	if (all.array[8])
		ft_printf("B\n");
//	i = 0;
/*	while (i < hashtable.max_path)
	{.
		if (ft_strcmp(p.array[i]->name, "start") == 0)
			all_paths(&p.array[i]);
		i++;
	}
*/	
	devide_ants(&p, hashtable.ants);
//	walking_ants(hashtable.ants, &p, hashtable.max_path);
	reset_vst(&p);
	walk_ants(&p, hashtable.ants);
	free_p(&p, &hashtable);
	free_ht(&hashtable);
	ft_printf("DONE\n");
	return (0);
}
/*
int			main(void)
{
	aap("leuk");
	return (0);
}*/
