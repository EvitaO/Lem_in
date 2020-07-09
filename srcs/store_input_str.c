/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_input_str.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 14:45:03 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/07/09 23:57:43 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	store_input_str_first_line(char **str, char **line)
{
	char	*tmp;

	tmp = ft_strjoin(*str, *line);
	if (ft_strcmp(*str, "\0") != 0)
		free(*str);
	*str = ft_strjoin(tmp, "\0");
	free(tmp);
}

void	store_input_str(char **str, char **line)
{
	char	*tmp;

	tmp = ft_strjoin(*str, *line);
	if (ft_strcmp(*str, "\0") != 0)
		free(*str);
	*str = ft_strjoin(tmp, "\n");
	free(tmp);
}
