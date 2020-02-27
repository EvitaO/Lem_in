/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_input_str.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 14:45:03 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/02/27 15:16:21 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	store_input_str(char **str, char **line)
{
	int	i;

	i = 0;
	*str = ft_strjoin(*str, *line);
	while (str[0][i] != '\0')
		i++;
	str[0][i] = '\n';
}
