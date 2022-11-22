/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_characters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:22:44 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/22 17:17:33 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_exist(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_characters(t_game game)
{
	int		x;
	int		y;
	char	*set;

	x = 0;
	set = "X10CEP";
	while (game.map.map[x])
	{
		y = 0;
		while (game.map.map[x][y])
		{
			if (!ft_exist(game.map.map[x][y], set))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}
