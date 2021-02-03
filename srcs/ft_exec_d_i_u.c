/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_d_i_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 22:43:34 by khelegbe          #+#    #+#             */
/*   Updated: 2021/02/02 23:39:27 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_exec_d_i_u(va_list arg, int is_unsigned)
{
	char	*out;

	if (is_unsigned)
		out = ft_utoa(va_arg(arg, unsigned int));
	else
		out = ft_itoa(va_arg(arg, int));
	ft_putstr(out);
	return ((int)ft_strlen(out));
}
