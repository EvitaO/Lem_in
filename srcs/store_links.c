/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_links.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 12:09:21 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/03/04 14:25:09 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	find_index(char *tmp, t_able *hashtable)
{
	if (ft_strcmp(tmp, hashtable->array[hashtable->size]->name) == 0)
		return (hashtable->size);
	else if (ft_strcmp(tmp, hashtable->array[hashtable->size + 1]->name) == 0)
		return (hashtable->size + 1);
	else
		return (hash(hashtable->size, tmp));
}

void		store_links(char **tmp, t_able *hashtable)
{
	int		index_a;
	int		index_b;
	t_node	*t;
	t_link	*t2;

	//index_a = hash(hashtable->size, tmp[0]);
	//index_b = hash(hashtable->size, tmp[1]);
	index_a = find_index(tmp[0], hashtable);
	index_b = find_index(tmp[1], hashtable);
	ft_printf("%i\n", index_a);
	t = hashtable->array[index_a];
	while (ft_strcmp(t->name, tmp[0]) != 0)
		t = t->next;
	if (!(t->link))
	{
		ft_printf("AAp\n");
		t->link = (t_link*)malloc(sizeof(t_link));
		t->link->name = ft_strdup(tmp[1]);
		t->link->next = NULL;
		ft_printf("%s\n", t->link->name);
	}
	else
	{
		t2 = t->link;
	//	ft_printf("%s\n", t2->name);
	//	while (t2 && t2->next)
	//	{
	//		ft_printf("AAl\n");
	//		t2 = t2->next;
	//	}
		ft_printf("AAl\n");
		t2->next = (t_link*)malloc(sizeof(t_link));
		t2 = t2->next;
		t2->name = ft_strdup(tmp[1]);
		t2->next = NULL;
	}
}
