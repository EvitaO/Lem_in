/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/07 11:34:53 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/03/07 13:27:33 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	first_node_path(t_able *hashtable, t_link ***array)
{
	int		i;
	t_link	*tmp;

	tmp = hashtable->array[hashtable->size]->link;
	while (tmp)
	{
		i = 0;
		array[i][0]->name = ft_strdup("start");
		array[i][0]->next = malloc(sizeof(t_link));
		array[i][0]->next->name = ft_strdup(tmp->name);
		array[i][0]->next->next = NULL;
		tmp = tmp->next;
		i++;
	}
}

t_link		*find_path(t_able *hashtable)
{
	t_link	*a[hashtable->cnt_s];
	t_link	**array;
	int		i;
	//int		j;
	//t_link	tmp;

	i = 0;
	array = a;
	first_node_path(hashtable, &array);
	while (i < hashtable->cnt_s)
	{
		ft_printf("array is %s\n", array[0][i].name);
		array[0][i] = *array[0][i].next;
		ft_printf("array is %s\n", array[0][i].name);
		i++;
	}
	exit(1);
	//while (1)
	//{
	//	j = 0;
	//	while (j < hashtable->cnt_s)
	//	{
	//	}
	//}
}

void		save_path(t_able *hashtable)
{
	int		i;
	t_link	*array[hashtable->max_path];

	i = 0;
	while (i < hashtable->max_path)
	{
		if (hashtable->cnt_s <= hashtable->cnt_e)
			*array[i] = *find_path(hashtable);
		//else
		//	*array[i] = find_path_end(hashtable);
		i++;
	}
}
