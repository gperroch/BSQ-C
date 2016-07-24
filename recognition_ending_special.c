/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognition_ending_special.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperroch <gperroch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 11:01:09 by gperroch          #+#    #+#             */
/*   Updated: 2015/08/27 18:24:03 by gperroch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_around.h"
#include "fcts.h"

int	ft_number_line_special(t_origin *s_db)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (s_db->map[i] != NULL)
	{
		j = 0;
		while (s_db->map[i][j] != '\0')
			j++;
		s_db->current_number_line++;
		i++;
	}
	if (s_db->current_number_line != (s_db->nb_line))
		return (alarm_1);
	return (0);
}
