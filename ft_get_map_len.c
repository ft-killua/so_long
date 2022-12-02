/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:38:40 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/27 00:56:24 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

static int	ft_nbrpow(int nbr)
{
	int	pow;

	pow = 1;
	while (nbr > 9 || nbr < -9)
	{
		nbr /= 10;
		pow++;
	}
	return (pow);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		neg;

	neg = n < 0;
	len = ft_nbrpow(n) + neg;
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len--] = '\0';
	while (len >= 0)
	{
		res[len] = ft_abs(n % 10) + '0';
		n /= 10;
		len--;
	}
	if (neg)
		res[0] = '-';
	return (res);
}

int	ft_get_rows_nbr(int fd)
{
	int		len;
	char	*line;

	len = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		len++;
	}
	free(line);
	return (len);
}

int	ft_get_cols_nbr(t_game game)
{
	int	len;

	len = 0;
	while (game.map.map[0][len])
		len++;
	return (len);
}
