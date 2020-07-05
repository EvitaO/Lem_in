/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/11 11:32:44 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/07/05 11:43:13 by eutienne      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static long long	loop_str(const char *str, int i)
{
	long long		res;

	res = 0;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (str[i] != '\0')
		exit(ft_error(12));
	return (res);
}

int					ft_atoi2(const char *str)
{
	long long	res;
	int			sign;
	int			i;

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
		if (str[i + 1] == '\0')
			exit(ft_error(12));
		i++;
	}
	else if (str[i] == '+')
		i++;
	res = loop_str(str, i);
	if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
		exit(ft_error(12));
	return (sign * res);
}
