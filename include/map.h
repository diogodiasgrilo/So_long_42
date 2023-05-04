/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:12:01 by diogpere          #+#    #+#             */
/*   Updated: 2023/05/04 22:53:46 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "so_long.h"

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 2
# endif

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_lay
{
	int	n_row;
	int	n_col;
	int	n_exit;
	int	n_pl;
	int	n_gh;
	int	n_collect;
}				t_lay;

t_lay		ft_newlayout(void);
char		**check_map(int fd, t_lay *lay);
char		**check_params(int argc, char **argv, t_lay *lay);
void		ft_readlayout(int fd, t_err *map_err, t_lay *lay, char **map_str);

#endif