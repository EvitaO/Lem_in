/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   go_to_start.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 12:22:53 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/03/03 12:22:55 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	go_to_first_room(t_room **room)
{
	while ((*room)->prev != NULL)
		*room = (*room)->prev;
}
