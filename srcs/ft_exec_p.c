/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 23:15:34 by khelegbe          #+#    #+#             */
/*   Updated: 2021/02/05 17:15:31 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_exec_p(va_list arg)
{
	long int			out;
	char				*address;

	out = ((long int)va_arg(arg, long int));
	address = ft_convert_hex(out, "0123456789abcdef");
	ft_putstr("0x");
	ft_putstr(address);
	return ((int)ft_strlen(address) + 2);
}
