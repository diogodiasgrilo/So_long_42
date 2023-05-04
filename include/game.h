/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:03:46 by diogpere          #+#    #+#             */
/*   Updated: 2023/05/04 22:50:43 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "so_long.h"

# define SIZE 32

typedef struct s_sprite
{
	void		**wall;
	void		*robin;
	void		*king;
	void		*treasure;
	void		*grass;
	void		*fence;
	void		*small_green;
}				t_sprite;

/* Main attributes for the game */
typedef struct s_game
{
	int			width;
	int			height;
	void		*id;
	void		*w_id;
	t_lay		*lay;
	t_lay		lay_bak;
	t_sprite	sprites;
	int			next_dir;
	char		**map;
	int			n_collect;
	int			n_moves;
	int			robin_x;
	int			robin_y;
	int			p_i;
	int			p_j;
}				t_game;

int			free_map_exit(void *game);
t_sprite	ft_initsprites(t_game *g);
void		start_game(char **map, t_lay lay);
void		new_game_image(t_game g, char **map);

#endif