/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 16:14:46 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/12 22:38:59 by eutienne      ########   odam.nl         */
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

	line = NULL;
	output = "";
	*hashtable = check_input(&line, &output);
	ft_printf("%s\n", output);
	free(output);
}

int			main(void)
{
	t_able	hashtable;
	t_path	p;
	t_path	all;
//	int		i;

	input(&hashtable);
//	exit (1);
//	ft_printf("max path is %i\n", hashtable.max_path);
	p = save_path(&hashtable);
	ft_printf("komt hier\n");
	all = save_all_p(&hashtable);
	ft_printf("2komt hier\n");
	size_path(&p);
	devide_ants(&p, hashtable.ants);
	if (all.array[1] && all.array[1]->prev)
		devide_ants(&all, hashtable.ants);
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
	// 	ft_printf("\n");
	// 	i++;
	// }
	// ft_printf("\n");
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
	// 	ft_printf("\n");
	// 	i++;
	// }
	// exit (1);
	ft_printf("p.inst.r is %i		all.instr is %i\n", p.instruction, all.instruction);
	if (all.instruction > 0 && all.instruction < p.instruction)
	{
		reset_vst(&all);
		walk_ants(&all, hashtable.ants);
	}
	else
	{
		reset_vst(&p);
		walk_ants(&p, hashtable.ants);
	}
	exit(1);
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
