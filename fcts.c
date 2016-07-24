/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 14:46:02 by acottier          #+#    #+#             */
/*   Updated: 2015/08/27 18:22:20 by gperroch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcts.h"
#include "proto_around.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_find_x(char *str, int y)
{
	int		x;
	int		i;

	i = 0;
	while (str[i] != '\n')
		i++;
	x = i;
	i = 0;
	while (str[i] != '\0')
	{
		i++;
		if ((str[i] == '\n') && (i != x % y))
			return (0);
	}
	return (x);
}

int		ft_obstacle(char c, char c_block, char c_free)
{
	if (c == c_block)
		return (1);
	else if (c == c_free)
		return (0);
	return (alarm_2);
}

int		ft_power(int nb, int power)
{
	int		res;

	res = 1;
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
	{
		if (power > 0)
			res = nb * ft_power(nb, power - 1);
		return (res);
	}
}
