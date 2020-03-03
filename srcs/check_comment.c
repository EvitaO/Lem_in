#include "../includes/lem_in.h"

int	check_comment(char **line)
{
	if (ft_strcmp(*line, "##start"))
		return (1);
	else if (ft_strcmp(*line, "##end"))
		return (2);
	return (0);
}
