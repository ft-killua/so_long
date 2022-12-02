/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 01:12:29 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/12/02 16:31:48 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_render_player(t_game game)
{
	char	*path;

	if (game.map.player.direction == UP)
		path = "textures/player/left.xpm";
	if (game.map.player.direction == LEFT)
		path = "textures/player/back.xpm";
	if (game.map.player.direction == RIGHT)
		path = "textures/player/right.xpm";
	if (game.map.player.direction == DOWN)
		path = "textures/player/front.xpm";
	return (path);
}

char	*ft_get_path(char spirit, int exit, t_game game)
{
	char	*path;

	exit *= 1;
	path = NULL;
	if (spirit == WALL)
		path = game.map.wall;
	if (spirit == FLOOR)
		path = "textures/floor.xpm";
	else if (spirit == PLAYER)
		path = ft_render_player(game);
	else if (spirit == COLLEC)
		path = game.map.coin;
	else if (spirit == ENEMY)
		path = game.map.enemy_color;
	else if (spirit == EXIT)
	{
		if (!exit)
			path = "textures/exit/closed.xpm";
		else
			path = "textures/exit/open.xpm";
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
		mlx_put_image_to_window(game.mlx, game.win,
			game.img, y * L, x * L);
		mlx_destroy_image(game.mlx, game.img);
	}
}

void	ft_print_movement(t_game game)
{
	char	*nbr;
	char	*moves;
	int		center;
	int		bottum;

	nbr = ft_itoa(game.moves);
	moves = ft_strjoin("Moves number : ", nbr);
	center = ((game.map.cols) * L) / 2 - 2 * L;
	bottum = ((game.map.rows) * L);
	mlx_string_put(game.mlx, game.win, center, bottum, 16735835, moves);
	free(nbr);
	free(moves);
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
	ft_print_movement(game);
}
