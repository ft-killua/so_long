/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:59:37 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/27 19:36:40 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_c(t_game game)
{
	int	exist;
	int	i;
	int	j;

	j = 0;
	i = 0;
	exist = 0;
	while (game.map.map_check[i])
	{
		j = 0;
		while (game.map.map_check[i][j])
		{
			if (game.map.map_check[i][j] == COLLEC)
				exist++;
			j++;
		}
		i++;
	}
	return (exist == 0);
}

int	ft_check_e(t_game game)
{
	int	exist;
	int	i;
	int	j;

	j = 0;
	i = 0;
	exist = 0;
	while (game.map.map_check[i])
	{
		j = 0;
		while (game.map.map_check[i][j])
		{
			if (game.map.map_check[i][j] == EXIT)
				exist++;
			j++;
		}
		i++;
	}
	return (exist == 0);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s)
		s++;
	if (*s == (char)c)
		return ((char *) s);
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

void	ft_error(t_game *game, char *message)
{
	ft_printf("%sError\n%s%s", RED, message, RESET);
	if (game)
		ft_free(game, 0);
	exit(1);
}
