/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 16:14:46 by eutrodri       #+#    #+#                */
/*   Updated: 2020/03/07 11:34:44 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	aap(char *a)
{
	char	*line;
	char	*output;
	t_room	*room;
	t_able	hashtable;

	a = "hallo";
	line = NULL;
	output = "";
	room = NULL;
	hashtable = check_input(&line, &room, &output);
	ft_printf("%s\n", output);
	free(output);
	free_room(&room);
	save_path(&hashtable);
	free_ht(&hashtable);
	return (0);
}

int			main(void)
{
	aap("leuk");
	while (1);
	return (0);
}
