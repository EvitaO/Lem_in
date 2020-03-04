/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_input_str.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 14:45:03 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/03/04 10:18:29 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	store_input_str(char **str, char **line)
{
	char	*tmp;

	tmp = ft_strjoin(*str, *line);
	if (ft_strcmp(*str, "\0") != 0)
		free(*str);
	*str = ft_strjoin(tmp, "\n");
	free(tmp);
}
