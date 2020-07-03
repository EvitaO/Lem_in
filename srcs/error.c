/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/20 13:16:55 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/29 14:28:38 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	error_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(2, &s[i], 1);
		i++;
	}
	write(2, "\n", 1);
}

int			ft_error(int i)
{
	char	*str[13];

	str[0] = "incorrect format of ants";
	str[1] = "incorrect room name";
	str[2] = "room line has incorrect format";
	str[3] = "invalid room name";
	str[4] = "room name already exists";
	str[5] = "coördinates already exists";
	str[6] = "there are multiple start/end rooms given";
	str[7] = "there is no start/end room";
	str[8] = "link line has incorrect format";
	str[9] = "link name does not exists";
	str[10] = "start/end room has no links";
	str[11] = "wrong format";
	str[12] = "there is no path";
	error_putstr(str[i - 1]);
	return (0);
}
