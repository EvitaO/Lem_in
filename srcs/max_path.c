/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   max_path.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 12:02:07 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/03/06 12:15:09 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	max_path(t_able *ht)
{
	if (ht->cnt_s <= ht->cnt_e && ht->cnt_s <= ht->ants)
		ht->max_path = ht->cnt_s;
	else if (ht->cnt_e < ht->cnt_s && ht->cnt_e <= ht->ants)
		ht->max_path = ht->cnt_e;
	else
		ht->max_path = ht->ants;
}
