/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_surounded.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:32:24 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/22 17:23:36 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_surounded(t_game game)
{
	int	i;
	int	j;
	int	cols;
	int	rows;

	i = 0;
	cols = game.map.cols - 1;
	rows = game.map.rows - 1;
	while (i <= rows)
	{
		j = 0;
		while (j <= cols && game.map.map[i][j] != '\n' && game.map.map[i][j])
		{	
			if (i == 0 || i == rows || j == 0 || j == cols)
				if (game.map.map[i][j] != '1')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}
