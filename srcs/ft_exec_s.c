/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 23:48:52 by khelegbe          #+#    #+#             */
/*   Updated: 2021/02/02 23:59:38 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_exec_s(va_list arg)
{
	char	*out;

	out = va_arg(arg, char*);
	ft_putstr(out);
	return ((int)ft_strlen(out));
}
