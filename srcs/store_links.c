#include "../includes/lem_in.h"

void		store_links(char **tmp, t_able *hashtable)
{
	int		index_a;
	int		index_b;
	t_node	*t;
	t_node	*t2;

	index_a = hash(hashtable->size, tmp[0]);
	index_b = hash(hashtable->size, tmp[1]);
	t = hashtable->array[index_a];
	while (ft_strcmp(t->name, tmp[0]) != 0)
		t = t->next;
	if (!(t->link->name))
	{
		t->link = (t_link*)malloc(sizeof(t_link));
		t->link->name = ft_strdup(tmp[1]);
		t->link->next = NULL;
	}
	else
	{
		t2 = t->link->name;
		t->link->name = tmp[0];
		t->link->next = t2;
	}
}