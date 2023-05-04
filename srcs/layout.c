/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:28:07 by diogpere          #+#    #+#             */
/*   Updated: 2023/05/04 21:55:22 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_checklayout(char *line, t_err *map_err, t_lay *lay, int is_last);

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
				error_msg_params("Map is empty!", NULL);
			else
				ft_checklayout(last_line, map_err, lay, 1);
			free(last_line);
			break ;
		}
		free(last_line);
		ft_checklayout(line, map_err, lay, !lay->n_row);
		last_line = ft_substr(line, 0, ft_strlen(line));
		*map_str = ft_strenlarge(*map_str, line);
		lay->n_row++;
	}
}

void	ft_checklayout(char *line, t_err *map_err, t_lay *lay, int is_last)
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
	{
		if (!ft_strchr("01CEPG\n", *line))
			map_err->inv_char = 1;
		line++;
	}
}
