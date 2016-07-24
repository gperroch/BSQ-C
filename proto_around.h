/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto_around.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperroch <gperroch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 08:40:03 by gperroch          #+#    #+#             */
/*   Updated: 2015/08/27 20:02:54 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_AROUND_H
# define PROTO_AROUND_H
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef	struct	s_origin
{
	int			nb_line;
	int			length_first_line;
	int			length_line;
	int			cur_line_length;
	int			current_number_line;
	int			i;
	int			j;
	int			k;
	int			x;
	int			y;
	int			block;
	char		c_free;
	char		c_block;
	char		c_fill;
	char		**map;
}				t_origin;

typedef	enum	e_list
{
	alarm_1 = 404,
	alarm_2,
}				t_e_alarm;

int				ft_total(int fd);
int				ft_recognition(int fd);
int				ft_how_many_numbers(int fd);
int				ft_how_many_lines(int fd, int numbers_count);
int				ft_check_characters(int fd);
int				ft_line_length(int fd);
int				ft_number_line(int fd);
int				ft_copy_map(int fd);
int				affichage_map_test(void);
void			ft_map_evolution(t_origin *s_db);
void			ft_display_final(t_origin *g_db);
int				ft_special(t_origin *g_db, int fd);
int				ft_copy_map_special(t_origin *g_db, int fd);
int				ft_recognition_special(t_origin *s_db);
int				ft_how_many_numbers_special(t_origin *s_db);
int				ft_how_many_lines_special(int numbers_count, t_origin *s_db);
int				ft_check_characters_special(t_origin *s_db);
int				ft_line_length_special(t_origin *s_db);
int				ft_number_line_special(t_origin *g_db);
char			*ft_stradd(char *tmp, char c);
char			**ft_tabadd(char **map, char *tmp);
void			ft_create_square(int i, int j, t_origin *s_db);
void			ft_seeker(t_origin *s_db);
void			ft_compare_global(t_origin *s_db, int k);

#endif
