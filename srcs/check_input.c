/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 13:28:12 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/03/02 13:51:18 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	check_input(int *ants, char **line, t_room **room, char **str)
{
	int		size;
	t_able	hashtable;
	int		i;

	i = 0;
	*ants = count_ants(line, str);
	size = read_rooms(line, room, str);
	hashtable = rooms_hash(room, &hashtable, size);
	read_links(line, room, str);
}
