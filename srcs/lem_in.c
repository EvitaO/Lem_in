/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 16:14:46 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/04 14:37:28 by eutrodri      ########   odam.nl         */
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
	//int		i;

	input(&hashtable);
//	ft_printf("max path is %i\n", hashtable.max_path);
	p = save_path(&hashtable);
	all = save_all_p(&hashtable);
	devide_ants(&all, hashtable.ants);
	ft_printf("p.inst.r is %i		all.instr is %i\n", p.instruction, all.instruction);
	exit(1);
	// if (all.instruction > 0 && all.instruction < p.instruction)
	// {
	// 	reset_vst(&all);
	// 	walk_ants(&all, hashtable.ants);
	// }
	// else
	// {
	// 	reset_vst(&p);
	// 	walk_ants(&p, hashtable.ants);
	// }
	// exit(1);
	// i = 0;
	// while (p.array[i])
	// {
	// 	ft_printf("shortest\n");
	// 	while (p.array[i])
	// 	{
	//  		if (p.array[i]->prev)
	//  			ft_printf("%s -", p.array[i]->name);
	//  		else
	//  			ft_printf("%s\n", p.array[i]->name);
	//  		p.array[i] = p.array[i]->prev;
	// 	}
	// 	i++;
	// }
	// i = 0;
	// while (all.array[i])
	// {
	// 	ft_printf("size van path is %i			", all.array[i]->visited);
	// 	while (all.array[i])
	// 	{
	//  		if (all.array[i]->prev)
	//  			ft_printf(" %s -", all.array[i]->name);
	//  		else
	//  			ft_printf(" %s\n", all.array[i]->name);
	//  		all.array[i] = all.array[i]->prev;
	// 	}
	// 	i++;
	// }
	// exit (1);
//	i = 0;
/*	while (i < hashtable.max_path)
	{.
		if (ft_strcmp(p.array[i]->name, "start") == 0)
			all_paths(&p.array[i]);
		i++;
	}
*/	
//	walking_ants(hashtable.ants, &p, hashtable.max_path);
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
