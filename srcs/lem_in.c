/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 16:14:46 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/20 19:40:14 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		free_p(t_path *p, t_able *hashtable)
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
	free(p);
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
	t_path	*p;

	input(&hashtable);
	p = save_path(&hashtable);
	//ft_printf("p.inst.r is %i\n", p->instruction);
	reset_vst(p);
	walk_ants(p, hashtable.ants);
	free_p(p, &hashtable);
	free_ht(&hashtable);
	ft_printf("\n");
	return (0);
}
