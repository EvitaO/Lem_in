/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 13:28:12 by eutrodri       #+#    #+#                */
/*   Updated: 2020/03/03 14:47:21 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_able	check_input(int *ants, char **line, t_room **room, char **str)
{
	int		size;
	t_able	hashtable;

	*ants = count_ants(line, str);
	size = read_rooms(line, room, str);
	free(*line);
	hashtable = rooms_hash(room, &hashtable, size);
	go_to_first_room(room);
	read_links(line, room, str);
	return (hashtable);
}
