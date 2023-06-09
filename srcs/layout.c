/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:28:07 by diogpere          #+#    #+#             */
/*   Updated: 2023/05/07 10:16:50 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_lay	ft_newlayout(void)
{
	t_lay	lay;

	lay.n_row = 0;
	lay.n_col = 0;
	lay.n_exit = 0;
	lay.n_pl = 0;
	lay.n_collect = 0;
	return (lay);
}

void	invalid_char(t_err *map_err, char **map_str, char *orig_line)
{
	free(*map_str);
	map_err->inv_char = 1;
	ft_print_map_error(map_err, &orig_line);
}

void	empty_map(char *line, char *last_line, char **map_str)
{
	if (line)
		free(line);
	if (last_line)
		free(last_line);
	if (*map_str)
		free(*map_str);
	error_msg_params("Map is empty!", NULL);
}

void	ft_readlayout(int fd, t_err *map_err, t_lay *lay, char **map_str)
{
	char		*line;
	char		*last_line;

	line = NULL;
	last_line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (!lay->n_col)
				empty_map(line, last_line, map_str);
			else
				ft_checklayout(last_line, map_err, lay, 1);
			free(last_line);
			break ;
		}
		free(last_line);
		if (ft_checklayout(line, map_err, lay, !lay->n_row))
			invalid_char(map_err, map_str, line);
		last_line = ft_substr(line, 0, ft_strlen(line));
		*map_str = ft_strenlarge(*map_str, line);
		lay->n_row++;
		free(line);
	}
}

int	ft_checklayout(char *line, t_err *map_err, t_lay *lay, int is_last)
{
	if (!lay->n_col)
		lay->n_col = ft_strlen(line) - 1;
	if (lay->n_col && ((lay->n_col != (int)ft_strlen(line) - 1 && \
			ft_strchr(line, '\n')) || (lay->n_col != (int)ft_strlen(line) && \
			!ft_strchr(line, '\n'))))
		map_err->inv_rowlen = 1;
	if (line[0] != '1' || line[lay->n_col - 1] != '1' || \
			(ft_countchar(line, '1') != lay->n_col && is_last))
		map_err->inv_borders = 1;
	lay->n_exit += ft_countchar(line, 'E');
	lay->n_pl += ft_countchar(line, 'P');
	lay->n_gh += ft_countchar(line, 'G');
	lay->n_collect += ft_countchar(line, 'C');
	map_err->inv_n_exits = (lay->n_exit < 1 || lay->n_exit > 1);
	map_err->inv_n_players = (lay->n_pl < 1 || lay->n_pl > 1);
	map_err->inv_n_collect = lay->n_collect < 1;
	while (line && *line)
		if (!ft_strchr("01CEPG\n", *(line++)))
			return (1);
	return (0);
}
