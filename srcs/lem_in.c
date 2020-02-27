/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 16:14:46 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/02/25 15:58:04 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	main(void)
{
	int		ants;
	char	*line;
	t_room	*room;

	line = NULL;
	ants = count_ants(&line);
	if (!ants)
		return (0);
	room = (t_room*)malloc(sizeof(t_room));
	room->prev = NULL;
	read_rooms(&line, &room);
	read_links(&line, &room);
	return (0);
}
