/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 13:28:12 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/20 13:15:47 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_able	check_input(char **line, char **str)
{
	t_able	hashtable;

	hashtable.check = 0;
	hashtable.ants = count_ants(line, str);
	hashtable = read_rooms(line, &hashtable, str);
	if (hashtable.array[787] == NULL || \
		hashtable.array[788] == NULL)
		exit(ft_error(8));
	check_links(*line, &hashtable);
	free(*line);
	read_links(line, str, &hashtable);
	links_start_end(&hashtable);
	if (hashtable.cnt_e == 0 || hashtable.cnt_s == 0)
		exit(ft_error(11));
	max_path(&hashtable);
	return (hashtable);
}
