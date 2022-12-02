/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:50:09 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/27 23:05:52 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map(char *file, t_game *game)
{
	ft_check_if_dir(file);
	if (!ft_check_extention(file))
		ft_error(NULL, "bad extention !");
	if (!ft_check_empty(file))
		ft_error(NULL, "empty file !");
	ft_fill_map(file, game);
	ft_fill_check_map(file, game);
	ft_check_len(game);
	if (!ft_check_characters(*game))
		ft_error(game, "bad character in map !");
	if (!ft_check_surounded(*game))
		ft_error(game, "map is not surounded by walls !");
	if (!ft_check_exit(*game))
		ft_error(game, "map must contain 1 exit !");
	if (!ft_check_collec(*game))
		ft_error(game, "map must contain 1 collectible at least !");
	if (!ft_check_player(*game))
		ft_error(game, "map must contain 1 starting position !");
	ft_get_info(game);
	if (!ft_check_path(game))
		ft_error(game, "map must contain 1 valid path at least !");
	if (ft_check_last_nl(file, game))
		ft_error(game, "map must be rectangular!");
}
