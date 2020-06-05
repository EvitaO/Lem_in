/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_ants.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/20 17:28:34 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/05 12:58:08 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			print_ant(int print, int ant, char *name)
{
	if (print != 0)
		write(1, " ", 1);
	ft_printf("L%i-%s", ant, name);
	print++;
	return (print);
}
