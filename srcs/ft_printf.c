/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:10:10 by khelegbe          #+#    #+#             */
/*   Updated: 2021/02/07 23:19:29 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_printf(const char *str, ...)
{
	va_list		arg;
	int			len;

	va_start(arg, str);
	len = ft_parse((char*)str, arg, NULL);
	va_end(arg);
	return (len);
}
