/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperroch <gperroch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 08:05:51 by gperroch          #+#    #+#             */
/*   Updated: 2015/08/27 19:58:46 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_around.h"
#include "fcts.h"

char	*ft_stradd(char *tmp, char c)
{
	int		i;
	char	*new_str;

	i = 0;
	while (tmp != NULL && tmp[i] != '\0')
		i++;
	new_str = (char*)malloc(sizeof(char) * (i + 2));
	i = 0;
	while (tmp && tmp[i] != '\0')
	{
		new_str[i] = tmp[i];
		i++;
	}
	free(tmp);
	new_str[i] = c;
	new_str[i + 1] = '\0';
	return (new_str);
}

char	**ft_tabadd(char **map, char *tmp)
{
	int		i;
	char	**new_map;

	i = 0;
	while (map && map[i] != NULL)
		i++;
	new_map = (char**)malloc(sizeof(char*) * (i + 2));
	i = 0;
	while (map && map[i] != NULL)
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[i] = tmp;
	new_map[i + 1] = NULL;
	if (map != NULL)
		free(map);
	return (new_map);
}

int		ft_copy_map_special(t_origin *s_db, int fd)
{
	char	c;
	char	*tmp;

	tmp = NULL;
	s_db->map = NULL;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			s_db->nb_line++;
			s_db->map = ft_tabadd(s_db->map, tmp);
			tmp = NULL;
		}
		else if (c != '\n')
		{
			tmp = ft_stradd(tmp, c);
		}
	}
	return (0);
}
