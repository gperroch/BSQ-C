/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_evolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperroch <gperroch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 19:47:30 by gperroch          #+#    #+#             */
/*   Updated: 2015/08/27 18:22:55 by gperroch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_around.h"
#include "fcts.h"

extern	char		*g_current_file;
extern	t_square	g_square_max;

void	ft_map_evolution(t_origin *s_db)
{
	int i;
	int j;

	i = g_square_max.top_left_y;
	j = g_square_max.top_left_x;
	while (i < (g_square_max.top_left_y + g_square_max.side))
	{
		while (j < (g_square_max.top_left_x + g_square_max.side))
		{
			s_db->map[i][j] = s_db->c_fill;
			j++;
		}
		j = g_square_max.top_left_x;
		i++;
	}
}
