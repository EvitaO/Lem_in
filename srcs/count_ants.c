#include "../includes/lem_in.h"

int	check_ants(int	ants, char **line)
{
	int		i;

	i = 0;
	while (line[0][i] && ft_isdigit(line[0][i]) == 1)
		i++;
	if (line[0][i] == '\0')
		ants = ft_atoi(*line);
	else if (line[0][0] == '#')
		return (ants);
	else
	{
		ft_printf("Error\n");
		exit(-1);
	}
	return (ants);
}

int	count_ants(char **line, char **str)
{
	int	ants;

	ants = 0;
	while (ants == 0)
	{
		get_next_line(0, line);
		ants = check_ants(ants, line);
		store_input_str(str, line);
		free(*line);
	}
	return (ants);
}
