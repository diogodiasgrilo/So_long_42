/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:41:39 by diogpere          #+#    #+#             */
/*   Updated: 2023/05/05 19:49:47 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_split(char **strs)
{
	int	i;

	i = -1;
	while (strs && strs[++i])
		free(strs[i]);
	if (strs)
		free(strs);
}

int	find_s(char **map, int which)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'P')
			{
				if (!which)
					return (y);
				else
					return (x);
			}
		}
	}
	return (1);
}

t_err	ft_newmap_error(void)
{
	t_err	map_err;

	map_err.inv_borders = 0;
	map_err.inv_char = 0;
	map_err.inv_n_exits = 0;
	map_err.inv_n_collect = 0;
	map_err.inv_rowlen = 0;
	map_err.inv_n_players = 0;
	map_err.inv_path = 0;
	return (map_err);
}

char	**check_map(int fd, t_lay *lay)
{
	int		c;
	char	*map_str;
	char	**map;
	t_err	map_err;

	c = 0;
	map = 0;
	map_str = 0;
	map_err = ft_newmap_error();
	*lay = ft_newlayout();
	ft_readlayout(fd, &map_err, lay, &map_str);
	ft_print_map_error(&map_err, &map_str);
	lay->map_cpy = ft_strdup(map_str);
	lay->map_cpy_split = ft_split(lay->map_cpy, '\n');
	find_path(lay->map_cpy_split, find_s(lay->map_cpy_split, 1), \
		find_s(lay->map_cpy_split, 0), &c);
	map_err.inv_path = (c != lay->n_collect + 1);
	free(lay->map_cpy);
	free_split(lay->map_cpy_split);
	ft_print_map_error(&map_err, &map_str);
	map = ft_split(map_str, '\n');
	free(map_str);
	if (!map)
		error_msg_params("Memory allocation error!", 0);
	return (map);
}

char	**check_params(int argc, char **argv, t_lay *lay)
{
	int	i;
	int	fd;

	i = 0;
	if (argc != 2)
		error_msg_params("Invalid number of arguments!", 0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_msg_params("File not found!", 0);
	while (argv[1][i] && argv[1][i] == '.')
		i++;
	while (argv[1][i] && argv[1][i] != '.')
		i++;
	if (ft_strncmp(argv[1] + i, ".ber", 4) || ft_strncmp(argv[1] + i, ".ber",
			ft_strlen(argv[1] + i)))
		error_msg_params("Invalid file type, use .ber!", 0);
	return (check_map(fd, lay));
}
