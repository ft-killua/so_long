/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:28:32 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/27 00:58:22 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_if_dir(char *f_name)
{
	if (open(f_name, O_DIRECTORY) != -1)
		ft_error(NULL, "this is a directory !");
	close(open(f_name, O_DIRECTORY));
}

int	ft_check_extention(char *f_name)
{
	size_t	len;
	char	*ext;
	int		i;

	i = 0;
	len = ft_strlen(f_name);
	ext = ".ber";
	while (len-- > 4)
		i++;
	while (f_name[i])
	{
		if (f_name[i] != *ext)
			return (0);
		i++;
		ext++;
	}
	return (1);
}
