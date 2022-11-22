/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_collec_nb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:11:28 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/22 17:23:29 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_get_info(t_game *game)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	nb = 0;
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
