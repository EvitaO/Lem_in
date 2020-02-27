#include "../includes/lem_in.h"

void		check_room_exists(char *name, t_room **room)
{
	while ((*room)->next)
	{
		if (ft_strcmp(name, (*room)->name) == 0)
			return ;
		*room = (*room)->next;
	}
	if (ft_strcmp(name, (*room)->name) == 0)
		return ;
	else
		exit(ft_printf("Error\n"));
}

void		check_links(char *line, t_room **room)
{
	char	**tmp;
	int		i;

	tmp = ft_strsplit(line, '-');
	i = 0;
	while (tmp[i] && i < 2)
	{
		check_room_exists(tmp[i], room);
		i++;
		go_to_first_room(room);
	}
	if (tmp[i])
		exit(ft_printf("Error\n"));
	free(line);
	free(tmp);
}

void	read_links(char **line, t_room **room, char **str)
{
	check_links(*line, room);
	*line = NULL;
	while (get_next_line(0, line) == 1)
	{
		check_links(*line, room);
		*str = ft_strjoin(*str, *line);
		*line = NULL;
	}
}
