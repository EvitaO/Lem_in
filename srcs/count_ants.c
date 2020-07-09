/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   count_ants.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 12:23:12 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/07/10 00:28:47 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	read_first_line(int *ants, char **str)
{
	int		i;
	char	line[2];
	char	*line2;

	i = read(0, line, 1);
	line2 = line;
	store_input_str_first_line(str, &line2);
	line2 = NULL;
	if (i <= 0)
		exit(write(2, "no file\n", 8));
	else if (ft_strcmp(line, "\n") == 0)
		exit(ft_error(12));
	i = get_next_line(0, &line2);
	if (i <= 0)
		exit(ft_error(12));
	store_input_str_first_line(str, &line2);
	*ants = check_ants(*ants, str);
	*str = ft_strjoin(*str, "\n");
	free(line2);
}

int			check_ants(int ants, char **line)
{
	int	i;

	i = 0;
	while (line[0][i] && ft_isdigit(line[0][i]) == 1)
		i++;
	if (line[0][i] == '\0')
		ants = ft_atoi2(*line);
	else if (line[0][0] == '#')
	{
		if (check_comment(*line) != 0)
			exit(ft_error(12));
		return (ants);
	}
	else
		exit(ft_error(1));
	return (ants);
}

int			count_ants(char **line, char **str)
{
	int	ants;
	int	i;

	ants = 0;
	read_first_line(&ants, str);
	while (ants == 0)
	{
		i = get_next_line(0, line);
		if (i == 0)
			exit(ft_error(12));
		ants = check_ants(ants, line);
		store_input_str(str, line);
		free(*line);
	}
	return (ants);
}
