/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_check_room.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/29 17:58:21 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/04/25 11:28:10 by eutienne      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		valid_cordinates(char **tmp)
{
	int	i;
	int	j;

	j = 1;
	while (tmp[j] != NULL)
	{
		i = 0;
		while (tmp[j][i] && ft_isdigit(tmp[j][i]) == 1)
			i++;
		if (tmp[j][i])
			exit(ft_printf("Error\n"));
		j++;
	}
}

void		valid_name(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] && ft_isascii(tmp[i]) == 1)
		i++;
	if (tmp[i] != '\0')
		exit(ft_printf("Error\n"));
}

/*
static void	check_cordinates(char *x, char *y, t_room **room)
{
	while ((*room)->next)
	{
		if (ft_strcmp((*room)->x, x) == 0)
		{
			if (ft_strcmp((*room)->y, y) == 0)
				exit(ft_printf("Error\n");
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
*/

static void	check_exist(char **tmp, t_room **room)
{
	while ((*room)->next)
	{
		if (ft_strcmp((*room)->name, tmp[0]) == 0)
			exit(ft_printf("Error\n"));
		if (ft_strcmp((*room)->x, tmp[1]) == 0)
		{
			if (ft_strcmp((*room)->y, tmp[2]) == 0)
				exit(ft_printf("Error\n"));
		}
		*room = (*room)->next;
	}
	if (ft_strcmp((*room)->name, tmp[0]) == 0)
			exit(ft_printf("Error\n"));
	if (ft_strcmp((*room)->x, tmp[1]) == 0)
	{
		if (ft_strcmp((*room)->y, tmp[2]) == 0)
			exit(ft_printf("Error\n"));
	}
}

void		check_valid_room(char **tmp, t_room **room)
{
	go_to_first_room(room);
	check_exist(tmp, room);
}
