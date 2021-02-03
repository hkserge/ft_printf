/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:10:10 by khelegbe          #+#    #+#             */
/*   Updated: 2021/02/02 22:35:08 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_printf(const char *str, ...)
{
	va_list		arg;
	int			len;

	va_start(arg, str);
	len = ft_parse((char*)str, arg);
	va_end(arg);
	return (len);
}
