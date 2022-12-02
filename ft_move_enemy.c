/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:01:59 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/27 00:44:40 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_swap(char *pos_a, char *pos_b)
{
	char	holder;

	holder = *pos_a;
	*pos_a = *pos_b;
	*pos_b = holder;
}

int	ft_condition(t_game *game, int i, int j)
{
	if (game->map.map[i][j] == FLOOR || game->map.map[i][j] == PLAYER)
		return (1);
	return (0);
}

void	ft_test(int i, int j, t_game *game)
{
	if (game->map.map[i][j] == PLAYER)
		ft_lose(game);
}

void	ft_enemy_helper(t_game *game, int index, int i, int j)
{
	if (ft_condition(game, i - 1, j) && (rand() % 4 == 0))
	{
		ft_test(i - 1, j, game);
		ft_swap(&game->map.map[i - 1][j], &game->map.map[i][j]);
		game->map.enemy[index].x--;
	}
	else if (ft_condition(game, i + 1, j) && (rand() % 4 == 1))
	{
		ft_test(i + 1, j, game);
		ft_swap(&game->map.map[i + 1][j], &game->map.map[i][j]);
		game->map.enemy[index].x++;
	}
	else if (ft_condition(game, i, j - 1) && (rand() % 4 == 2))
	{
		ft_test(i, j - 1, game);
		ft_swap(&game->map.map[i][j - 1], &game->map.map[i][j]);
			game->map.enemy[index].y--;
	}
	else if (ft_condition(game, i, j + 1) && (rand() % 4 == 3))
	{
		ft_test(i, j + 1, game);
		ft_swap(&game->map.map[i][j + 1], &game->map.map[i][j]);
		game->map.enemy[index].y++;
	}
}

void	ft_move_enemy(t_game *game)
{
	int			i;
	int			j;
	int			t;
	static int	frame = 0;

	i = -1;
	if (frame == 3500)
	{
		mlx_clear_window(game->mlx, game->win);
		while (++i < game->map.enemy_nbr)
			ft_enemy_helper(game, i, game->map.enemy[i].x,
				game->map.enemy[i].y);
		frame = 0;
		ft_render(*game);
	}
	frame++;
}
