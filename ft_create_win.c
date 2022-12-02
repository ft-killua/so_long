/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 01:21:13 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/27 23:10:54 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free(t_game *game, int flag)
{
	int	i;

	i = -1;
	while (game->map.map[++i])
		free(game->map.map[i]);
	free(game->map.map);
	i = -1;
	while (game->map.map_check[++i])
		free(game->map.map_check[i]);
	free(game->map.map_check);
	if (flag)
		mlx_destroy_window(game->mlx, game->win);
	exit(1);
}

void	ft_win_create(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->map.cols * L,
			(game->map.rows) * L + 32, "so_long");
	if (!game->win)
	{
		free(game->mlx);
		ft_error(game, "window creation error !");
	}
}
