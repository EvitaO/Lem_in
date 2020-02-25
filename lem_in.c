/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 16:14:46 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/02/25 11:21:55 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	store_room(char **tmp, t_room *room)
{
	room->name = tmp[0];
	room->x = tmp[1];
	room->y = tmp[2];
}

int		check_rooms(char *line, t_room *room)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 1;
	tmp = ft_strsplit(line, ' ');
	if (!tmp[1])
		return (1);
	while (tmp[0][i] && ft_isascii(tmp[0][i]) == 1)
		i++;
	if (tmp[0][i] != '\0')
		exit(ft_printf("Error\n"));
	i = 0;
	while (tmp[j] != NULL)
	{
		while (tmp[j][i] && ft_isdigit(tmp[j][i]) == 1)
			i++;
		if (tmp[j][i])
			exit(ft_printf("Error\n"));
		i = 0;
		j++;
	}
	store_room(tmp, room);
	free(tmp);
	return (0);
}

int	check_ants(int	ants, char **line)
{
	int		i;

	i = 0;
	while (line[0][i] && ft_isdigit(line[0][i]) == 1)
		i++;
	if (line[0][i] == '\0')
		ants = ft_atoi(*line);
	return (ants);
}

int	main(void)
{
	int		ants;
	char	*line;
	t_room	room;
	int		i;

	ants = 0;
	line = NULL;
	i = 0;
	while (ants == 0)
	{
		get_next_line(0, &line);
		ants = check_ants(ants, &line);
		free(line);
		line = NULL;
	}
	ft_printf("%i\n", ants);
	while (i != 1 && get_next_line(0, &line) == 1)
		i = check_rooms(line, &room);
	ft_printf("%s\n", line);
	return (0);
}
