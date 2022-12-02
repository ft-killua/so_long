/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:34:09 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/27 22:26:44 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_empty(char *file)
{
	int		fd;
	char	test;
	int		ret;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%sso_long: no such file or directory: %s%s",
			RED, file, RESET);
		exit(1);
	}
	ret = read(fd, &test, 1);
	close(fd);
	return (ret);
}

int	ft_check_last_nl(char *file, t_game *game)
{
	int		i;
	int		fd;
	char	line[800000];
	int		ret;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%sso_long: no such file or directory: %s%s",
			RED, file, RESET);
		exit(1);
	}
	ret = read(fd, line, game->map.cols * game->map.rows + game->map.rows);
	close(fd);
	return (line[ret - 1] == '\n');
}
