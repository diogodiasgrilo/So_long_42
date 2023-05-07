/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:41:56 by diogpere          #+#    #+#             */
/*   Updated: 2023/05/05 18:43:44 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	error_msg_params(char *msg, char **map_str)
{
	if (map_str && *map_str)
		free(*map_str);
	ft_printf("Error\n%s%s%s\n", RED, msg, DEFAULT);
	exit(0);
	return (0);
}

int	ft_print_map_error(t_err *map_err, char **map_str)
{
	if (map_err->inv_char)
		error_msg_params("Unexpected char(s) in map!", map_str);
	if (map_err->inv_rowlen)
		error_msg_params("Map must be rectangular!", map_str);
	if (map_err->inv_borders)
		error_msg_params("Map must be surrounded by walls!", map_str);
	if (map_err->inv_n_exits)
		error_msg_params("Invalid number of exits!", map_str);
	if (map_err->inv_n_players)
		error_msg_params("Invalid number of players!", map_str);
	if (map_err->inv_n_collect)
		error_msg_params("There should be at least one collectible!", map_str);
	if (map_err->inv_path)
		error_msg_params("There isn't a valid path to the exit!", map_str);
	return (0);
}
