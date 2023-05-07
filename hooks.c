/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:30:49 by diogpere          #+#    #+#             */
/*   Updated: 2023/05/05 14:13:30 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	free_map_exit(void *game)
{
	int		i;
	t_game	*g;

	i = -1;
	g = (t_game *)game;
	mlx_loop_end(g->id);
	while (g->map[++i])
		free(g->map[i]);
	free(g->map);
	mlx_destroy_image(g->id, g->sprites.wall);
	mlx_destroy_image(g->id, g->sprites.king);
	mlx_destroy_image(g->id, g->sprites.robin);
	mlx_destroy_image(g->id, g->sprites.treasure);
	mlx_destroy_image(g->id, g->sprites.grass);
	mlx_destroy_image(g->id, g->sprites.fence);
	mlx_destroy_image(g->id, g->sprites.small_green);
	mlx_destroy_window(g->id, g->w_id);
	mlx_destroy_display(g->id);
	free(g->id);
	exit(0);
}

int	manage_next_image(int key, t_game *g, int x, int y)
{
	if (key == 65307)
		free_map_exit(g);
	if (g->map[g->robin_y][g->robin_x] == 'E' && g->n_collect == 0)
		free_map_exit(g);
	else if (g->map[g->robin_y][g->robin_x] == 'C')
	{
		g->map[g->robin_y][g->robin_x] = '0';
		g->n_collect--;
	}
	if (x != g->robin_x || y != g->robin_y)
	{
		mlx_put_image_to_window(g->id, g->w_id, g->sprites.small_green, \
			x * SIZE, y * SIZE);
		mlx_put_image_to_window(g->id, g->w_id, g->sprites.robin, \
			g->robin_x * SIZE, g->robin_y * SIZE);
		g->n_moves++;
	}
	new_game_image(*g, g->map);
	return (0);
}

void	change_dir(t_game *g, int option)
{
	int		size;

	size = SIZE;
	if (option == 1)
	{
		mlx_destroy_image(g->id, g->sprites.robin);
		g->sprites.robin = mlx_xpm_file_to_image(g->id, \
			"./sprites/robin.xpm", &size, &size);
	}
	else if (option == 2)
	{
		mlx_destroy_image(g->id, g->sprites.robin);
		g->sprites.robin = mlx_xpm_file_to_image(g->id, \
			"./sprites/robin_left.xpm", &size, &size);
	}
}

int	ft_input(int key, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	g->x_comp = g->robin_x;
	g->y_comp = g->robin_y;
	if (key == 100 && g->map[g->robin_y][g->robin_x + 1] != '1')
	{
		change_dir(g, 1);
		g->robin_x += 1;
	}
	else if (key == 97 && g->map[g->robin_y][g->robin_x - 1] != '1')
	{
		change_dir(g, 2);
		g->robin_x -= 1;
	}
	else if (key == 115 && g->map[g->robin_y + 1][g->robin_x] != '1')
		g->robin_y += 1;
	else if (key == 119 && g->map[g->robin_y - 1][g->robin_x] != '1')
		g->robin_y -= 1;
	return (manage_next_image(key, g, g->x_comp, g->y_comp));
}
