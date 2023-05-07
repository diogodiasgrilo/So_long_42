/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:12:01 by diogpere          #+#    #+#             */
/*   Updated: 2023/05/07 10:17:52 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAYOUT_H
# define LAYOUT_H

# include "errors.h"
# include "so_long.h"

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 2
# endif

typedef struct s_vector
{
	int			x;
	int			y;
}				t_vector;

typedef struct s_image
{
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_lay
{
	char		**map_cpy_split;
	char		*map_cpy;
	int			n_row;
	int			n_col;
	int			n_exit;
	int			n_pl;
	int			n_gh;
	int			n_collect;
}				t_lay;

t_lay			ft_newlayout(void);
void			ft_readlayout(int fd, t_err *map_err, t_lay *lay,
					char **map_str);
int				ft_checklayout(char *line, t_err *map_err, t_lay *lay, \
				int is_last);

#endif