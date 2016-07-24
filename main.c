/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperroch <gperroch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 13:49:00 by gperroch          #+#    #+#             */
/*   Updated: 2015/08/27 20:01:56 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_around.h"
#include "fcts.h"

char		*g_current_file;

int	main(int argc, char **argv)
{
	int			fd;
	int			count_file;
	t_origin	s_db;

	count_file = 1;
	fd = 0;
	if (argc != 1)
	{
		while (count_file < argc)
		{
			g_current_file = argv[count_file];
			fd = open(g_current_file, O_RDONLY);
			if (errno == ENOENT)
				write(1, "map error\n", 10);
			else
				ft_special(&s_db, fd);
			close(fd);
			count_file++;
		}
	}
	else
		ft_special(&s_db, fd);
	return (0);
}

int	ft_special(t_origin *s_db, int fd)
{
	int i;

	i = 0;
	s_db->nb_line = 0;
	s_db->length_line = 0;
	s_db->cur_line_length = 0;
	s_db->current_number_line = 0;
	ft_copy_map_special(s_db, fd);
	if (ft_recognition_special(s_db) == alarm_1)
	{
		write(2, "map error\n", 10);
		return (0);
	}
	ft_seeker(s_db);
	ft_map_evolution(s_db);
	ft_display_final(s_db);
	while (i < s_db->nb_line)
	{
		free(s_db->map[i]);
		i++;
	}
	free(s_db->map);
	return (0);
}
