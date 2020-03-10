/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   all_paths.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 13:55:23 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/03/10 15:52:04 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	all_paths(t_link **path)
{
	t_link *tmp;
	t_link *tmp2;
	t_link *tmp3;

	tmp = *path;
	tmp3 = NULL;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		tmp->next = tmp3;
		tmp3 = tmp;
		tmp = tmp2;
	}
	tmp->next = tmp3;
	*path = tmp;
}
