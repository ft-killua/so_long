/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:28:10 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/22 20:42:44 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_allocation_error(char **map)
{
	if (!map)
	{
		printf("%sALLOCATION ERROR%s", RED, RESET);
		exit(1);
	}
}

void	ft_fill_map(char *map_file, t_game *game)
{
	int	fd;
	int	i;
	int	rows;

	i = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		printf("%sso_long: no such file or directory: %s%s",
			RED, map_file, RESET);
		exit(1);
	}
	game->map.rows = ft_get_rows_nbr(fd);
	rows = game->map.rows;
	close(fd);
	game->map.map = malloc(sizeof(char *) * (rows + 1));
	ft_allocation_error(game->map.map);
	game->map.map[rows] = 0;
	fd = open(map_file, O_RDONLY);
	while (i < rows)
		game->map.map[i++] = get_next_line(fd);
	close(fd);
	game->map.cols = ft_get_cols_nbr(*game);
	game->map.player.direction = DOWN;
}
