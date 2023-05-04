/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:42:45 by diogpere          #+#    #+#             */
/*   Updated: 2023/05/04 23:21:59 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_sprite	ft_initsprites(t_game *g)
{
	int	size;

	size = SIZE;
	g->sprites.wall = mlx_xpm_file_to_image(g->id, \
		"./sprites/wall.xpm", &size, &size);
	g->sprites.robin = mlx_xpm_file_to_image(g->id, \
		"./sprites/robin.xpm", &size, &size);
	g->sprites.king = mlx_xpm_file_to_image(g->id, \
		"./sprites/king_d.xpm", &size, &size);
	g->sprites.treasure = mlx_xpm_file_to_image(g->id, \
		"./sprites/treasure.xpm", &size, &size);
	g->sprites.grass = mlx_xpm_file_to_image(g->id, \
		"./sprites/grass.xpm", &size, &size);
	g->sprites.fence = mlx_xpm_file_to_image(g->id, \
		"./sprites/fence.xpm", &size, &size);
	g->sprites.small_green = mlx_xpm_file_to_image(g->id, \
		"./sprites/small_green.xpm", &size, &size);
	return (g->sprites);
}

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	return (img);
}

void	set_background_image(t_game *g, char *image_path)
{
	t_image	bg_image;

	bg_image = ft_new_sprite(g->id, image_path);
	mlx_put_image_to_window(g->id, g->w_id, \
		bg_image.reference, 0, 0);
	mlx_destroy_image(g->id, bg_image.reference);
}
