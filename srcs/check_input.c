/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 13:28:12 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/29 13:20:44 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	print_directly(t_able *hashtable)
{
	int		ants;
	int		i;

	i = 2;
	ants = hashtable->ants;
	ft_printf("L%i-%s", 1, hashtable->array[hashtable->size + 1]->name);
	while (i <= ants)
	{
		ft_printf(" L%i-%s", i, hashtable->array[hashtable->size + 1]->name);
		i++;
	}
	ft_printf("\n");
}

static void	directly_con(t_able *hashtable)
{
	t_node	*s;
	t_node	*e;
	t_link	*tmp;

	s = hashtable->array[hashtable->size];
	e = hashtable->array[hashtable->size + 1];
	tmp = s->link;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, e->name) == 0)
		{
			print_directly(hashtable);
			exit(1);
		}
		tmp = tmp->next;
	}
}

t_able		check_input(char **line, char **str)
{
	t_able	hashtable;

	hashtable.check = 0;
	hashtable.ants = count_ants(line, str);
	hashtable = read_rooms(line, &hashtable, str);
	if (hashtable.array[787] == NULL || \
		hashtable.array[788] == NULL)
		exit(ft_error(8));
	check_links(*line, &hashtable);
	free(*line);
	read_links(line, str, &hashtable);
	links_start_end(&hashtable);
	if (hashtable.cnt_e == 0 || hashtable.cnt_s == 0)
		exit(ft_error(11));
	directly_con(&hashtable);
	max_path(&hashtable);
	return (hashtable);
}
