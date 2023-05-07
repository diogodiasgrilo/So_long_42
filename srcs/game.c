/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:09:21 by diogpere          #+#    #+#             */
/*   Updated: 2023/05/07 11:04:59 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// mlx_loop_hook(g.id, *ft_update, &g);

void	print_moves(t_game g)
{
	char	*num;
	char	*together;

	num = ft_itoa(g.n_moves);
	together = ft_strjoin("Current moves: ", num);
	mlx_string_put(g.id, g.w_id, 1 * SIZE / 2, 1 * SIZE / 2, \
		16777215, together);
	free(num);
	free(together);
}

void	new_game_image(t_game g, char **map)
{
	g.p_i = -1;
	while (map[++g.p_i])
	{
		g.p_j = -1;
		while (map[g.p_i][++g.p_j])
		{
			if (map[g.p_i][g.p_j] == 'C')
				mlx_put_image_to_window(g.id, g.w_id, g.sprites.treasure, g.p_j
					* SIZE, g.p_i * SIZE);
			else if (map[g.p_i][g.p_j] == '1' && map[g.p_i][g.p_j + 1] == '1'
					&& g.p_i != 0 && g.p_i < g.lay->n_row - 1)
				mlx_put_image_to_window(g.id, g.w_id, g.sprites.fence, g.p_j
					* SIZE, g.p_i * SIZE);
			else if (map[g.p_i][g.p_j] == '1')
				mlx_put_image_to_window(g.id, g.w_id, g.sprites.wall, g.p_j
					* SIZE, g.p_i * SIZE);
			else if (g.p_i == g.robin_y && g.p_j == g.robin_x)
				mlx_put_image_to_window(g.id, g.w_id, g.sprites.robin, g.p_j
					* SIZE, g.p_i * SIZE);
			else if (map[g.p_i][g.p_j] == 'E')
				mlx_put_image_to_window(g.id, g.w_id, g.sprites.king, g.p_j
					* SIZE, g.p_i * SIZE);
		}
	}
	print_moves(g);
}

void	start_game(char **map, t_lay lay)
{
	t_game	g;

	g.n_moves = 0;
	g.lay_bak = lay;
	g.n_collect = lay.n_collect;
	g.id = mlx_init();
	g.w_id = mlx_new_window(g.id, lay.n_col * SIZE, lay.n_row * SIZE,
			"The King's Task");
	set_background_image(&g, "./sprites/background.xpm");
	find_player(&g, map);
	ft_newgame(&g, map, &lay);
	new_game_image(g, map);
	mlx_key_hook(g.w_id, *ft_input, &g);
	mlx_hook(g.w_id, 17, 0, free_map_exit, &g);
	mlx_loop(g.id);
}

void	ft_newgame(t_game *g, char **m, t_lay *lay)
{
	g->n_moves = 0;
	g->width = lay->n_col * SIZE;
	g->height = lay->n_row * SIZE;
	g->lay = lay;
	g->map = m;
	g->sprites = ft_initsprites(g);
}

void	find_player(t_game *g, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				g->robin_x = j;
				g->robin_y = i;
			}
		}
	}
}
