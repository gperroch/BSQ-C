/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognition_special.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperroch <gperroch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 09:22:58 by gperroch          #+#    #+#             */
/*   Updated: 2015/08/27 18:29:41 by gperroch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_around.h"
#include "fcts.h"

int	ft_recognition_special(t_origin *s_db)
{
	int		numbers_count;
	int		nb_line;
	int		length_first_line;

	length_first_line = 0;
	numbers_count = ft_how_many_numbers_special(s_db);
	if (numbers_count == 0)
		return (alarm_1);
	nb_line = ft_how_many_lines_special(numbers_count, s_db);
	while (s_db->map[0][length_first_line] != '\0')
		length_first_line++;
	s_db->length_first_line = length_first_line + 1;
	s_db->nb_line = nb_line;
	s_db->c_free = s_db->map[0][numbers_count];
	s_db->c_block = s_db->map[0][numbers_count + 1];
	s_db->c_fill = s_db->map[0][numbers_count + 2];
	if (ft_check_characters_special(s_db) == alarm_1 ||
			ft_line_length_special(s_db) == alarm_1 ||
			ft_number_line_special(s_db) == alarm_1)
		return (alarm_1);
	else
		return (0);
}

int	ft_how_many_numbers_special(t_origin *s_db)
{
	int i;
	int k;

	i = 0;
	k = 0;
	if (s_db->map[0][0] > '9' && s_db->map[0][0] < '0')
		return (0);
	while (s_db->map[0][i] != '\0' && k < 2)
	{
		if (s_db->map[0][i] == ' ')
			k++;
		i++;
	}
	if (k == 2)
		return (i - 4);
	else
		return (i - 3);
}

int	ft_how_many_lines_special(int numbers_count, t_origin *s_db)
{
	int		j;
	int		s;
	int		total;

	j = 0;
	total = 0;
	while (j < numbers_count)
	{
		s = (s_db->map[0][j] - 48) * ft_power(10, (numbers_count - j - 1));
		total += s;
		j++;
	}
	return (total);
}

int	ft_check_characters_special(t_origin *s_db)
{
	int j;
	int i;

	i = 1;
	while (s_db->map[i] != NULL)
	{
		j = 0;
		while (s_db->map[i][j] != '\0')
		{
			if (s_db->map[i][j] != s_db->c_free &&
					s_db->map[i][j] != s_db->c_block)
				return (alarm_1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_line_length_special(t_origin *s_db)
{
	int	i;
	int j;

	i = 2;
	j = 0;
	while (s_db->map[1][j] != '\0')
		j++;
	s_db->length_line = j;
	while (s_db->map[i] != NULL)
	{
		j = 0;
		while (s_db->map[i][j] != '\0')
			j++;
		if (j != s_db->length_line)
			return (alarm_1);
		i++;
	}
	return (0);
}
