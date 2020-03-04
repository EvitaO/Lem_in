/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_rooms.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 12:28:42 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/03/04 13:51:27 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	store_room(char **tmp, t_room **room)
{
	if (*room)
	{
		(*room)->next = (t_room*)malloc(sizeof(t_room));
		(*room)->next->prev = *room;
		*room = (*room)->next;
		(*room)->next = NULL;
	}
	else
	{
		*room = (t_room*)malloc(sizeof(t_room));
		(*room)->prev = NULL;
		(*room)->next = NULL;
	}
	(*room)->name = ft_strdup(tmp[0]);
	(*room)->x = ft_strdup(tmp[1]);
	(*room)->y = ft_strdup(tmp[2]);
}

int		check_rooms(char *line, t_room **room)
{
	char	**tmp;

	if (line[0] == '#')
		return (0);
	tmp = ft_strsplit(line, ' ');
	if (!tmp[1])
	{
		free_tmp(tmp);
		return (1);
	}
	valid_name(tmp[0]);
	valid_cordinates(tmp);
	if (*room)
		check_valid_room(tmp, room);
	store_room(tmp, room);
	free_tmp(tmp);
	return (0);
}

int		read_rooms(char **line, t_room **room, char **str)
{
	int	ret;
	int	i;
	int	comment;

	i = 0;
	ret = 0;
	comment = 0;
	while (ret != 1 && get_next_line(0, line) == 1)
	{
		ret = check_rooms(*line, room);
		if (*line[0] != '#')
		{
			if (ret != 1)
				(*room)->comment = comment;
			i++;
		}
		store_input_str(str, line);
		if (ret != 1)
			free(*line);
		comment = check_comment(*line);
	}
	go_to_first_room(room);
	return (i - 1);
}
