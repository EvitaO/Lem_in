/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 16:14:46 by eutrodri       #+#    #+#                */
/*   Updated: 2020/03/02 18:12:31 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	main(void)
{
	int		ants;
	char	*line;
	char	*output;
	t_room	*room;
	t_able	hashtable;

	line = NULL;
	output = "";
	room = NULL;
	hashtable = check_input(&ants, &line, &room, &output);
	if (hashtable.size)
		ft_printf("a\n");
	ft_printf("%s\n", output);
	free(output);
	free_room(&room);
	while(1);
	return (0);
}
