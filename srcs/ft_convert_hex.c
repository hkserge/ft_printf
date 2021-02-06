/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 03:03:56 by khelegbe          #+#    #+#             */
/*   Updated: 2021/02/05 17:15:19 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_hex(long int var, char *base_to)
{
	char	*address;

	address = ft_convert_base(ft_itoa(var), "0123456789", base_to);
	return (address);
}
