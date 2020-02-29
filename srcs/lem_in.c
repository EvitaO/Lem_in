/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 16:14:46 by eutrodri       #+#    #+#                */
/*   Updated: 2020/02/29 17:55:09 by eutrodri      ########   odam.nl         */
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
	room = NULL;
	check_input(&ants, &line, &room, &output);
	ft_printf("%s\n", output);
	free(output);
	while(1);
	return (0);
}
