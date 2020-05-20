/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 16:14:46 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/05/20 15:43:29 by eutrodri      ########   odam.nl         */
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
//	int		i;

	input(&hashtable);
	p = save_path(&hashtable);
//	i = 0;
/*	while (i < hashtable.max_path)
	{
		if (ft_strcmp(p.array[i]->name, "start") == 0)
			all_paths(&p.array[i]);
		i++;
	}
*/	
	devide_ants(&p, hashtable.ants);
//	walking_ants(hashtable.ants, &p, hashtable.max_path);
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
