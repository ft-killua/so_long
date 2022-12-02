/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:00:33 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/27 00:52:18 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_coin_path(t_game *game)
{
	static int	frame = 0;

	frame++;
	if (frame == 16001)
		frame = 0;
	if (frame == 2000)
		game->map.coin = "textures/coins/c1.xpm";
	else if (frame == 4000)
		game->map.coin = "textures/coins/c2.xpm";
	else if (frame == 6000)
		game->map.coin = "textures/coins/c3.xpm";
	else if (frame == 8000)
		game->map.coin = "textures/coins/c4.xpm";
	else if (frame == 10000)
		game->map.coin = "textures/coins/c5.xpm";
	else if (frame == 12000)
		game->map.coin = "textures/coins/c6.xpm";
	else if (frame == 14000)
		game->map.coin = "textures/coins/c7.xpm";
	else if (frame == 16000)
		game->map.coin = "textures/coins/c8.xpm";
}

void	ft_wall_path(t_game *game)
{
	static int	frame = 0;

	frame++;
	if (frame == 20001)
		frame = 0;
	if (frame == 4000)
		game->map.wall = "textures/walls/w4.xpm";
	else if (frame == 8000)
		game->map.wall = "textures/walls/w1.xpm";
	else if (frame == 12000)
		game->map.wall = "textures/walls/w2.xpm";
	else if (frame == 16000)
		game->map.wall = "textures/walls/w3.xpm";
	else if (frame == 20000)
		game->map.wall = "textures/walls/w4.xpm";
}

void	ft_enemy_path(t_game *game)
{
	static int	frame = 0;

	frame++;
	if (frame == 20001)
		frame = 0;
	if (frame == 4000)
		game->map.enemy_color = "textures/enemy/1.xpm";
	else if (frame == 8000)
		game->map.enemy_color = "textures/enemy/2.xpm";
	else if (frame == 12000)
		game->map.enemy_color = "textures/enemy/3.xpm";
	else if (frame == 16000)
		game->map.enemy_color = "textures/enemy/4.xpm";
	else if (frame == 20000)
		game->map.enemy_color = "textures/enemy/5.xpm";
}

int	ft_move_animation(void	*param)
{
	t_game		*game;

	game = (t_game *)param;
	ft_enemy_path(game);
	ft_coin_path(game);
	ft_wall_path(game);
	ft_move_enemy(game);
	return (1);
}
