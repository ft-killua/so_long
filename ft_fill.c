/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:28:10 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/27 01:15:29 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_allocation_error(char **map)
{
	if (!map)
	{
		ft_printf("%sALLOCATION ERROR%s", RED, RESET);
		exit(1);
	}
}

void	ft_initializer(t_game *game, int fd)
{
	game->map.enemy_color = "textures/enemy/5.xpm";
	game->map.coin = "textures/coins/c8.xpm";
	game->map.wall = "textures/walls/w0.xpm";
	game->map.rows = ft_get_rows_nbr(fd);
}

void	ft_fill_check_map(char *map_file, t_game *game)
{
	int	fd;
	int	i;
	int	rows;

	i = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%sso_long: no such file or directory: %s%s",
			RED, map_file, RESET);
		exit(1);
	}
	rows = game->map.rows;
	close(fd);
	game->map.map_check = malloc(sizeof(char *) * (rows + 1));
	ft_allocation_error(game->map.map);
	game->map.map_check[rows] = 0;
	fd = open(map_file, O_RDONLY);
	while (i < rows)
		game->map.map_check[i++] = get_next_line(fd);
	close(fd);
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
		ft_printf("%sso_long: no such file or directory: %s%s",
			RED, map_file, RESET);
		exit(1);
	}
	ft_initializer(game, fd);
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
