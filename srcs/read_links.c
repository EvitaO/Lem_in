/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_links.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 12:26:57 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/07/05 12:04:36 by eutienne      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		count_char(char *line, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (line[i] != '\0')
	{
		if (line[i] == c)
			cnt++;
		i++;
	}
	if (c == '-' && cnt != 1)
		exit(ft_error(9));
	if (c == ' ' && cnt != 2 && cnt != 0)
		exit(ft_error(3));
}

void		check_links(char *line, t_able *hashtable)
{
	char	**tmp;

	count_char(line, '-');
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
		else if (check_comment(*line) != 0)
			exit(ft_error(12));
		store_input_str(str, line);
		free(*line);
	}
	free(*line);
}
