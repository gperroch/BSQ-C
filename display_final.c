/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_final.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperroch <gperroch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 21:04:35 by gperroch          #+#    #+#             */
/*   Updated: 2015/08/27 18:39:24 by gperroch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_around.h"
#include "fcts.h"

void	ft_display_final(t_origin *g_db)
{
	g_db->i = 1;
	g_db->j = 0;
	while (g_db->map[g_db->i] != NULL)
	{
		while ((g_db->map[g_db->i][g_db->j]) != '\0')
		{
			write(1, &(g_db->map[g_db->i][g_db->j]), 1);
			g_db->j++;
		}
		write(1, "\n", 1);
		g_db->j = 0;
		g_db->i++;
	}
}
