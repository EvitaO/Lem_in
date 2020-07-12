/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_rooms.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 12:28:42 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/07/05 12:04:44 by eutienne      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		store_check_coord(t_xy *coord, char **crd, int index)
{
	t_info	*tmp;
	t_info	*new;

	tmp = coord->array[index];
	new = (t_info*)malloc(sizeof(t_info));
	new->x = ft_atoi2(crd[1]);
	new->y = ft_atoi2(crd[2]);
	while (tmp)
	{
		if (tmp->x == new->x)
		{
			if (tmp->y == new->y)
				exit(ft_error(6));
		}
		tmp = tmp->next;
	}
	tmp = coord->array[index];
	new->next = tmp;
	coord->array[index] = new;
}

void		check_cordinates(char **tmp, t_xy *coord)
{
	int		index;
	t_info	*new;

	index = hash(787, tmp[1]);
	if (!coord->array[index])
	{
		new = (t_info*)malloc(sizeof(t_info));
		new->x = ft_atoi2(tmp[1]);
		new->y = ft_atoi2(tmp[2]);
		new->next = NULL;
		coord->array[index] = new;
	}
	else
		store_check_coord(coord, tmp, index);
}

void		store_room(char **tmp, t_able *ht, int *comment, t_xy *coord)
{
	int		index;

	if (*comment == 1)
		index = 787;
	else if (*comment == 2)
		index = 788;
	else
		index = hash(787, tmp[0]);
	*comment = 0;
	ht_put(ht, tmp[0], index);
	check_cordinates(tmp, coord);
}

int			check_rooms(char *line, t_able *ht, int *comment, t_xy *coord)
{
	char	**tmp;

	if (ft_strcmp(line, "") == 0)
		exit(ft_error(12));
	if (line[0] == '#')
		return (0);
	else if (line[0] == 'L' || line[0] == ' ')
		exit(ft_error(2));
	count_char(line, ' ');
	tmp = ft_strsplit(line, ' ');
	if (!(tmp[1]))
	{
		free_tmp(tmp);
		return (1);
	}
	else if ((!tmp[2]) || tmp[3])
		exit(ft_error(3));
	valid_name(tmp[0]);
	store_room(tmp, ht, comment, coord);
	free_tmp(tmp);
	return (0);
}

t_able		read_rooms(char **line, t_able *ht, char **str)
{
	int		ret;
	int		comment;
	t_xy	coord;

	ret = 0;
	comment = 0;
	ht->array = (t_node**)malloc((787 + 2) * sizeof(t_node));
	ft_memset(ht->array, 0, (787 + 2) * sizeof(t_node));
	coord.array = (t_info**)malloc(787 * sizeof(t_info));
	ft_memset(coord.array, 0, 787 * sizeof(t_info));
	ht->size = 787;
	while (ret != 1 && get_next_line(0, line) == 1)
	{
		ret = check_rooms(*line, ht, &comment, &coord);
		store_input_str(str, line);
		if (comment == 0)
			comment = check_comment(*line);
		if (ret != 1)
			free(*line);
	}
	free_coord(&coord);
	return (*ht);
}
