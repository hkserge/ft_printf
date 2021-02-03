/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:36:25 by khelegbe          #+#    #+#             */
/*   Updated: 2021/02/02 23:56:58 by khelegbe         ###   ########.fr       */
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

		*i += 1;
		return (size);
	}
	ft_putchar('%');
	return (1);
}
