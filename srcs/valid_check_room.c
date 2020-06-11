/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_check_room.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/29 17:58:21 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/11 11:40:33 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		valid_name(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] && ft_isascii(tmp[i]) == 1)
		i++;
	if (tmp[i] != '\0')
		exit(ft_printf("Error\n"));
}
