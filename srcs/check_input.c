/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 13:28:12 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/02/27 14:32:20 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	check_input(int *ants, char **line, t_room **room, char **str)
{
	*ants = count_ants(line, str);
	read_rooms(line, room, str);
	read_links(line, room, str);
}
