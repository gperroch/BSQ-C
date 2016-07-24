/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 14:59:45 by acottier          #+#    #+#             */
/*   Updated: 2015/08/27 19:59:45 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcts.h"
#include "proto_around.h"

t_square	g_square_max;
t_square	g_square;

void		ft_compare_squares(void)
{
	if (g_square.side > g_square_max.side)
	{
		g_square_max.top_left_x = g_square.top_left_x;
		g_square_max.top_left_y = g_square.top_left_y;
		g_square_max.side = g_square.side;
	}
}

void		ft_compare_global(t_origin *s_db, int k)
{
	if (s_db->block == 1)
		g_square.side = k - 2;
	else
		g_square.side = k - 1;
	ft_compare_squares();
}

void		ft_create_square(int i, int j, t_origin *s_db)
{
	int		k;

	g_square.top_left_x = j;
	g_square.top_left_y = i;
	k = 1;
	s_db->block = 0;
	while ((j + k) <= s_db->length_line &&
			(i + k - 1) <= s_db->nb_line && s_db->block == 0)
	{
		while (i < (g_square.top_left_y + k) && s_db->block == 0)
		{
			while (j < (g_square.top_left_x + k) && s_db->block == 0)
			{
				if (s_db->map[i][j] == s_db->c_block || s_db->map[i][j] == '\0')
					s_db->block = 1;
				j++;
			}
			j = g_square.top_left_x;
			i++;
		}
		k++;
		i = g_square.top_left_y;
	}
	ft_compare_global(s_db, k);
}

void		ft_seeker(t_origin *s_db)
{
	int		cursor;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cursor = s_db->length_first_line;
	g_square_max.side = 0;
	while (cursor < (s_db->nb_line * s_db->length_line))
	{
		i = ((cursor - s_db->length_first_line) / s_db->length_line) + 1;
		j = (cursor - s_db->length_first_line) % s_db->length_line;
		if (s_db->map[i][j] != s_db->c_block)
			ft_create_square(i, j, s_db);
		cursor++;
	}
}
