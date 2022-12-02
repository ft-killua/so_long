/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:55:31 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/27 01:13:54 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c, int *len)
{
	write (1, &c, 1);
	(*len)++;
}

void	ft_putnbr(int n, int *len)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar('-', len);
		nb = -nb;
	}
	if (nb < 10)
		ft_putchar(nb + '0', len);
	else
	{
		ft_putnbr(nb / 10, len);
		ft_putnbr(nb % 10, len);
	}
}

void	ft_putstr(char *s, int *len)
{
	if (s == NULL)
		ft_putstr("(null)", len);
	while (s && *s)
	{
		ft_putchar(*s, len);
		s++;
	}
}

void	check_flag(va_list args, const char format, int *len)
{
	if (format == 'd')
		ft_putnbr(va_arg(args, int), len);
	else if (format == 's')
		ft_putstr(va_arg(args, char *), len);
}

int	ft_printf(const	char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			check_flag(args, *format, &len);
		}
		else
			ft_putchar(*format, &len);
		format++;
	}
	va_end(args);
	return (len);
}
