#include "../includes/lem_in.h"

void	store_room(char **tmp, t_room **room)
{
	if (*room)
	{
		(*room)->next = (t_room*)malloc(sizeof(t_room));
		(*room)->next->prev = *room;
		*room = (*room)->next;
	}
	else
	{
		*room = (t_room*)malloc(sizeof(t_room));
		(*room)->prev = NULL;
	}
	(*room)->name = ft_strdup(tmp[0]);
	(*room)->x = ft_strdup(tmp[1]);
	(*room)->y = ft_strdup(tmp[2]);
	(*room)->next = NULL;
}

int		check_rooms(char *line, t_room **room)
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
	if (*room)
		check_valid_room(tmp, room);
	store_room(tmp, room);
	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	return (0);
}

void	read_rooms(char **line, t_room **room, char **str)
{
	int	ret;

	ret = 0;
	while (ret != 1 && get_next_line(0, line) == 1)
	{
		ret = check_rooms(*line, room);
		store_input_str(str, line);
		if (ret != 1)
			free(*line);
	}
	free(*line);
	go_to_first_room(room);
}
