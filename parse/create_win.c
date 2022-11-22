/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 01:21:13 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/22 17:34:49 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_free(t_game *game)
{
	int	i;

	i = -1;
	while (game->map.map[++i])
		free(game->map.map[i]);
	free(game->map.map);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

// int	ft_finish(t_game *game)
// {
// 	ft_free(game, "WINDOW CLOSED");
// 	return (0);
// }

void	ft_win_create(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->map.cols * L,
			(game->map.rows) * L, "so_long");
	mlx_hook(game->win, CLOSE, 0, ft_free, game);
}
