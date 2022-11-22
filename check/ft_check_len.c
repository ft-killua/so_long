/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:33:27 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/22 17:25:06 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_len(t_game *game)
{
	int	i;
	int	len;

	i = 1;
	game->map.cols = ft_strlen(game->map.map[0]);
	while (game->map.map[i])
	{
		len = ft_strlen(game->map.map[i]);
		if (game->map.cols != len)
			return (0);
		i++;
	}
	return (1 && game->map.cols > game->map.rows);
}
