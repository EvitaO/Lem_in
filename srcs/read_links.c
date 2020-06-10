/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_links.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 12:26:57 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/10 13:16:35 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

// void	check_room_exists(char *name, t_room **room)
// {
// 	while ((*room)->next)
// 	{
// 		if (ft_strcmp(name, (*room)->name) == 0)
// 			return ;
// 		*room = (*room)->next;
// 	}
// 	if (ft_strcmp(name, (*room)->name) == 0)
// 		return ;
// 	else
// 		exit(ft_printf("Error check if room exists\n"));
// }

void	check_links(char *line, t_able *hashtable)
{
	char	**tmp;
	//int		i;

	tmp = ft_strsplit(line, '-');
	//i = 0;
	// while (tmp[i] && i < 2)
	// {
	// 	check_room_exists(tmp[i], room);
	// 	i++;
	// 	go_to_first_room(room);
	// }
	if (tmp[2])
		exit(ft_printf("Error check_links\n"));
	store_links(tmp, hashtable);
	free_tmp(tmp);
}

void	read_links(char **line, char **str, t_able *hashtable)
{
	while (get_next_line(0, line) == 1)
	{
		if (*line[0] != '#')
			check_links(*line, hashtable);
		store_input_str(str, line);
		free(*line);
	}
	free(*line);
}
