/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 16:14:46 by eutrodri       #+#    #+#                */
/*   Updated: 2020/02/27 15:31:52 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	main(void)
{
	int		ants;
	char	*line;
	char	*output;
	t_room	*room;

	line = NULL;
	output = "";
	room = (t_room*)malloc(sizeof(t_room));
	room->prev = NULL;
	check_input(&ants, &line, &room, &output);
	ft_printf("%s\n", output);
	free(output);
	while(1);
	return (0);
}
