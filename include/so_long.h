/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:43:37 by diogpere          #+#    #+#             */
/*   Updated: 2023/05/04 22:53:30 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "map.h"
# include "game.h"
# include "errors.h"
# include "colors.h"
# include "../miniLBX/mlx.h"
# include "../libft/libft.h"

int			ft_update(void *param);
int			ft_input(int key, void *param);
t_image		ft_new_sprite(void *mlx, char *path);
void		set_background_image(t_game *program, char *image_path);

#endif