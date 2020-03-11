/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 16:14:46 by eutrodri       #+#    #+#                */
/*   Updated: 2020/03/11 10:56:40 by eutrodri      ########   odam.nl         */
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
		tmp = p->array[i];
		free_link(tmp);
		i++;
	}
	free(p->array);
}

static int	aap(char *a)
{
	char	*line;
	char	*output;
	t_room	*room;
	t_able	hashtable;
	t_path	p;
	int		i;

	a = "hallo";
	line = NULL;
	output = "";
	room = NULL;
	hashtable = check_input(&line, &room, &output);
	ft_printf("%s\n", output);
	free(output);
	free_room(&room);
	p = save_path(&hashtable);
	i = 0;
	while (i < hashtable.max_path)
	{
		if (ft_strcmp(p.array[i]->name, "start") == 0)
			all_paths(&p.array[i]);
		i++;
	}
	walking_ants(hashtable.ants, &p, hashtable.max_path);
	free_p(&p, &hashtable);
	free_ht(&hashtable);
	ft_printf("DONE\n");
	return (0);
}

int			main(void)
{
	aap("leuk");
	while (1);
	return (0);
}
