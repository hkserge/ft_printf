/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 23:15:34 by khelegbe          #+#    #+#             */
/*   Updated: 2021/02/18 18:29:38 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_exec_p(va_list arg)
{
	long int			out;
	char				*address;
	int					len;

	out = ((long int)va_arg(arg, long int));
	if (!out)
	{
		ft_putstr("(nil)");
		return ((int)ft_strlen("(nil)"));
	}
	address = ft_convert_hex(out, "0123456789abcdef");
	len = (int)ft_strlen(address) + 2;
	ft_putstr("0x");
	ft_putstr(address);
	if (address)
		free(address);
	return (len);
}
