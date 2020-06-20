/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_links.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 12:26:57 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/20 13:12:39 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	check_links(char *line, t_able *hashtable)
{
	char	**tmp;

	tmp = ft_strsplit(line, '-');
	if ((!tmp[1]) || tmp[2])
		exit(ft_error(9));
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
