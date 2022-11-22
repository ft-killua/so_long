/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 01:12:29 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/22 17:23:14 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_render_player(char spirit, t_game game)
{
	char	*path;

	if (game.map.player.direction == UP)
		path = "spirites/left.xpm";
	if (game.map.player.direction == LEFT)
		path = "spirites/back.xpm";
	if (game.map.player.direction == RIGHT)
		path = "spirites/right.xpm";
	if (game.map.player.direction == DOWN)
		path = "spirites/player.xpm";
	return (path);
}

char	*ft_get_path(char spirit, int exit, t_game game)
{
	char	*path;

	exit *= 1;
	path = NULL;
	if (spirit == WALL)
		path = "spirites/wall.xpm";
	if (spirit == FLOOR)
		path = "spirites/floor.xpm";
	else if (spirit == PLAYER)
		path = ft_render_player(spirit, game);
	else if (spirit == COLLEC)
		path = "spirites/col.xpm";
	else if (spirit == ENEMY)
		path = "spirites/enemy.xpm";
	else if (spirit == EXIT)
	{
		if (!exit)
			path = "spirites/exit_closed.xpm";
		else
			path = "spirites/exit_open.xpm";
	}
	return (path);
}

void	ft_render_helper(t_game game, int x, int y)
{
	char	*path;

	if (!(game.map.collectibles))
		game.exit = 1;
	path = ft_get_path(game.map.map[x][y], game.exit, game);
	if (path)
	{
		game.img = mlx_xpm_file_to_image(game.mlx, path,
				&game.img_s, &game.img_s);
		mlx_put_image_to_window(game.mlx, game.win, game.img, y * L, x * L);
		mlx_destroy_image(game.mlx, game.img);
	}
}

void	ft_render(t_game game)
{
	int	x;
	int	y;

	x = 0;
	game.img_s = L;
	while (game.map.map[x])
	{
		y = 0;
		while (game.map.map[x][y] != '\n' && game.map.map[x][y])
		{
			ft_render_helper(game, x, y);
			y++;
		}
		x++;
	}
}
