/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 13:28:12 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/06 15:42:39 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_able	check_input(char **line, t_room **room, char **str)
{
	t_able	hashtable;

	hashtable.ants = count_ants(line, str);
	hashtable.size = read_rooms(line, room, str);
	hashtable = rooms_hash(room, &hashtable, hashtable.size);
	if (hashtable.array[hashtable.size] == NULL || \
		hashtable.array[hashtable.size + 1] == NULL)
		exit(-1);
	go_to_first_room(room);
	check_links(*line, room, &hashtable);
	free(*line);
	go_to_first_room(room);
	read_links(line, room, str, &hashtable);
	links_start_end(&hashtable);
	max_path(&hashtable);
	return (hashtable);
}
