/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_check_room.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/29 17:58:21 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/02/29 18:27:24 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	check_cordinates(char *x, char *y, t_room **room)
{
	while ((*room)->next)
	{
		if (ft_strcmp((*room)->x, x) == 0)
		{
			if (ft_strcmp((*room)->y, y) == 0)
			{
				ft_printf("Error\n");
				exit(-1);
			}
		}
		*room = (*room)->next;
	}
	if (ft_strcmp((*room)->x, x) == 0)
	{
		if (ft_strcmp((*room)->y, y) == 0)
		{
			ft_printf("Error\n");
			exit(-1);
		}
	}

}

static void	check_room_name(char *name, t_room **room)
{
	while ((*room)->next)
	{
		if (ft_strcmp((*room)->name, name) == 0)
		{
			ft_printf("Error\n");
			exit(-1);
		}
		*room = (*room)->next;
	}
	ft_printf("AA\n");
	if (ft_strcmp((*room)->name, name) == 0)
	{
		ft_printf("Error\n");
		exit(-1);
	}
}

void		check_valid_room(char **tmp, t_room **room)
{
	go_to_first_room(room);
	check_room_name(tmp[0], room);
	go_to_first_room(room);
	check_cordinates(tmp[1], tmp[2], room);
}
