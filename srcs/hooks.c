/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:30:49 by diogpere          #+#    #+#             */
/*   Updated: 2023/05/04 22:19:03 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	free_map_exit(void *game)
{
	int		i;
	t_game	*g;

	i = -1;
	g = (t_game *)game;
	while (g->map[++i])
		free(g->map[i]);
	free(g->map);
	exit(0);
}

void	manage_cleanup(t_game *g, int x, int y)
{
	if (g->map[g->robin_y][g->robin_x] == 'E' && g->n_collect == 0)
	{
		printf("You Win!\n");
		free_map_exit(g);
	}
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
		printf("Current N. of Moves -> %d\n", g->n_moves);
	}
	new_game_image(*g, g->map);
}

int	ft_input(int key, void *param)
{
	t_game	*g;
	int		x;
	int		y;

	g = (t_game *)param;
	x = g->robin_x;
	y = g->robin_y;
	if (key == 100 && g->map[g->robin_y][g->robin_x + 1] != '1')
		g->robin_x += 1;
	else if (key == 97 && g->map[g->robin_y][g->robin_x - 1] != '1')
		g->robin_x -= 1;
	else if (key == 115 && g->map[g->robin_y + 1][g->robin_x] != '1')
		g->robin_y += 1;
	else if (key == 119 && g->map[g->robin_y - 1][g->robin_x] != '1')
		g->robin_y -= 1;
	else if (key == 65307)
		free_map_exit(g);
	manage_cleanup(g, x, y);
	return (0);
}

int	ft_update(void *param)
{
	int			size;
	static int	frame;
	t_game		*g;

	frame++;
	g = (t_game *)param;
	size = SIZE;
	if (frame == ANIMATION_FRAMES)
	{
		g->sprites.robin = mlx_xpm_file_to_image(g->id, \
			"./sprites/robin_d.xpm", &size, &size);
	}
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		g->sprites.robin = mlx_xpm_file_to_image(g->id, \
			"./sprites/robin.xpm", &size, &size);
		frame = 0;
	}
	new_game_image(*g, g->map);
	return (0);
}
