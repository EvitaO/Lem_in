/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/11 10:36:58 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/11 10:38:52 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_info(t_info *tmp)
{
	t_info	*tmp2;

	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
}
