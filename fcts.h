/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcts.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 14:03:13 by acottier          #+#    #+#             */
/*   Updated: 2015/08/27 15:42:13 by gperroch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FCTS_H
# define FCTS_H

typedef struct	s_square
{
	int			top_left_x;
	int			top_left_y;
	int			side;
}				t_square;

int				ft_strlen(char *str);
int				ft_find_x(char *str, int y);
int				ft_obstacle(char c, char c_block, char c_fill);
int				ft_power(int nb, int power);
void			ft_compare_squares(void);

#endif
