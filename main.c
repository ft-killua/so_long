/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:04:12 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/22 17:42:57 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		exit(1);
	ft_check_map(av[1], &game);
	game.mlx = mlx_init();
	ft_win_create(&game);
	ft_render(game);
	mlx_hook(game.win, 2, 0, ft_handler, &game);
	mlx_loop(game.mlx);
}
