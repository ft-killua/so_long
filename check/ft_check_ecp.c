/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ecp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:22:08 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/22 17:23:46 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_exit(t_game game)
{
	int	exist;
	int	i;
	int	j;

	i = 0;
	exist = 0;
	while (game.map.map[i])
	{
		j = 0;
		while (game.map.map[i][j])
		{
			if (game.map.map[i][j] == EXIT)
				exist++;
			j++;
		}
		i++;
	}
	return (exist == 1);
}

int	ft_check_player(t_game game)
{
	int	exist;
	int	i;
	int	j;

	i = 0;
	j = 0;
	exist = 0;
	while (game.map.map[i])
	{
		j = 0;
		while (game.map.map[i][j])
		{
			if (game.map.map[i][j] == PLAYER)
				exist++;
			j++;
		}
		i++;
	}
	return (exist == 1);
}

int	ft_check_collec(t_game game)
{
	int	exist;
	int	i;
	int	j;

	j = 0;
	i = 0;
	exist = 0;
	while (game.map.map[i])
	{
		j = 0;
		while (game.map.map[i][j])
		{
			if (game.map.map[i][j] == COLLEC)
				exist++;
			j++;
		}
		i++;
	}
	return (exist > 0);
}
