/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 03:03:56 by khelegbe          #+#    #+#             */
/*   Updated: 2021/03/09 04:47:24 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_hex(long int var, char *base_to)
{
	// char	*address;
	char	*temp;

	temp = ft_itoa(var);
	// address = ft_convert_base(temp, "0123456789", base_to);
	free(temp);
	return (ft_convert_base(temp, "0123456789", base_to));
}
