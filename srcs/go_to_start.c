#include "../includes/lem_in.h"

void	go_to_first_room(t_room **room)
{
	while ((*room)->prev != NULL)
		(*room) = (*room)->prev;
}
