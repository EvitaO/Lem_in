/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   devide_ants.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/18 16:48:09 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/19 16:05:34 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		choose_path(t_link *tmp, t_link *tmp2, int i, t_link *p)
{
	if (tmp != p && p->visited <= tmp->visited && p->visited <= tmp2->visited)
	{
		p->visited++;
		p->next->visited++;
		i = 0;
	}
	else if (tmp->visited <= tmp2->visited)
	{
		tmp->visited++;
		tmp->next->visited++;
	}
	else
	{
		tmp2->visited++;
		tmp2->next->visited++;
		i++;
	}
	return (i);
}

void	reset_vst(t_path *p)
{
	int		i;

	i = 0;
	while (p->array[i])
	{
		p->array[i]->visited = 0;
		i++;
	}
}

void	all_instruction(t_path *p)
{
	int	i;
	int	instr;

	i = 0;
	instr = 0;
	while (p->array[i] && p->array[i]->prev && p->array[i]->next->visited > 0)
	{
		if (instr == 0 || instr <= p->array[i]->visited)
			instr = p->array[i]->visited;
		i++;
	}
	p->instruction = instr;
}

void	devide_ants(t_path *p, int ants)
{
	t_link	*tmp;
	t_link	*tmp2;
	int		i;

	i = 0;
	if (!(p->array[i + 1] && p->array[i + 1]->prev))
	{
		p->array[i]->next->visited = ants;
		p->instruction = p->array[i]->visited + ants;
		return ;
	}
	while (ants != 0)
	{
		tmp = p->array[i];
		if (!(p->array[i + 1] && p->array[i + 1]->prev))
		{
			i = 0;
			tmp2 = p->array[i];
		}
		else
			tmp2 = p->array[i + 1];
		i = choose_path(tmp, tmp2, i, p->array[0]);
		ants--;
	}
	all_instruction(p);
}
