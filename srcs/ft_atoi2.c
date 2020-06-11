/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/11 11:32:44 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/06/11 11:38:29 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	loop_str(const char *str, int i)
{
	int		res;

	res = 0;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (str[i] != '\0')
		exit(ft_printf("Error\n"));
	return (res);
}

int			ft_atoi2(const char *str)
{
	int		res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') || \
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
	{
		if (ft_strcmp(&str[i], "-2147483648") == 0)
			return (-2147483648);
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	res = loop_str(str, i);
	return (sign * res);
}
