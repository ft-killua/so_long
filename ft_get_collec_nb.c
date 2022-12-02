/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_collec_nb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:11:28 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/27 00:59:15 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_enemy(t_game *game)
{
	int	i;
	int	j;
	int	nbr;

	i = 0;
	j = 0;
	nbr = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == ENEMY)
				nbr++;
			j++;
		}
		i++;
	}
	return (nbr);
}

void	ft_init_enemy(t_game	*game)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	n = 0;
	game->map.enemy_nbr = ft_count_enemy(game);
	game->map.enemy = malloc(sizeof(t_player) * game->map.enemy_nbr);
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == ENEMY)
			{
				game->map.enemy[n].x = i;
				game->map.enemy[n].y = j;
				n++;
			}
			j++;
		}
		i++;
	}
}

void	ft_get_info(t_game *game)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	nb = 0;
	game->moves = 0;
	game->map.collectibles = 0;
	ft_init_enemy(game);
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == COLLEC)
				game->map.collectibles++;
			else if (game->map.map[i][j] == PLAYER)
			{
				game->map.player.x = i;
				game->map.player.y = j;
			}
			j++;
		}
		i++;
	}
}
