/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_links.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 12:26:57 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/29 19:06:53 by eutienne      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	count_dash(char *line)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '-')
			cnt++;
		i++;
	}
	if (cnt != 1)
		exit(ft_error(9));
}

void		check_links(char *line, t_able *hashtable)
{
	char	**tmp;

	count_dash(line);
	tmp = ft_strsplit(line, '-');
	if ((!tmp[0]) || (!tmp[1]) || tmp[2])
		exit(ft_error(9));
	store_links(tmp, hashtable);
	free_tmp(tmp);
}

void		read_links(char **line, char **str, t_able *hashtable)
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
