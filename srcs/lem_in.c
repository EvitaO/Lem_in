/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 16:14:46 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/29 14:33:38 by eutrodri      ########   odam.nl         */
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

static char	*input(t_able *hashtable)
{
	char	*line;
	char	*output;

	line = NULL;
	output = "";
	*hashtable = check_input(&line, &output);
	return (output);
}

int			main(void)
{
	t_able	hashtable;
	t_path	*p;
	char	*output;

	output = input(&hashtable);
	p = save_path(&hashtable);
	ft_printf("%s\n", output);
	free(output);
	reset_vst(p);
	walk_ants(p, hashtable.ants);
	free_p(p, &hashtable);
	free_ht(&hashtable);
	return (0);
}
