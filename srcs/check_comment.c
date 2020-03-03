/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_comment.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 12:22:35 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/03/03 12:22:37 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	check_comment(char *line)
{
	if (ft_strcmp(line, "##start") == 0)
		return (1);
	else if (ft_strcmp(line, "##end") == 0)
		return (2);
	return (0);
}
