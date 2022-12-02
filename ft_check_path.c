/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:23:37 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/27 19:36:46 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_func1(t_game *game, int x, int y)
{
	char	**map;

	map = game->map.map_check;
	if (map[x + 1][y] == '0' || map[x + 1][y] == 'C')
		ft_func_helper(game, x + 1, y, 1);
	if (map[x - 1][y] == '0' || map[x - 1][y] == 'C')
		ft_func_helper(game, x - 1, y, 1);
	if (map[x][y + 1] == '0' || map[x][y + 1] == 'C')
		ft_func_helper(game, x, y + 1, 1);
	if (map[x][y - 1] == '0' || map[x][y - 1] == 'C')
		ft_func_helper(game, x, y - 1, 1);
	return ;
}

void	ft_func2(t_game *game, int x, int y)
{
	char	**map;

	map = game->map.map_check;
	if (map[x + 1][y] == '0' || map[x + 1][y] == 'S' || map[x + 1][y] == 'E')
		ft_func_helper(game, x + 1, y, 0);
	if (map[x - 1][y] == '0' || map[x - 1][y] == 'S' || map[x - 1][y] == 'E')
		ft_func_helper(game, x - 1, y, 0);
	if (map[x][y + 1] == '0' || map[x][y + 1] == 'S' || map[x][y + 1] == 'E')
		ft_func_helper(game, x, y + 1, 0);
	if (map[x][y - 1] == '0' || map[x][y - 1] == 'S' || map[x][y - 1] == 'E')
		ft_func_helper(game, x, y - 1, 0);
	return ;
}

void	ft_func_helper(t_game *game, int x, int y, int flag)
{
	if (flag)
	{
		game->map.map_check[x][y] = 'S';
		ft_func1(game, x, y);
	}
	else
	{
		game->map.map_check[x][y] = 'T';
		ft_func2(game, x, y);
	}
}

int	ft_check_path(t_game *game)
{
	int	x;
	int	y;

	x = game->map.player.x;
	y = game->map.player.y;
	ft_func1(game, x, y);
	ft_func2(game, x, y);
	return (ft_check_c(*game) && ft_check_e(*game));
}
