/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 05:13:07 by khelegbe          #+#    #+#             */
/*   Updated: 2021/02/18 18:48:31 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_exec_x(va_list arg, int is_caps)
{
	char			*out;
	char			*temp;
	int				len;

	temp = ft_utoa(va_arg(arg, unsigned int));
	if (is_caps)
		out = ft_convert_base(temp, "0123456789", "0123456789ABCDEF");
	else
		out = ft_convert_base(temp, "0123456789", "0123456789abcdef");
	ft_putstr(out);
	len = (int)ft_strlen(out);
	if (temp)
		free(temp);
	if (out)
		free(out);
	return (len);
}
