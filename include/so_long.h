/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:43:37 by diogpere          #+#    #+#             */
/*   Updated: 2023/05/05 19:17:41 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "layout.h"
# include "game.h"
# include "check.h"
# include "errors.h"
# include "colors.h"
# include "../mlx/mlx.h"
# include "../libft/libft.h"

void		print_moves(t_game g);
int			ft_update(void *param);
t_sprite	ft_initsprites(t_game *g);
int			ft_input(int key, void *param);
t_image		ft_new_sprite(void *mlx, char *path);
void		set_background_image(t_game *program, char *image_path);

#endif