/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_input_str.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 14:45:03 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/03/02 17:30:32 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	store_input_str(char **str, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strjoin(*str, *line);
	if (ft_strcmp(*str, "\0") != 0)
		free(*str);
	*str = tmp;
	while (str[0][i] != '\0')
		i++;
	str[0][i] = '\n';
	str[0][i + 1] = '\0';
}
