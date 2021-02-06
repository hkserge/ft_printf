/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:36:25 by khelegbe          #+#    #+#             */
/*   Updated: 2021/02/06 20:43:27 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_exec_arg(char *str, va_list arg, int *i)
{
	int		size;

	size = 0;
	if (ft_strchr("cspdiuxX%", str[0]))
	{
		if (str[0] == 'c')
			size = ft_exec_c(arg);
		if (str[0] == 'd' || str[0] == 'i' || str[0] == 'u')
			size = ft_exec_d_i_u(arg, str[0] == 'u');
		if (str[0] == 's')
			size = ft_exec_s(arg);
		if (str[0] == 'p')
			size = ft_exec_p(arg);
		if (str[0] == 'x' || str[0] == 'X')
			size = ft_exec_x(arg, str[0] == 'X');
		if (str[0] == '%')
		{
			ft_putchar('%');
			size += 1;
		}
		*i += 1;
		return (size);
	}
	return (1);
}
