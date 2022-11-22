/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:50:09 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/22 17:23:41 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_map(char *file, t_game *game)
{
	ft_check_if_dir(file);
	if (!ft_check_extention(file))
		ft_error(NULL, "bad extention !");
	ft_fill_map(file, game);
	if (!ft_check_len(game))
		ft_error(game, "map must be rectangular!");
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
}
